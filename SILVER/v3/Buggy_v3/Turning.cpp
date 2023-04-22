#include "Turning.h"

void check_for_turn(){
  if (digitalRead(LEYE) == LOW){
    left();
  }
  else if (digitalRead(REYE) == LOW){
    right();
  }
  else{
    straight();
  }
  
}