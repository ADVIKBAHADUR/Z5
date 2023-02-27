#include <WiFiNINA.h>
#include <string>

//PORTS
const int LEYE = 9; 
const int REYE = 3; 
const int V_RIGHT = 19;
const int V_LEFT = 16; 
const int S_RIGHT1 = 7;
const int S_RIGHT2 =8; 
const int S_LEFT1 = 2; 
const int S_LEFT2 = 10;
const int US_TRIG = 6;
const int US_ECHO = 5;
const int STOPPINGDIST = 30;
unsigned long prev_event = 0;


//Slider variables
int L1 = 205;
int L2 = 100;
int R1 = 100;
int R2= 205;

//PRIORTY FACTOR
volatile int priority = 1;
bool running = false;
/*
Since we have multiple aspects trying to control the same functions of our code, and they sometimes send mixed signals to the the wheels causing it to choke, 
if we have a priority chart, when in cases where we have contradictory outputs, we just follow the one with a smalled proirity factor associated to it.
1 = PROCESSING GUI
2 = ULTRASONICS
3 = TURNING INTERRUPTS
4 = REGULAR DRIVE
*/

int count = 0; //ultrasonic counter

//WiFi Config
char ssid[] = "Advik's Galaxy"; 
char pass[] = "12345678"; 
WiFiServer server(5200); 

void setup() { 

  Serial.begin(9600); 
  WiFi.begin(ssid, pass); 
  IPAddress ip = WiFi.localIP(); 
  Serial.print("IP Address:"); 
  Serial.println(ip); 
  server.begin();

  //MODES
  pinMode(13, OUTPUT); //LED
  pinMode(LEYE, INPUT );
  pinMode(REYE, INPUT ); 
  pinMode(V_RIGHT, OUTPUT);
  pinMode(V_LEFT, OUTPUT);
  pinMode(S_RIGHT1, OUTPUT);
  pinMode(S_RIGHT2, OUTPUT);
  pinMode(S_LEFT1, OUTPUT);
  pinMode(S_LEFT2, OUTPUT);
  pinMode(US_ECHO, INPUT);
  pinMode(US_TRIG, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(LEYE), right, LOW);
  attachInterrupt(digitalPinToInterrupt(REYE), left, LOW);

  priority = 1;
}

void loop(){
  wifi();
  if (running == true){  
    ultrasonics();
    }

}

void wifi(){
  //Communicates all messages from the processing GUI terminal into the different variables
  WiFiClient client = server.available();
  String data = client.readString();
  if(data == "GO"){
    if(priority = 1){
      priority = 4;
      running = true;
    }
  }

  else if (data =="STOP"){
    priority = 1;
    drive("STOP");
    running = false;
  }
  else if (data[0] == 'L'){
    int n = data.length();
    if (data[1] == 1){
      L1 = (data.substring(3, n-1)).toInt();
    }
    else{
      L2 = (data.substring(3, n-1)).toInt();

    }
  }
  else if (data[0] == 'R'){
    int n = data.length();
    if (data[1] == 1){
      R1 = (data.substring(3, n-1)).toInt();

    }
    else{
      R2 = (data.substring(3, n-1)).toInt();

    }
  }
  else{

  }

}
void ultrasonics(){
  unsigned long curr_time = millis();
  double distance;
  double duration;
  int count;
  digitalWrite(US_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(US_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIG, LOW);
  duration = pulseIn(US_ECHO, HIGH);  //high for 10
    //received back. length of ulse = dist
  distance = duration / 58;
  // if((count != 0 || curr_time >= EVENT)){
  //   if (distance <= STOPPINGDIST ){
  //     if (priority >= 2){      
  //       priority = 2;
  //       drive("STOP");
  //       count = count +1;
  //       curr_time = 0;
  //       delay(1000);
  //     }
  //   }
  //   else {
  //     count = 0;
  //     if (priority != 1){
  //       priority = 4;
  //     }
  //   }

  
  if (distance <= STOPPINGDIST ){
    if (priority >= 2){      
      priority = 2;
      drive("STOP");
      delay(500);
    } 
  }
  else{
  run_regular();
  }
}



void drive(String option){
  //Driving maneouvres
  if (option == "STRAIGHT"){
    analogWrite(V_LEFT, 155);
    analogWrite(V_RIGHT, 155);
    rightM(1);
    leftM(1);
    Serial.println("Straight");
  }

  else if (option == "REVERSE"){
    analogWrite(V_LEFT, 150);
    analogWrite(V_RIGHT, 150);
    rightM(2);
    leftM(2);
    Serial.println("Reverse");
  }

  else if (option == "STOP"){
    analogWrite(V_LEFT, 0);
    analogWrite(V_RIGHT, 0);
    rightM(0);
    leftM(0);
    Serial.println("Stop");
  }

  else if (option == "LEFT"){
    if (priority >= 3){  
      analogWrite(V_RIGHT, R1);
      analogWrite(V_LEFT, L1);
      rightM(1);
      leftM(1);
      Serial.println("Right");  
    }


  }

  else if (option == "RIGHT"){ 
    if (priority >= 3){
      analogWrite(V_LEFT, L2);
      analogWrite(V_RIGHT, R2);
      rightM(1);
      leftM(1);
      Serial.println("Left");
    }

  }

}


void run_regular(){
  if(priority = 4){
    drive("STRAIGHT");
  }
}

//Solely for the purposes of buggy interrupts
void right(){
  drive("RIGHT");  
}
void left(){
  drive("LEFT");
}

void rightM(int state){
switch(state){
case 0:
digitalWrite(S_RIGHT1, 0);
digitalWrite(S_RIGHT2, 0);
break;

case 1:
digitalWrite(S_RIGHT1, 0);
digitalWrite(S_RIGHT2, 1);
break;

case 2: 
digitalWrite(S_RIGHT1, 1);
digitalWrite(S_RIGHT2, 0);
break;
}

}

void leftM(int state){
  switch(state){
  case 0:
  digitalWrite(S_LEFT1, 0);
  digitalWrite(S_LEFT2, 0);
  break;

  case 1:
  digitalWrite(S_LEFT1, 0);
  digitalWrite(S_LEFT2, 1);
  break;

  case 2: 
  digitalWrite(S_LEFT1, 1);
  digitalWrite(S_LEFT2, 0);
  break;
  }

}

  


