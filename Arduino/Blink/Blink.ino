/*
 * TME Education Ethiopia
 * www.tmeeducation.com
 * This code is proudly made by Robe getachew on Augest 23
 * Pulse readng example 
*/

int pin = 7;
unsigned long duration;

void setup() {
  Serial.begin(9600);
  pinMode(pin, INPUT);
}

void loop() {
  duration = pulseIn(pin, HIGH);
  Serial.println(duration);
}
