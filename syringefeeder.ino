/*************************************
 * Dual Channel DC Motor Driver Board* 
 *  Code Written by Idayu - MYBOTIC  *
 *************************************/
 
int IN1 = 3; 
int IN2 = 5; 
int IN3 = 6;
int IN4 = 9;
String feederstate="stanby";
int autofeedcycle=23;
String lastaction="none";

void setup()
{
 pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(115200);
}

void loop()
{
  /*
  if(lastaction=="none" && digitalRead(8)==LOW){
     feederstate="auto";
  }else{
    feederstate="stanby";
  }


  if(feederstate=="auto"){
    moveforward();
    delay(50);
    movestop();
    delay(2000);
    if(autofeedcycle==0){
      feederstate="stanby";
    }
    autofeedcycle=autofeedcycle-1;
    
  }else if(feederstate=="stanby"){
    
    autofeedcycle=4;
    lastaction="none";

    if (digitalRead(7) == HIGH) {
    } else {
       Serial.println("buton1 press");  
       movebackward();
       lastaction="backward";
    }
  
    if (digitalRead(8) == HIGH) {
    } else {
      Serial.println("buton2 press");  
      moveforward();
      lastaction="forward";
    }
    
  }*/
    if(digitalRead(7) == LOW && digitalRead(8) == LOW){
       while(digitalRead(7) == LOW && digitalRead(8) == LOW){
          feederstate="auto";
          delay(500);
       }
    }else if(digitalRead(7) == LOW){
       Serial.println("buton1 press");  
       while(digitalRead(7) == LOW){
          movebackward();
          delay(50);
          movestop();
          delay(100);
       }
    }else if(digitalRead(8) == LOW){
      Serial.println("buton2 press");  
      while(digitalRead(8) == LOW){
          moveforward();
          delay(50);
          movestop();
          delay(100);
      }
    }

    if(feederstate=="auto"){
       Serial.println("buton12 press");
       moveforward();
        delay(50);
        movestop();
        delay(2000);
        if(autofeedcycle==0 || digitalRead(7) == LOW || digitalRead(8) == LOW){
          feederstate="stanby";
        }
        autofeedcycle=autofeedcycle-1;
    }else{
      autofeedcycle=23;
    }

  delay(700);
}

void movebackward(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void moveforward(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW); 
}

void movestop(){
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);  
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW); 
}
