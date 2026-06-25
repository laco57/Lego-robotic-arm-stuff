#include <Servo.h>

//servos defined
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;


//first joystick
const int joyY1 = A1;
const int joyX1 = A0;

//second joystick
const int joyY2 = A2;
const int joyX2 = A3;

//servos
const int servo_podstava_pin = 7;
const int servo_naklanacka1_pin = 8;
const int servo_naklanacka2_pin = 9;
const int servo_zuby1 = 10;
const int servo_zuby2 = 11;


//empty valuables
int joyValue1;
int joyValue2;
int joyValue3;
int joyValue4;

int servoAngle1;
int servoAngle2;
int servoAngle3;
int servoAngle4;
void setup() {
  
  myServo1.attach(servo_podstava_pin);

  myServo2.attach(servo_naklanacka1_pin);

  myServo3.attach(servo_naklanacka2_pin);
  


} 

void loop() {
  //first jostick podstava plus prva naklanacka
  joyValue1 = analogRead(joyX1); 
  servoAngle1 = map(joyValue1, 0, 1023, 0, 180);
  myServo1.write(servoAngle1); 
  
  // Čítanie osi Y a ovládanie druhého serva
  joyValue2 = analogRead(joyY1);
  servoAngle2 = map(joyValue2, 0, 1023, 0, 180);
  myServo2.write(servoAngle2); 
  
  delay(15);




  //druhy joystick
  joyValue3 = analogRead(joyX2); 
  servoAngle3 = map(joyValue3, 0, 1023, 0, 180);
  myServo3.write(servoAngle3); 
  
  // Čítanie osi Y a ovládanie druhého serva
  joyValue4 = analogRead(joyY2);
  servoAngle4 = map(joyValue4, 0, 1023, 0, 180);
  myServo4.write(servoAngle4); 
  
  delay(15);

}

