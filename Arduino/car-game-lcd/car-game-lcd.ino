 /*  Tesfamichael Molla Ali
 *  LCD Car Game
 *  v0.1.0
 *  -------------
 *  In this program you will learn how to build a small scale 
 *  car game using LCD display and Potentionmeter
 */ 

//Importing libraries we need for the project
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
#include <Adafruit_MCP23008.h>


// Custom characters used in the project both for the player and oponents
byte playerCar[] = {
  B00001,
  B11100,
  B11110,
  B10011,
  B10011,
  B11110,
  B11100,
  B00001
};

byte oponentCar1[] = {
  B10000,
  B01001,
  B00101,
  B10110,
  B10110,
  B00101,
  B01001,
  B10000
};

byte oponentCar2[] = {
  B10001,
  B00001,
  B01010,
  B10100,
  B10100,
  B01010,
  B00001,
  B10001
};

//Structure datatype for the player
struct playerModel{
  int playerid;
  int posx;
  int posy;
}player;


// Structure datatype for oponents
struct oponentModel{
  int oponentid;
  bool isactive;
  int posx;
  int posy;
}oponent1, oponent2;

hd44780_I2Cexp lcd(0x20, I2Cexp_MCP23008, 7, 6, 5, 4, 3, 2, 1, HIGH);

void setup() {
  
  lcd.begin(16 ,2);  //Initialize 16x2 lcd
  lcd.clear(); 

  // Creating the custom chars
  lcd.setCursor(0,0);
  lcd.createChar(1 , playerCar);                              
  lcd.createChar(2 , oponentCar1);
  lcd.createChar(3 , oponentCar2);

  // Initializing structure properties
  player.playerid = 1;
  player.posx = 0;
  player.posy = 0;

  oponent1.oponentid = 2;
  oponent1.posx = 0;
  oponent1.posy = 0;
  oponent1.isactive = true;

  oponent2.oponentid = 3;
  oponent2.posx = 0;
  oponent2.posy = 1;
  oponent2.isactive = true;

  //Displaying intro message
 intro();

}

void loop() {
  
  //Main loop
  player.posy = potValue();
  singleStep();
  setDisplay();
  checkCollision();
  delay(500);
  
  lcd.clear();

}


int potValue(){
  return analogRead(A1)/512;
  }

void singleStep(){
  
  if ((oponent1.isactive) && (oponent1.posx > 0)){
    oponent1.posx -= 1;
  }
  else{
    oponent1.posx = random(5, 15);;
  }

  if ((oponent2.isactive) && (oponent2.posx > 0)){
    oponent2.posx -= 1;
  }
  else{
    
    if(oponent1.posx < 10) oponent2.posx = oponent1.posx + random(4, 6);
    else oponent2.posx = oponent1.posx - random(4, 6);
    
  }

}

void setDisplay(){
  
    lcd.setCursor(player.posx , player.posy);
    lcd.write(player.playerid); 

    lcd.setCursor(oponent1.posx , oponent1.posy);
    lcd.write(oponent1.oponentid);

    lcd.setCursor(oponent2.posx , oponent2.posy);
    lcd.write(oponent2.oponentid);
    
}

void checkCollision(){

  //Check for collutions 
  
  if((player.posx == oponent1.posx) && (player.posy == oponent1.posy)){
      // Display Game over
      displayGameOver();
  }
  else if((player.posx == oponent2.posx) && (player.posy == oponent2.posy)){
      // Display Game over'
      displayGameOver();
  }else {
    
  }

  
}

void displayGameOver(){
  lcd.clear();
  lcd.setCursor(6,0);
  lcd.print("Game");

  lcd.setCursor(6,1);
  lcd.print("Over");

  delay(1000);
}

void intro(){
  String projectName = "Car Game LCD";
  String version = "1.0";
  
  lcd.clear(); 
  lcd.setCursor(0, 0);
  lcd.print("TMEeducation.com");
  
  lcd.setCursor(0, 1);
  for(int i = 0; i < (16 - projectName.length()) / 2; i++){
    lcd.print(" ");
  }
  lcd.print(projectName);
  
  delay(2500);
  
  lcd.setCursor(0, 1);
  lcd.print("                ");
  
  lcd.setCursor(0, 1);
  for(int i = 0; i < (16 - version.length()) / 2; i++){
    lcd.print(" ");
  }
  lcd.print(version);

  delay(2500);  
  lcd.clear();
  delay(100);
}
