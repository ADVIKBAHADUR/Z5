#include "msg_handler.h"
/*
MESSAGE PROTOCOL
GO --> Go
STOP --> Stop
V133 --> 1.33m/s
D12.01 --> 12.01 m
You are... --> Print message
OS --> Obstacle seen
OA --> Obstacle avoided
*/

int handle_msg(String msg){
  if(msg != "0"){
    if(msg == "GO"){
      return(0);
    }
    else if (msg == "STOP"){
      return(1);
    }
  }
}