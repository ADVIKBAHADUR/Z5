#include <WiFiNINA.h>
#include <string>
#include <NewPing.h>



 int LEYE = 9; //11;//5
const int REYE = 3; //2;//3
const int V_RIGHT = 19; //5;//CONFIRMED 19
const int V_LEFT = 16; //12;//16
const int S_RIGHT1 = 7; //8;//CONFIRMED 7
const int S_RIGHT2 =8;  //10;//CONFIRMED 8
const int S_LEFT1 = 2; //6;//2
const int S_LEFT2 = 10; //7;//10

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

} 
void loop() {
 WiFiClient client = server.available(); 

  char data = client.read();

  if (data == 'w'){
    straight();
    Serial.println("Straight");
  }
}

void straight(){
  analogWrite(V_LEFT, 150);
  analogWrite(V_RIGHT, 150);
}

void stop(){
  analogWrite(V_LEFT, 0);
  analogWrite(V_RIGHT, 0);
}