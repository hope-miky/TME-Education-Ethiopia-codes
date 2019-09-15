/*
 * TME Education Ethiopia
 * www.tmeeducation.com
 * This code is proudly created by team   from TME Eucation workshop at BlueLab from Aug 27 - 30
 * a quiz app using push buttn
*/

int btnA = 4;
int btnB = 5;
int btnC = 6;
char ans[5];
char answer[]={'A','B','C'};
bool getout1 = true;
bool getout2 = true;
bool getout3 = true;
int score = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(btnA,INPUT);
  pinMode(btnB,INPUT);
  pinMode(btnC,INPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
  Serial.println("Welcome to the Quize app");
  Serial.println("press D8 to start");
  while(!digitalRead(8)){}
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  Serial.println("1. QUESTION");
  Serial.println("a. CHOICE");
  Serial.println("b. CHOICE");
  Serial.println("c. CHOICE");
  while(getout1){
    if(digitalRead(btnA)){
      ans[0] = 'A';
      getout1 = false;
    }else if(digitalRead(btnB)){
      ans[0] = 'B';
      getout1 = false;
    }else if(digitalRead(btnC)){
      ans[0] = 'C';
      getout1 = false;
    }
  }
  Serial.println(ans[0]);
  delay(1000);
  Serial.println("2. QUESTION");
  Serial.println("a. CHOICE");
  Serial.println("b. CHOICE");
  Serial.println("c. CHOICE");
  while(getout2){
    if(digitalRead(btnA)){
      ans[1] = 'A';
      getout2 = false;
    }else if(digitalRead(btnB)){
      ans[1] = 'B';
      getout2 = false;
    }else if(digitalRead(btnC)){
      ans[1] = 'C';
      getout2 = false;
    }
  }
  Serial.println(ans[1]);
  delay(1000);
  Serial.println("3. QUESTION");
  Serial.println("a. CHOICE");
  Serial.println("b. CHOICE");
  Serial.println("c. CHOICE");
  while(getout3){
    if(digitalRead(btnA)){
      ans[2] = 'A';
      getout3 = false;
    }else if(digitalRead(btnB)){
      ans[2] = 'B';
      getout3 = false;
    }else if(digitalRead(btnC)){
      ans[2] = 'C';
      getout3 = false;
    }
  }
  Serial.println(ans[2]);
  delay(2000);

  for(int i = 0; i < 3; i++){
    if(ans[i] == answer[i]){
      score++;
    }
  }
  Serial.println();
  Serial.print("YOU SCORED  ");
  Serial.println(score);
  setup();
}
