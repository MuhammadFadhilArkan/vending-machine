#include <Servo.h>
#include <LiquidCrystal_I2C.h>

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myservo1;  //servo1
Servo myservo2;  //servo2
Servo myservo3;  //servo3
Servo myservo4;  //servo4
int pos1 = 0;  //variable for number of degrees for servo1
int pos2 = 0;  //variable for number of degrees for servo2
int pos3 = 0;  //variable for number of degrees for servo3
int pos4 = 0;  //variable for number of degrees for servo4
// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
// Stores the red. green and blue colors
int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int nominal = 0; //jumlah uang 
int a;
int buttonValue;

void LCD(){
  lcd.setCursor(0,0); //Defining positon to write from first row,first column .
  lcd.print(" Saldo :"); //You can write 16 Characters per line .
  lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
  lcd.print(nominal);
}

void Sensor(){
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the RED (R) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  // redColor = map(redFrequency, 70, 120, 255,0);
  redColor = map(redFrequency, 61, 73, 255,0);
  
  // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redColor);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the GREEN (G) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  // greenColor = map(greenFrequency, 100, 199, 255, 0);
  greenColor = map(greenFrequency, 52, 63, 255, 0);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenColor);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  // Remaping the value of the BLUE (B) frequency from 0 to 255
  // You must replace with your own values. Here's an example: 
  // blueColor = map(blueFrequency, 38, 84, 255, 0);
  blueColor = map(blueFrequency, 68, 80, 255, 0);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.print(blueColor);
  delay(100);

  // Checks the current detected color and prints
  // a message in the serial monitor

  if(greenColor >200 && redColor>200 && blueColor >200){
    lcd.clear();
    nominal=nominal+500;
    delay(100);
  } 
  else if((redColor > greenColor && redColor > blueColor)&&redColor>0){
    lcd.clear();
    nominal=nominal+1000;
    delay(100);
  }
  else if((greenColor <100 || redColor<100) && blueColor <10){
    nominal=nominal;
  } 
  else if(blueColor > redColor && blueColor > greenColor){
    lcd.clear();    
    nominal=nominal+2000;
    delay(100); 
  } 
}

void setup() {
// Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  // Begins serial communication
  Serial.begin(9600);

  lcd.begin();//Defining 16 columns and 2 rows of lcd display
  lcd.backlight();//To Power ON the back light

  myservo1.attach(3); //activating pin 3 for servo 1
  myservo2.attach(9); //activating pin 9 for servo 2
  myservo3.attach(10); //activating pin 10 for servo 3
  myservo4.attach(11); //activating pin 11 for servo 4

}

void loop() {
  LCD();
  Sensor();
  
  buttonValue = analogRead(A0); //Read analog value from A0 pin
  
  //For 1st button:
  if (buttonValue>=997 && buttonValue<=1006){
    if(nominal>=3500){
    Serial.println("button 4 is pressed!");    
    myservo1.write(180); //setting servo1 to 0 degrees
    delay(1000);
    myservo1.write(0); //setting servo1 to 180 degrees
    delay(1000);
    lcd.clear();
    nominal=nominal-3500;
    }
  }
  //For 2nd button:
  else if (buttonValue>=923 && buttonValue<=935){
    if(nominal>=2500){
    Serial.println("button 2 is pressed!");    
    myservo2.write(180); //setting servo1 to 0 degrees
    delay(1000);
    myservo2.write(0); //setting servo1 to 180 degrees
    delay(1000);
    lcd.clear();
    nominal=nominal-2500;
    }
  }
  //For 3rd button:
  else if (buttonValue>=968  && buttonValue<=978){
    if(nominal>=1500){    
    Serial.println("button 3 is pressed!");    
    myservo3.write(180); //setting servo1 to 0 degrees
    delay(1000);
    myservo3.write(0); //setting servo1 to 180 degrees
    delay(1000);
    lcd.clear();
    nominal=nominal-1500;
    }
  }
  //For 4th button:
  else if (buttonValue>=987  && buttonValue<=993){
    Serial.println("button 4 is pressed!");
    a= int(nominal/500);   
    for(int j=1;j<=nominal/500;j=j+1){
      myservo4.write(180); //setting servo1 to 0 degrees
      delay(1000);
      myservo4.write(0); //setting servo1 to 180 degrees
      delay(1000);
      delay(250);
    }
    lcd.clear();
    nominal=0;
  }
}
