#include "Adafruit_MCP23008.h"
Adafruit_MCP23008 mcp;

uint8_t seg7[11] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
  B01100001  // 1. (10)
};

void setup() {
  // put your setup code here, to run once:
  mcp.begin(0x4); // offset above 0x20 (lowest address)
  mcp.pinMode(0, OUTPUT);
  mcp.pinMode(1, OUTPUT);
  mcp.pinMode(2, OUTPUT);
  mcp.pinMode(3, OUTPUT);
  mcp.pinMode(4, OUTPUT);
  mcp.pinMode(5, OUTPUT);
  mcp.pinMode(6, OUTPUT);
  mcp.pinMode(7, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
 zero();
 delay(1000);
 clear1();
 delay(1000);
 one();
 delay(1000);
 clear1();
  delay(1000);
 two();
 delay(1000);
 clear1();
 delay(1000);
 three();
 delay(1000);
 clear1();
 delay(1000);
 four();
 delay(1000);
 clear1();
 delay(1000);
 five();
 delay(1000);
 clear1();
 delay(1000);
 six();
 delay(1000);
 clear1();
 delay(1000);
 seven();
 delay(1000);
 clear1();
 delay(1000);
 eight();
 delay(1000);
 clear1();
 delay(1000);
 nine();
 delay(1000);
 clear1();
 delay(1000);
}


void clear1(){
for (int i =0; i<8; i++){
   mcp.digitalWrite(i, false);
  }
  }

  ///////// zero /////////
void zero(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, true);
  mcp.digitalWrite(5, true);
  mcp.digitalWrite(6, false);
  }

  ////////    one    ///////
  
  void one(){
  mcp.digitalWrite(0, false);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, false);
  mcp.digitalWrite(4, false);
  mcp.digitalWrite(5, false);
  mcp.digitalWrite(6, false);
  }

////////////   two     ////////////
void two(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, false);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, true);
  mcp.digitalWrite(5, false);
  mcp.digitalWrite(6, true);
  }


//////////////    three   //////////////

void three(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, false);
  mcp.digitalWrite(5, false);
  mcp.digitalWrite(6, true);
  }


  ///////////// four    ////////////////
  void four(){
  mcp.digitalWrite(0, false);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, false);
  mcp.digitalWrite(4, false);
  mcp.digitalWrite(5, true);
  mcp.digitalWrite(6, true);
  }


  //////////////////    five    ////////

 void five(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, false);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, false);
  mcp.digitalWrite(5, true);
  mcp.digitalWrite(6, true);
  }


  /////////////////   six    /////////////////

  void six(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, false);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, true);
  mcp.digitalWrite(5, true);
  mcp.digitalWrite(6, true);
  }


  ////////////////   seven  ////////////////

  void seven(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, false);
  mcp.digitalWrite(4, false);
  mcp.digitalWrite(5, false);
  mcp.digitalWrite(6, false);
  }


  ///////////////   eight  //////// 

  void eight(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, true);
  mcp.digitalWrite(5, true);
  mcp.digitalWrite(6, true);
  }

////////////////   nine    /////////////

void nine(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, false);
  mcp.digitalWrite(5, true);
  mcp.digitalWrite(6, true);
  }
