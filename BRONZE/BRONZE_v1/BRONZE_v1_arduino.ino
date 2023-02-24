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
const unsigned long EVENT = 30000;//unsigned as gets realy long
const int STOPPINGDIST = 20;
unsigned long prev_event = 0;
int L1 = 200;
int L2 = 50;
int R1 = 50;
int R2= 200;


//WiFi Config
char ssid[] = "Advik's Galaxy"; 
char pass[] = "12345678"; 
WiFiServer server(5200); 
int brake = 1;

void setup() { 

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



  Serial.begin(9600); 
  WiFi.begin(ssid, pass); 
  IPAddress ip = WiFi.localIP(); 
  Serial.print("IP Address:"); 
  Serial.println(ip); 
  server.begin();

}
void loop(){
  int check = wifi();
//Check for if button pressed 
  if (check == 2){
    if (brake == 1){
      stop();    
    }
    else if (brake ==0){
      straight();
    }
    else{

    }    
  }
  else if(check != 2){
    brake = check;
  }

//ULTRASONICS
  unsigned long curr_time = millis();

  double distance;
  double duration;
  digitalWrite(US_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(US_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(US_TRIG, LOW);
  duration = pulseIn(US_ECHO, HIGH);  //high for 10
    //received back. length of ulse = dist
  distance = duration / 58;
  if (distance <= STOPPINGDIST){
    stop();
  }
  Serial.print("Distance= ");
  Serial.print(distance);
  Serial.println("cm");
  //delay(1000);

}




int wifi(){
  WiFiClient client = server.available();
  String data = client.readString();
  if(data == "GO"){
    return(0);
  }
  else if (data =="STOP"){
    return(1);
  }
    else if (data[0] == 'L'){
      int n = data.length();
      if (data[1] == 1){
        L1 = (data.substring(3, n-1)).toInt();
        return(2);
      }
      else{
        L2 = (data.substring(3, n-1)).toInt();
        return(2);
      }
    }
    else if (data[0] == 'R'){
      int n = data.length();
      if (data[1] == 1){
        R1 = (data.substring(3, n-1)).toInt();
        return(2);
      }
      else{
        R2 = (data.substring(3, n-1)).toInt();
        return(2);
      }
    }
    else{
      return(2);
    }
}

void straight(){
  analogWrite(V_LEFT, 150);
  analogWrite(V_RIGHT, 150);
  rightM(1);
  leftM(1);
  Serial.println("Straight");
}

void reverse(){
  analogWrite(V_LEFT, 150);
  analogWrite(V_RIGHT, 150);
  rightM(2);
  leftM(2);
  Serial.println("Reverse");
}

void stop(){
  analogWrite(V_LEFT, 0);
  analogWrite(V_RIGHT, 0);
  rightM(0);
  leftM(0);
  Serial.println("Stop");
}

void left(){
  if (brake != 1){  
  analogWrite(V_RIGHT, R1);
  analogWrite(V_LEFT, L1);
  rightM(1);
  leftM(1);
  Serial.println("Right");  
  }

}

void right(){ 
  if (brake != 1){
  analogWrite(V_LEFT, L2);
  analogWrite(V_RIGHT, R2);
  rightM(1);
  leftM(1);
  Serial.println("Left");
  }
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
