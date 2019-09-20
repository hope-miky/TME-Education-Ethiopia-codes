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
