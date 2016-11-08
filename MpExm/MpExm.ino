#include "Constants.h"
#include "InputOutputUtils.h"
#include "StateMachine.h"

#define LOGLEVEL LOG_LEVEL_DEBUG

StateMachine stateMachine;

void setup(){
  
  logger.init(LOGLEVEL,9600);
  logger.debug("\n-------------> Setup\n");
   
  inputOutputUtils.initializeInputElements();
  inputOutputUtils.initializeOutputElements();

  stateMachine.start();

}

void loop(){

  logger.debug("\n-------------> Loop\n");
  stateMachine.executeTransition();
  
}

void reset(){
  inputOutputUtils.resetInputElements();
  inputOutputUtils.resetOutputElements();
  stateMachine.reset();
}
