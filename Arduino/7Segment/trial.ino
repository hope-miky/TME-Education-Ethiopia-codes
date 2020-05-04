
#include "Adafruit_MCP23008.h"

Adafruit_MCP23008 mcp;
int val = 0;
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

  pinMode(5, INPUT);

}

void loop() {

if (digitalRead(5) == HIGH){
    val = val + 1;
    delay(50);
}

if (val == 0){
    zero();
}

else if(val == 1){
    clear1();
    delay(10)
    one();
}

else if (val == 2){
    two();
}

}


void zero(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, true);
  mcp.digitalWrite(5, true);
  mcp.digitalWrite(6, false);
}

void clear1(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, true);
  mcp.digitalWrite(5, true);
  mcp.digitalWrite(6, false);
}


void one(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, true);
  mcp.digitalWrite(5, true);
  mcp.digitalWrite(6, false);
}

void two(){
  mcp.digitalWrite(0, true);
  mcp.digitalWrite(1, true);
  mcp.digitalWrite(2, true);
  mcp.digitalWrite(3, true);
  mcp.digitalWrite(4, true);
  mcp.digitalWrite(5, true);
  mcp.digitalWrite(6, false);
}

