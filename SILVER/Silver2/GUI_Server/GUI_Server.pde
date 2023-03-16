//SERVER SIDE TEST
import processing.net.*;
import controlP5.*;
ControlP5 cp5;
PFont font;
String BUG_VEL = "3.00";
String ABS_VEL = "4.00";

Knob myKnobA;
Knob myKnobB;


Server myServer;
void setup() {

  myServer = new Server(this, 5200);
  size(550,400);
  textSize(20);
  background(255,100,100);
  font = createFont("arial", 25);
  

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
  myKnobA = cp5.addKnob("BUGGY")
    .setPosition(300, 45)
    .setSize(120, 120)
    .setFont(font)
    .setResolution(0.01)
    .setValue(float(ABS_VEL))
    ;
  myKnobB = cp5.addKnob("OBJECT")
  .setPosition(300, 220)
  .setSize(120, 120)
  .setFont(font)
  .setResolution(0.01)
  .setValue(float(BUG_VEL))
  ;
} 
void draw() {
  Client thisClient = myServer.available();
  myKnobA.setValue(float(BUG_VEL));
  myKnobB.setValue(float(ABS_VEL));
  // If the client is not null, and says something, display what it said
  if (thisClient !=null) {
    String whatClientSaid = thisClient.readString();
    println(whatClientSaid);
    if (whatClientSaid != null){
      String test = whatClientSaid.substring(0,3);
      if(test.equals("BUG") == true){        
        BUG_VEL = whatClientSaid.substring(3,7);
      }
      else if (test.equals("ABS") == true){
        ABS_VEL = whatClientSaid.substring(3,7);
      }
      
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
  myServer.write("STOP");
}
