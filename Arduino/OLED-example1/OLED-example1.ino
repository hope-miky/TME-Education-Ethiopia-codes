/*
 * TME Education Ethiopia
 * www.tmeeducation.com
 * This code is proudly made by Tesfamichael Mola on Sptember 14
 * OLED Example 2     -    drawing bluemoon ethiopia logo
*/


#include <Wire.h>

#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 
// Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);



void setup() {
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
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

void loop() {
  
   
  //display.clearDisplay();
  display.fillCircle(90, 30, 30, WHITE);
  display.setTextColor(WHITE);
  display.setTextSize(2.5);
  display.setCursor(10,24); 
  display.print("Blue");
  
  display.setTextColor(BLACK);
  display.setTextSize(2.5);
  display.setCursor(63,24); 
  display.print("Moon");
  display.display();
  delay(1000);
}
