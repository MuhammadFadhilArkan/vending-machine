#include <LiquidCrystal_I2C.h>
/* www.electronicsprojectshub.com */
/*Import following Libraries*/
//I2C pins declaration
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() 
{

lcd.begin();//Defining 16 columns and 2 rows of lcd display
lcd.backlight();//To Power ON the back light
//lcd.backlight();// To Power OFF the back light

}

void loop() 
{
//Write your code
lcd.setCursor(0,0); //Defining positon to write from first row,first column .
lcd.print("HELLOW"); //You can write 16 Characters per line .
lcd.setCursor(0,1);  //Defining positon to write from second row,first column .
lcd.print("FRIENDS!");
delay(8000); 

lcd.clear();//Clean the screen
lcd.setCursor(0,0); 
lcd.print("INSERT");
lcd.setCursor(0,1);
lcd.print("COIN!");
delay(8000); 
}
