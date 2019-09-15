/*
 * TME Education Ethiopia
 * www.tmeeducation.com
 * This code is proudly made by Tesfamichael Mola on Sptember 14
 * LED Blinking using object oriented programming 
*/

//////////////////////////////////////// Start  /////////////////////////////////////
// Class assignment with a name LED
class LED{
  // declearing the variables pin nad sec
  int pin;    // for pin assignment 
  int sec;    // for delay 


  // the constructor which accept the pin number and the seconds delay from the object 
  public:
  LED(int ledpin, int sec1){
    pin = ledpin;
    sec = sec1;
    pinMode(pin, OUTPUT);           // Assigning the pin as OUTPUT pin
    }


  // main function for the led opperation which accepts a bool as a state 
  void ledOperation(bool state){
    if(state) digitalWrite(pin, HIGH);     // turn the led on if the state passed is true
    else digitalWrite(pin, LOW);           // turn if state is false 
  }

 // delay function which uses the sec variable
  void ledDelay(){
    delay(sec);     // delay 1 sec
  }
  
  };                // end of the class

LED newLedObject(13, 1000);             // creat an object for the LED class using pin13 and 1sec delay

void setup() {
  // No setup needed
}

void loop() {
newLedObject.ledOperation(true);     // turn the led on     
newLedObject.ledDelay();             // 1 sec delay 
newLedObject.ledOperation(false);    // turn the led off
newLedObject.ledDelay();             // 1 sec delay
}

//////////////////////////////// END ///////////////////////////////////////////////
