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
  

}
bool obstacle = false;
int lposx, lposy;
int wid = 20, hig = 10;
int del = 1;
void loop() {
  display.clearDisplay();
  display.drawLine(34,0,34,64, WHITE);
  display.drawLine(94,0,94,64, WHITE);
  lineDrawer();
  drawPlayer(playerPose());
  drawObstacle();
  display.setTextColor(WHITE);
  display.setTextSize(1.0);
  display.setCursor(0,20); 
  display.print("score");
  display.setCursor(5,30); 
  display.print(millis()/1000);
  display.display();
  delay(100);

  
  }


  void drawObstacle(){

   if (obstacle == false){
    obstacle = true;
    lposx = randomGen();
    lposy = 5;
    display.fillRect(lposx, lposy, wid, hig, WHITE);
   }

   else {
      if (lposy<64){
        display.fillRect(lposx, nextypose(), wid, hig, WHITE);
        display.display();
      }

        else{
          obstacle = false;
        }
   }

    
  }

 int nextypose(){
  int temp = millis()/1000;
  if ( temp >= 5)
      del = 2;
  if (temp >= 15)
      del = 4;
  if (temp >= 25)
      del = 6;
  if (temp >= 35)
      del = 8;
  if (temp >= 45)
      del = 10;
  lposy = lposy + del;
  return lposy;
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
    return random(34,80);
  }
  
