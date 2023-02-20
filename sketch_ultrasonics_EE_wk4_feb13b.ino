
/*
#include <W
const int LEYE = 2;
void setup() {
 Serial.begin( 9600 );
 pinMode(LEYE, INPUT);
}
void loop() {
 bool all_clear = digitalRead( LEYE );

 if( !all_clear ){
 Serial.println("I see you!");
 }else{
 Serial.println("No");
 }
 delay( 1000 );
}
*/
const int US_TRIG = 3;
const int US_ECHO = 4;
const unsigned long EVENT = 1000;//unsigned as gets realy long
const int STOPPINGDIST = 10;
unsigned long prev_event = 0;
//int time = millis();

void setup() {
  Serial.begin(9600);
  pinMode(US_ECHO, INPUT);
  pinMode(US_TRIG, OUTPUT);
}
//pinMode(LEYE, INPUT);

void loop() {
  //if (time % 3000000 == 0) {
  unsigned long curr_time = millis();
  if (curr_time - prev_event >= EVENT) {
    //bool all_clear = digitalRead( LEYE );

    //if( !all_clear ){
    //Serial.println("I see you!");
    //}else{
    //Serial.println("No");
    //}
    //delay( 1000 );

    int distance;
    long duration;
    digitalWrite(US_TRIG, LOW);
    delayMicroseconds(2);

    digitalWrite(US_TRIG, HIGH);
    delayMicroseconds(10);  //high for 10
    digitalWrite(US_TRIG, LOW);
    duration = pulseIn(US_ECHO, HIGH);  //received back. length of ulse = dist
    distance = duration / 58;
    if (distance <= STOPPINGDIST){
      
      // find out 1/0 whch component for stopping
    }
    Serial.print("Distance= ");
    Serial.print(distance);
    Serial.println("cm");
    //delay(1000);
    prev_event = curr_time;
  }
}
