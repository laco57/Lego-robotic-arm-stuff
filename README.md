
AI-ROBOTIC ARM
<img width="750" height="300" alt="ROBOTICARMPIC" src="https://github.com/user-attachments/assets/5ccf0180-1ed5-43ca-88a5-aafb32d2e6ca" />

So this is a robotic arm controlled by AI and it works by calling a api (in this case gemini) and you can chat with it and it will reply plus do some gestures. You
can make algorithms hence the ai has memory and also ask it to do stuff (planning  to add a camera soon!!!). 

REQUIREMENTS:
      -A microcontroler preferably arduin
      -Jumper wires and 3 servos (if you are making the arm big buy stronger servos if smaller/lighter buy according to need)
      -Something to make the arm from (cardboard, legos)
      -REALLY IMPORTANT a good power supply, its generally not recomended to power servos straight from a microcontrolers 5V pin so i highly recommend either using a batter or making a ATX power supply(i can make a repo about how to make that too if yall are interested)
      -And very important too it is required to be happy:)
      

So how do you set it up?

1.Get the robot_test_code from this repo and load it on your microcontroler of choice (im using a arduino if u are using something else like an esp you might have to tweak a few stuff)
and you should assemble the arm. I made a stl file for the arm but i cant really afford a 3D printer and if you cant either its very easy to assemble from lego, cardboard or anything, BE CREATIVE!!.
try makiing it according to the stl file if you wanna make sure it works but any other design is fine too.

2.Assemble the arm and now here comes the probably on a bit dangerous part, a servo if you didnt already know has 3 cables a yellow,red and brown one. you should plug the yellow one inside
of the microcontroler (the pin your using to control it for example in the test code the base is pin 7) the brown one goes to ground. You will want to take the ground from your power supply and hook
up all the grounds in one place + one from the arduino (just trust me). And the red wires are the 5v+ it depends on how big or small your servos are (connect them all together too).

3. So now that we got the fun part out time for the less fun one, first i recommend tring out the arm with the test code and two joysticks to make sure you made the arm correctly make sure it doesnt wobble over or anything like that. After making sure it works now its time for the hard stuff. I included two programs for the arm. A serial recieve and a serial send. Download the send on your pc and the recieve on the microcontroler(you might have to change a few stuff if you ae using a different microcontroler!!). Now that you got the code its time to download all the libraries needed.
run this command in your terminal/powershell

pip install google-genai python-dotenv pyserial
(keep in mind if you are on linux you have to set up a virtual enviroment just run "sudo apt install python3-venv".


4.Now you got all the libraries time to test, download all the code needed and hook up the arduino to the pc and make sure your connections to the arm are right an if you did everything right
the arm should move based on your answer. You cant really text with it yet but im working on that. If you got any questions/something doesnt work feel free to reach out.
