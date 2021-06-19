#include <Servo.h>
Servo myservo1;  //servo1Servo myservo1;  //servo1
Servo myservo2;  //servo1
Servo myservo3;  //servo1
Servo myservo4;  //servo1
int pos1 = 0;  //variable for number of degrees for servo1
int pos2 = 0;  //variable for number of degrees for servo1
int pos3 = 0;  //variable for number of degrees for servo1
int pos4 = 0;  //variable for number of degrees for servo1
int buttonValue; //Stores analog value when button is pressed
void setup()
{
  Serial.begin(9600);
  myservo1.attach(9); //activating pin 9 for servo 
  myservo3.attach(11); //activating pin 9 for servo 
  myservo4.attach(3); //activating pin 9 for servo 

}
void loop()
{
  buttonValue = analogRead(A0); //Read analog value from A0 pin
  Serial.println(buttonValue);

  }
