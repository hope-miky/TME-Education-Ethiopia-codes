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


class Snake{
int randx;
int randy;
public:
Snake(int randx, int randy){
 // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
randx = randx;
randy = randy;

}



void Up(){
  
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



  int drawP(int x1, int y1, int score=0, bool food=false){

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(100,50);
    display.setTextColor(WHITE);
    display.print(score);
    display.drawPixel(x1,y1, WHITE);
    if(food){
    randx = random(0,63);
    randy = random(0,127);
    }
    display.drawPixel(randx,randy, WHITE);
    display.display();
    return randx, randy;
  }



};


Snake led(10, 10);

int x =10, y=10;
int dx = 0, dy=0;
bool eaten = false;
int randx, randy;
 
void setup() {
  pinMode(5,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(6,INPUT);
  pinMode(13,OUTPUT);
 led.Up();

}

void loop() {
  
  
  if (digitalRead(5)== HIGH){
    delay(2);
    if (digitalRead(5)== HIGH){
    dx = 1;
    dy = 0;
  }
  }


   if (digitalRead(6)== HIGH){
    delay(2);
    if (digitalRead(6)== HIGH){
    dx = -1;
    dy = 0;
  }
  }

   else if (digitalRead(7)== HIGH){
    delay(2);
    if (digitalRead(7)== HIGH){
    dy = 1;
    dx = 0;
  }
   }
  

  else if (digitalRead(8)== HIGH){
    delay(2);
    if (digitalRead(8)== HIGH){
    dy = -1;
    dx = 0;
  }
  }
  
if ((x>0) && (x<64)&& (y>0) && (y<128)){
  if(dx == 1) x+=2;
  else if(dx == -1) x-=2;

  if(dy == 1) y+=2;
  else if(dy == -1) y-=2;

  randx, randy = led.drawP(y,x,eaten);
  
  
if((randx == y) && (randy == x)&&(eaten == false)){
  digitalWrite(13, HIGH);
  eaten = true;
}
else{
  digitalWrite(13, LOW);
  eaten = false;
  }
  
  delay(10);
}

else if ((dx==1)&&(x==64)){
  x=2;
  }

else if ((dx==-1)&&(x==0)){
  x=62;
  }



 else if ((dy==-1) && (y==0)){
  y=126;
  }

else if ((dy==1) && (y==128)){
  y=2;
  }
 


  }
