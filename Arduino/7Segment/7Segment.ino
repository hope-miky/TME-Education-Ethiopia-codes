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
for (int i =0; i < 8; i++){
  int d = i%2;
  if (d==0)
        mcp.digitalWrite(i, true);
  }
}


void clear1(){
  mcp.digitalWrite(0, false);
  mcp.digitalWrite(1, false);
  mcp.digitalWrite(2, false);
  mcp.digitalWrite(3, false);
  mcp.digitalWrite(4, false);
  mcp.digitalWrite(5, false);
  mcp.digitalWrite(6, false);
  }

  void one(){
  mcp.digitalWrite(0, false);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, false);
  mcp.digitalWrite(4, false);
  mcp.digitalWrite(5, false);
  mcp.digitalWrite(6, false);

  }

void two(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, false);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, true);
  mcp.digitalWrite(5, false);
  mcp.digitalWrite(6, true);
  }
  
  
