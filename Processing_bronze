import processing.net.*;

Client myClient;
String data;


void setup() {
 myClient = new Client(this, "192.168.154.127", 5200); //get IP address of Arduino
 myClient.write("I am a new client");
} 


void draw(){
 data = myClient.readString();
 if(data != null){
   println(data);
 }
 
 if(keyPressed){
   if(key == CODED){
     if(keyCode == UP){
       myClient.write("w");
     }
   }
 } 

}
