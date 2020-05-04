#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define RESET_BTN 4
#define INPUTPIN 8
Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT, &Wire, RESET_BTN);

struct Car {
    String name;
    int xpos;
    int ypos;
    const uint8_t* bitmap;

}player1,player2,player3,player4,player5;

const unsigned char playerBitmap [] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x07, 0xc0, 
  0x06, 0xc0, 0x04, 0x00, 0x05, 0x60, 0x07, 0xc0, 0x04, 0x40, 0x07, 0xc0, 0x07, 0xc0, 0x05, 0x40, 
  0x04, 0x40, 0x07, 0xc0, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00
};

void setup(){
if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(10); // Pause f

    player1.bitmap = playerBitmap;
    player2.bitmap = playerBitmap;
    player3.bitmap = playerBitmap;
    player4.bitmap = playerBitmap;
    player5.bitmap = playerBitmap;

    pinMode(5, INPUT);

}


int count = 0;
void loop(){

    if (digitalRead(5) == HIGH){
        delay(10);
        if (digitalRead(5) == HIGH){
            count++;
        }
    }

    if (count == 0){
        display.clearDisplay();
    } else if(count == 1){
        player1.xpos = 10;
        player1.ypos = 10;
        dispaly.drawBitmap(player1.xpos, player1.ypos, player1.bitmap, 15, 25, WHITE);
    }

    else if(count == 2){
        player1.xpos = 10;
        player1.ypos = 10;
        dispaly.drawBitmap(player1.xpos, player1.ypos, player1.bitmap, 15, 25, WHITE);
        player2.xpos = 10;
        player2.ypos = 10;
        dispaly.drawBitmap(player2.xpos, player2.ypos, player2.bitmap, 15, 25, WHITE);
    }

trial(player1);

display.clearDisplay();
delay(100);
}



void trial(struct node*){



}