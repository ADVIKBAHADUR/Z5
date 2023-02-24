import processing.net.*;
import controlP5.*;
ControlP5 cp5;
PFont font;

Client myClient;

void setup(){
  size(600,400);
  textSize(20);
  background(255,100,100);
  font = createFont("arial", 30);
  
  myClient = new Client(this, "192.168.154.127", 5200); //get IP address of Arduino
  myClient.write("I am a new client");

cp5 = new ControlP5(this);
  cp5.addButton("Start")
     .setValue(0)
     .setPosition(60,60)
     .setSize(140,100)
     .setFont(font)
     .activateBy(ControlP5.PRESSED);
     ;
  cp5.addButton("Stop")
     .setValue(0)
     .setPosition(60,240)
     .setSize(140,100)
     .setFont(font)
     .activateBy(ControlP5.PRESSED);
     ;
  text("RIGHT WHEEL", 225, 50);
  cp5.addSlider("LEFT_RPM_1")
    .setPosition(230, 60)
    .setSize(40, 280)
    .setRange(0, 255)
    .setValue(100)
    .setNumberOfTickMarks(255)
    .setSliderMode(Slider.FLEXIBLE)
    .setTriggerEvent(ControlP5.RELEASED)
    .getValueLabel().align(ControlP5.RIGHT, ControlP5.TOP_OUTSIDE).setPaddingX(1);
    ;
  cp5.addSlider("RIGHT_RPM_1")
    .setPosition(300, 60)
    .setSize(40, 280)
    .setRange(0, 255)
    .setValue(100)
    .setNumberOfTickMarks(255)
    .setSliderMode(Slider.FLEXIBLE)
    .setTriggerEvent(ControlP5.RELEASED)
    .getValueLabel().align(ControlP5.RIGHT, ControlP5.TOP_OUTSIDE).setPaddingX(1);
    ;
    
  text("LEFT WHEEL", 380, 50);
  cp5.addSlider("LEFT_RPM_2")
    .setPosition(380, 60)
    .setSize(40, 280)
    .setRange(0, 255)
    .setValue(100)
    .setNumberOfTickMarks(255)
    .setSliderMode(Slider.FLEXIBLE)
    .setTriggerEvent(ControlP5.RELEASED)
    .getValueLabel().align(ControlP5.RIGHT, ControlP5.TOP_OUTSIDE).setPaddingX(1);
    ;
  cp5.addSlider("RIGHT_RPM_2")
    .setPosition(440, 60)
    .setSize(40, 280)
    .setRange(0, 255)
    .setValue(100)
    .setNumberOfTickMarks(255)
    .setSliderMode(Slider.FLEXIBLE)
    .setTriggerEvent(ControlP5.RELEASED)
    .getValueLabel().align(ControlP5.RIGHT, ControlP5.TOP_OUTSIDE).setPaddingX(1);
    ;
  smooth();
}

void draw(){}

public void Start() {
  println("Start");
  myClient.write("GO");
}
public void Stop(){
  println("Stop");
  myClient.write("STOP");
}

public void LEFT_RPM_1(float theValue){

}
