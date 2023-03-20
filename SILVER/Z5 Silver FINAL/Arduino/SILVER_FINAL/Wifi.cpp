#include "Wifi.h"
char ssid[] = "Advik's Galaxy"; 
char pass[] = "12345678";

WiFiClient client;
IPAddress server(192,168,193,124);
void connect(){
  bool connected = false;
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  client.connect(server,5200);
  while(!connected){ 
    if (WiFi.status() == 3){
      client.write("You are connected to the Arduino Client");
      Serial.println("Connected");
      connected = true;
    }
    else{
      connected = false;
    }
  }
}
String readMessages(){
  if(client.available()){
    return(client.readString());
  }
  else{
    return("-1");
  }
}

void writeMessages(const char *msg){
  client.write(msg);
}
