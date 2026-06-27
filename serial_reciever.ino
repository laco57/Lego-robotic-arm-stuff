



#include<Servo.h>


const unsigned int MAX_MESSAGE_LENGTH = 16; 
//servos defined
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;

//defined pins
const int servo_podstava_pin = 7;
const int servo_naklanacka1_pin = 6;
const int servo_naklanacka2_pin = 5;

//servo angles
int servoAngle1;
int servoAngle2;
int servoAngle3;

void setup() {
  //start serial
  Serial.begin(9600); 

//attach servos to pins
  myServo1.attach(servo_podstava_pin);

  myServo2.attach(servo_naklanacka1_pin);

  myServo3.attach(servo_naklanacka2_pin);
}

void loop() {
  
  while (Serial.available() > 0) 
  {
    static char message[MAX_MESSAGE_LENGTH];
    static unsigned int message_pos = 0;

    char inByte = Serial.read();

    
    if (inByte != '\n' && message_pos < (MAX_MESSAGE_LENGTH - 1))
    {
      message[message_pos] = inByte;
      message_pos++;
    }
    else 
    {
      message[message_pos] = '\0'; 

      
      Serial.print("Prijate data: ");
      Serial.println(message);

  
      char* portion = strtok(message, ",");
      if (portion != NULL) {
        int base_val = atoi(portion); 

        portion = strtok(NULL, ",");
        if (portion != NULL) {
          int shoulder_val = atoi(portion); 

          portion = strtok(NULL, ",");
          if (portion != NULL) {
            int neck_val = atoi(portion); 

            //printing the vals on servos remember baseval shoulder val neck val are all integer vaues for the servo positions!!
            Serial.print("Base: "); Serial.print(base_val);
            myServo1.write(base_val);
            Serial.print(" | Shoulder: "); Serial.print(shoulder_val);
            myServo2.write(shoulder_val);
            Serial.print(" | Neck: "); Serial.println(neck_val);
            myServo3.write(neck_val);
            
            
          }
        }
      }

      
      message_pos = 0;
    }
  }
}
