#include "Ultrasonics.h"
NewPing sonar(US_TRIG, US_ECHO);

double duration(){ //Returns duration from obstacle

  double duration;
 digitalWrite(US_TRIG, LOW);
 delayMicroseconds(2);
 digitalWrite(US_TRIG, HIGH);
 delayMicroseconds(10);
 digitalWrite(US_TRIG, LOW);
 duration = pulseIn(US_ECHO, HIGH);
  //duration = sonar.ping_median(5);  //high for 10
    //received back. length of ulse = dist
  return duration;
} 

int distance(){
  double distance;
  distance = duration() / 58;
  Serial.println(distance);
  return distance;
}

bool stop_for_object(){ // Stops for obstacle when at a certain distance
  Serial.println(distance());
  if (distance() <= STOPPINGDIST){
    writeMessages("Obstacle Seen");
    return true;
  }
  else{
    return false;
  }
}
