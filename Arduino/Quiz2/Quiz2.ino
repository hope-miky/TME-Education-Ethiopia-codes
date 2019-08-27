/*
 * TME Education Ethiopia
 * www.tmeeducation.com
 * This code is proudly made by team   on TME Education workshop at BlueLab on Aug 27 - 30
 * Quiz using Buttons as input and serial COM
*/


int bttnA = 4;
int bttnB = 5;
int bttnC= 6;
int bttnD = 7;
int red = 9;
int green = 10;
bool b1 = true;
bool b2 = true;
bool b3 = true;


void setup() {
  // put your setup code here, to run once:
pinMode(bttnA, INPUT);
pinMode(bttnB, INPUT);
pinMode(bttnC, INPUT);
pinMode(bttnD, INPUT);  
Serial.begin(9600); //baud rate
}
void pr( String Q, String A, String B, String C, String D)
{
  Serial.println(Q);
  Serial.println(A);
  Serial.println(B);
  Serial.println(C);
  Serial.println(D);
}

void loop() {
  // put your main code here, to run repeatedly:
// _________________________________________________________________________________
pr("Question 1", "A. Choise 1", "B. Choise 2", "C. Choise 3", "D. Choise 4");
while(b1)
{
  if(digitalRead(bttnA)== HIGH)
  {
    b1 = false;
    //delay(100);
    digitalWrite(green, HIGH);
    delay(400);
    Serial.println("Answer is A!");
    digitalWrite(green, LOW);
    
  }
  else if (digitalRead(bttnB)== HIGH ||digitalRead(bttnC)== HIGH ||digitalRead(bttnD)== HIGH)
  {
    digitalWrite(red, HIGH);
    delay(400);
    digitalWrite(red, LOW);
  }
}
// _________________________________________________________________________________
pr("Question 2", "A. Choise 1", " B. Choise 2", "C. Choise 3", "D. Choise 4");
while(b2)
{
  if(digitalRead(bttnC)== HIGH)
  {
    b2 = false;
    //delay(100);
    digitalWrite(green, HIGH);
    delay(400);
    Serial.println("Answer is C!");
    digitalWrite(green, LOW);
  }
    else if (digitalRead(bttnB)== HIGH ||digitalRead(bttnA)== HIGH ||digitalRead(bttnD)== HIGH)
  {
    digitalWrite(red, HIGH);
    delay(400);
    digitalWrite(red, LOW);
  }
}
// _________________________________________________________________________________
pr("Question 3", "A. Choise 1", " B. Choise 2", "C. Choise 3", "D. Choise 4");
while(b3)
{
  if(digitalRead(bttnD)== HIGH)
  {
    b3 = false;
    //delay(100);
    digitalWrite(green, HIGH);
    delay(400);
    Serial.println("Answer is D!");
    digitalWrite(green, LOW);
  }
    else if (digitalRead(bttnB)== HIGH ||digitalRead(bttnC)== HIGH ||digitalRead(bttnA)== HIGH) 
  {
    digitalWrite(red, HIGH);
    delay(400);
    digitalWrite(red, LOW);
  }
}
b1 = true;
b2 = true;
b3 = true;

}
