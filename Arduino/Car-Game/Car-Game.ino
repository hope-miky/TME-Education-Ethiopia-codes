#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define RESET_BTN 4
#define INPUTPIN 8
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT, &Wire, RESET_BTN);

struct Obstacle {
  const uint8_t* bitmap;
  bool active;
  int posx;
  int posy;
}obstacle1,obstacle2,obstacle3;

// 15x25px
const unsigned char playerBitmap [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x07, 0xc0, 
  0x06, 0xc0, 0x04, 0x00, 0x05, 0x60, 0x07, 0xc0, 0x04, 0x40, 0x07, 0xc0, 0x07, 0xc0, 0x05, 0x40, 
  0x04, 0x40, 0x07, 0xc0, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00
};


// 15x25px
const unsigned char obstacleBitmap [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x0f, 0xe0, 0x0f, 0xe0, 
  0x0f, 0xe0, 0x0c, 0x60, 0x18, 0x30, 0x1f, 0xf0, 0x0f, 0xe0, 0x0f, 0xe0, 0x0f, 0xe0, 0x0f, 0xe0, 
  0x08, 0x20, 0x0c, 0x60, 0x0f, 0xe0, 0x07, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00
};




void setup() {
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(400); // Pause for 2 seconds
  Serial.begin(9600);
  pinMode(A1, INPUT);
  obstacle1.bitmap = obstacleBitmap;
  obstacle2.bitmap = obstacleBitmap;
  obstacle3.bitmap = obstacleBitmap;
  obstacle1.posy = 0;
  obstacle2.posy = 0;
  obstacle3.posy = 0;
  obstacle1.active == true;
  obstacle2.active == true;
  obstacle3.active == true;
}

void loop() {
  display.clearDisplay();
  display.drawLine(34,0,34,64, WHITE);
  display.drawLine(94,0,94,64, WHITE);
  lineDrawer();
  drawPlayer(playerPose());
  drawObstacle();
  display.display();
  delay(100);

  
  }


  void drawObstacle(){
   

    if (obstacle1.active == false){
        obstacle1.posy++;
        display.drawBitmap(40, obstacle1.posy,  obstacle1.bitmap, 15, 25, WHITE);
    }

    
  }

 

  

  int playerPose(){
    return map(analogRead(A1),0,1023,34,80);
  }

  void drawPlayer(int pose){
    display.drawBitmap(pose, 45,  playerBitmap, 15, 25, WHITE);
  }

  void lineDrawer(){
        if (millis()%3 == 0){
            //display.clearDisplay();
            drawLines1();
            display.display();
        }
    
        else if (millis()%3 == 1){
          //display.clearDisplay();
          drawLines2();
          display.display();
        }

        else {
          //display.clearDisplay();
          drawLines3();
          display.display();
        }
    
    }
  

  void drawLines1(){
   display.drawLine(64,0,64,10, WHITE);
   display.drawLine(64,15,64,25, WHITE);
   display.drawLine(64,30,64,40, WHITE);
   display.drawLine(64,45,64,55, WHITE);
   display.drawLine(64,60,64,64, WHITE);
   
  }

  void drawLines2(){
   display.drawLine(64,0,64,5, WHITE);
   display.drawLine(64,10,64,20, WHITE);
   display.drawLine(64,25,64,35, WHITE);
   display.drawLine(64,40,64,50, WHITE);
   display.drawLine(64,55,64,64, WHITE);
  }


  void drawLines3(){
   display.drawLine(64,0,64,8, WHITE);
   display.drawLine(64,13,64,23, WHITE);
   display.drawLine(64,28,64,38, WHITE);
   display.drawLine(64,43,64,53, WHITE);
   display.drawLine(64,58,64,64, WHITE);
  }

  int randomGen(){
    return random(200)%2;
  }
  
