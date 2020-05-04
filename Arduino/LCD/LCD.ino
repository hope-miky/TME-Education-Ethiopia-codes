/*
 * TME Education Ethiopia
 * www.tmeeducation.com
 * This code is proudly made by Robe Getachew on Sptember 12
 * LCD Example 
*/


#include <Wire.h>
#include <tmelcd.h>
#include <MCP/Adafruit_MCP23008.h>
#include <I2CExp/hd44780_I2Cexp.h>

hd44780_I2Cexp lcd(0x20, I2Cexp_MCP23008, 7, 6, 5, 4, 3, 2, 1, HIGH);

int score = 0;
bool pressed = false;
String ans = "";

void setup(){
  lcd.begin(16, 2);
 
}
void loop()
{

lcd.setCursor(0,0);
lcd.print("This is Question 1");
lcd.setCursor(0,1);
lcd.print("A  B   C   D");

while (!pressed){
  if(digitalRead(5) == HIGH){
    ans = "A";
    pressed = true;
    break;
  }
  else if(digitalRead(6) == HIGH){
    ans = "B";
    pressed = true;
    break;
  }
}


if (ans == "A"){
  score++;
}

 



}
