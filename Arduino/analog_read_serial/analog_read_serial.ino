/*
 * TME Education Ethiopia
 * www.tmeeducation.com
 * This code is proudly made by Robe getachew on June 18
 * Analog read and serial printing example
*/


void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

/// runs over and over again.
void loop() {
  // read the input on analog pin 1.
  int sensorValue = analogRead(A1);
  // print out the value you read.
  Serial.println(sensorValue);
  delay(1);        // delay in between reads.
}
