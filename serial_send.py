

from google import genai
from google.genai import types
import os
from pathlib import Path
from dotenv import load_dotenv
import serial
import time


def main():
    # Setup prostredia
    env_path = Path(__file__).resolve().with_name('.env')
    load_dotenv(dotenv_path=env_path)

    api_key = os.getenv('GEMINI_API_KEY')
    if not api_key:
        raise ValueError("GEMINI_API_KEY not found in environment variables. Please set it in the .env file.")

    client = genai.Client(api_key=api_key)
    print("API KEY IS FINE")
            
    # Inicializácia chatu
    chat = client.chats.create(
        model='gemini-2.5-flash',
        config=types.GenerateContentConfig(
            system_instruction=(
                "You are a helpful assistant controlling a robotic arm. It has a base, a shoulder, and a neck. "
                "The base goes left and right, the shoulder forward and back, and the neck forward and back. "
                "Each servo has an initial value of 90. Only respond in a plain list of numbers separated by commas "
                "(e.g., 90,120,45) and make it so it's always in the order: base,shoulder,neck. "
                "you should move aroound as much as possible, but never go below 0 or above 180.    "
                "The values must be integers between 0 and 180. Do not use markdown, markdown code blocks, or spaces."
            ),
            thinking_config=types.ThinkingConfig(thinking_budget=0)
        ),
    )

    # Otvorenie sériového portu (IBA RAZ)
    try:
        serialcomm = serial.Serial('/dev/ttyACM0', 9600)
        serialcomm.timeout = 1
        print("Sériový port otvorený, čakám na reset hardvéru...")
        time.sleep(2)
    except Exception as e:
        print(f"Chyba pri otváraní portu: {e}")
        return

    # Hlavná slučka
    while True:
        user_input = input("Enter text (or 'Done' to exit): ")

        if user_input.strip() == "Done":
            print('finished')
            break

        print("gemini response: ", end="", flush=True)

        # OPRAVENÉ: Voláme priamo objekt `chat` a bez parametra `model`
        try:
            response_stream = chat.send_message_stream(message=user_input)
            
            full_response = ""
            for chunk in response_stream:
                print(chunk.text, end="", flush=True)
                full_response += chunk.text
        except Exception as e:
            print(f"\nChyba pri komunikácii s Gemini API: {e}")
            continue

        print("\n")  # Nový riadok po dokončení streamu

        clean_command = full_response.strip()

        if clean_command:
            send_data(serialcomm, clean_command)
        
        time.sleep(0.1)

    # Správne uzatvorenie portu po skončení cyklu
    serialcomm.close()
    print("Sériový port bol bezpečne zatvorený.")


def send_data(serial_port, text_to_send):
    try:
        data_newline = text_to_send + "\n"
        serial_port.write(data_newline.encode('utf-8'))
        print(f"Odoslané na Arduino: {text_to_send}")
    except Exception as e:
        print(f"Chyba pri odosielaní dát na Arduino: {e}")


if __name__ == "__main__":
    main()
