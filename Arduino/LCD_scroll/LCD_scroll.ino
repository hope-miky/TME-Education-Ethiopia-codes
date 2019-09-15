#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>


hd44780_I2Cexp lcd(0x20, I2Cexp_MCP23008, 7, 6, 5, 4, 3, 2, 1, HIGH);

void setup() {
  // put your setup code here, to run once:
    lcd.begin(16, 2);
    
}

void loop() {
  lcd.clear(); 
  lcd.setCursor(0, 0);
  lcd.print("TMEeducation");
  lcd.setCursor(0,1);
  lcd.print("rgferfewrf");
  delay(1000);
  
for (int positionCounter = 0; positionCounter < 17; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }  

  for (int positionCounter = 22; positionCounter > 0; positionCounter--) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
  
  /*
  // put your main code here, to run repeatedly:
  lcd.clear(); 
  lcd.setCursor(0, 0);
  lcd.print("TMEeduca");
for (int positionCounter = 0; positionCounter < 17; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(150);
  }  
  
  for (int positionCounter = 22; positionCounter > 0; positionCounter--) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(150);
  }
  
  delay(1000);
  */
}
