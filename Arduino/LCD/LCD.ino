


#include "includes.h"

hd44780_I2Cexp lcd(0x20, I2Cexp_MCP23008, 7, 6, 5, 4, 3, 2, 1, HIGH);

void setup(){
  lcd.begin(16, 2);
 
}
void loop()
{
lcd.setCursor(1,0);
  lcd.print("Hello");

 

  for (int scrollCounter = 0; scrollCounter < 28; scrollCounter++) 
  { 

    lcd.scrollDisplayRight(); 

    delay(250);
  }

  lcd.clear();

}
