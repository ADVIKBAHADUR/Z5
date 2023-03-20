#include "Turning.h"

void check_for_turn(){
  if (digitalRead(LEYE) == LOW){
    right();
  }
  else if (digitalRead(REYE) == LOW){
    left();
  }
  else{
    straight();
  }
  
}