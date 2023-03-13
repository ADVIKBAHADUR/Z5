#include <NewPing.h>

 int LEYE = 9; //11;//5
const int REYE = 3; //2;//3
const int V_RIGHT = 19; //5;//CONFIRMED 19
const int V_LEFT = 16; //12;//16
const int S_RIGHT1 = 7; //8;//CONFIRMED 7
const int S_RIGHT2 =8;  //10;//CONFIRMED 8
const int S_LEFT1 = 2; //6;//2
const int S_LEFT2 = 10; //7;//10


#define TRIGGER_PIN 6
#define ECHO_PIN 5

#define MAX_DISTANCE 150

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);



void setup() {

  Serial.begin(9600);

  pinMode(LEYE, INPUT );
  pinMode(REYE, INPUT ); 
  pinMode(V_RIGHT, OUTPUT);
  pinMode(V_LEFT, OUTPUT);
  pinMode(S_RIGHT1, OUTPUT);
  pinMode(S_RIGHT2, OUTPUT);
  pinMode(S_LEFT1, OUTPUT);
  pinMode(S_LEFT2, OUTPUT);
  digitalWrite(S_RIGHT1,0);
  digitalWrite(S_RIGHT2,1); 
  digitalWrite(S_LEFT1, 0);
  digitalWrite(S_LEFT2, 1);
  attachInterrupt(digitalPinToInterrupt(LEYE), right, LOW);
  attachInterrupt(digitalPinToInterrupt(REYE), left, LOW);
}

void right(){
    analogWrite(V_RIGHT, 255);
    analogWrite(V_LEFT, 80);
    Serial.println("r");

  
  }

void left(){
  analogWrite(V_LEFT, 255);
  analogWrite(V_RIGHT, 80);

  Serial.println("l");

}
void stop(){
  analogWrite(V_LEFT, 0);
  analogWrite(V_RIGHT, 0);
}
void straight(){
  analogWrite(V_LEFT, 150);
  analogWrite(V_RIGHT, 150);
}


void loop() {


  int iterations = 5;
  int dist = ((sonar.ping_median(iterations) / 2) * 0.0343);
  if(dist <= 30){  
    stop();
  } else {
    straight();
  }
	delay(500);

}
