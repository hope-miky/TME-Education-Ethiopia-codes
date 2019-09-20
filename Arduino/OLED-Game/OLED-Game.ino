/*
 * TME Education Ethiopia
 * www.tmeeducation.com
 * This code is proudly made by Tesfamichael Mola on Sptember 14
 * OLED Game on          *** on progress
*/


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 
// Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);


class Cube{

int wid;
int hght;


public:
Cube(int width, int height){

wid = width;
hght = height;

}



void Init(){
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  // Show initial display buffer contents on the screen --
  // the library initializes this with an Adafruit splash screen.
  display.display();
  delay(2000); // Pause for 2 seconds

  // Clear the buffer
  display.clearDisplay();
  
  }


  void drawR(int x,int y){
    display.clearDisplay();
    display.fillRect(x,y, wid, hght, WHITE);
    display.display();
  }

  void clearS(){
    display.clearDisplay();
  }

};

bool one = true, two = true, three = false, four = false;
int posx1 = 50, posy1 = 10;
int posx2 = 100, posy2 = 40;


int posx3 = 128, posy3 = 10;
int posx4 = 128, posy4 = 40;

int pix = 5, piy = 25;

Cube cube1(20,15);
Cube cube2(10,15);
Cube cube3(40,15);
Cube cube4(50,15);


void setup() {
 cube1.Init();
 cube2.Init();
 pinMode(6, INPUT);
 pinMode(8, INPUT);
}

void loop() {
  if(piy > 0){
  display.drawPixel(pix, piy, WHITE);
  display.display();
  }

   if(digitalRead(6) == HIGH) piy++;
   
    if(digitalRead(8) == HIGH) piy--;

  if(one){
  cube1.drawR(posx1, posy1);
  posx1--;
  }

  if(two){
  cube2.drawR(posx2, posy2);
  posx2--;
  }

  if(three){
  cube3.drawR(posx3, posy3);
  posx3--;
  }


  if(four){
  cube4.drawR(posx4, posy4);
  posx4--;
  }
  
  
  
  
  if(posx1 == 0){
    posx1 = 128;
    three = true;
    one = false;
  }

  if(posx2 == 0){
    posx2 = 128;
    four = true;
    two = false;
  }


  if(posx3 == 0){
    posx3 = 128;
    one = true;
    three = false;
  }

  if(posx4 == 0){
    posx4 = 128;
    two = true;
    four = false;
  }


  

 
  }
