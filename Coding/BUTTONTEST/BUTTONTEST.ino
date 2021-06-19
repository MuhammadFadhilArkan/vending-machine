const int BUTTON = 2;     // Pushbutton Input to Pin No.2
const int LED =  3;       // Output LED to Pin No. 3


int BUTTONState = 0;      // To store input status

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);    // Define LED pin as output.   
  pinMode(BUTTON, INPUT);  // Define BUTTON pin as Input.   
}


void loop(){
  BUTTONState = digitalRead(BUTTON); // Reading input from Button Pin.

  if (BUTTONState == HIGH) // Checking if Input from button is HIGH (1/+5V)
   {     
     digitalWrite(LED, HIGH);  // If input is High make LED ON (HIGH/1/+5V)
     Serial.print(BUTTONState);

   } 
  else  
  {
     digitalWrite(LED, LOW);  // For every other condition make LED OFF (0/GND/LOW)
     Serial.print(BUTTONState);

  }
}
