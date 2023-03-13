//SERVER SIDE TEST
import processing.net.*;
import controlP5.*;
ControlP5 cp5;
PFont font;


Server myServer;
void setup() {
  myServer = new Server(this, 5200);
  size(600,400);
  textSize(20);
  background(255,100,100);
  font = createFont("arial", 30);
  
  cp5 = new ControlP5(this);
  cp5.addButton("Start")
     //.setValue(0)
     .setPosition(60,60)
     .setSize(140,100)
     .setFont(font)
     .activateBy(ControlP5.PRESSED);
     ;
  cp5.addButton("Stop")
     //.setValue(0)
     .setPosition(60,240)
     .setSize(140,100)
     .setFont(font)
     .activateBy(ControlP5.PRESSED);
     ;
} 
void draw() {
  Client thisClient = myServer.available();
  // If the client is not null, and says something, display what it said
  if (thisClient !=null) {
    String whatClientSaid = thisClient.readString();
    if (whatClientSaid != null) {
      println(whatClientSaid);
    } 
  } 
}

public void Start() {
  println("Start");
  myServer.write("GO");
}
public void Stop(){
  println("Stop");
  myServer.write("STOP");
}

void serverEvent(Server someServer , Client someClient) {
  println("We have a new client: " + someClient.ip());
  myServer.write("You are connected to the server");

}
