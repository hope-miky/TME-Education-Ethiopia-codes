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
    display.drawRect(x,y, wid, hght, WHITE);
  }



};


Cube cube(10,10);

 
void setup() {
 cube.Init();

}

void loop() {
  cube.drawR(10,10);

  }