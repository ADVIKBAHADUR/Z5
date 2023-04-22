#include "Ports.h"
#include "Turning.h"
#include "Wifi.h"
#include "msg_handler.h"
#include "Drive.h"
#include "Ultrasonics.h"
#include "Follow_leader.h"
#include "Encoder.h"
#include "Coord.h"
#include "Alpha.h"

void setup() {
  
  error, prev_error = 0;
  time, prev_time = 0;
  parked = 1;
  connect();
  StartEncoder();
  //attachInterrupt(digitalPinToInterrupt(LEYE), right, LOW);
  //attachInterrupt(digitalPinToInterrupt(REYE), left, LOW);
  attachInterrupt(digitalPinToInterrupt(encoder), doEncoder, RISING);


}
void loop() {
  if (parked == 1 /*|| stop_for_object()*/){ //Uncomment for bronze challenge
    stop();
  }
  else{
    //Straight(); //Uncomment for bronzze challenge
    follow_leader(); //Silver
  }

  String msg = readMessages();
  if (msg != "-1"){
    if (handle_msg(msg) == 1){
      stop();
      parked = 1;
    }
    else if (handle_msg(msg) == 0){
      straight();
      parked = 0;
    }
    
  }
  run_encoder();

}