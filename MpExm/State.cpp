#include "State.h"

/******************************************************************************/
/* PUBLIC METHODS                                                             */
/******************************************************************************/

State::State(){

  logger.debug("State - State\n");

  currentState = STATE_INACTIVE;
}

int State::getCurrentState(){

  logger.debug("State - getCurrentState - current state: %i\n", currentState);

  return currentState;
}

void State::setCurrentState(int state){

  logger.debug("State - setCurrentState - modify current state:  %i\n", state);

  currentState = state;
}

void State::reset(){

  logger.debug("State - reset\n");

  currentState = STATE_INACTIVE;
}


int State::getMittenPosition(){

  //int mesuredPosition = inputOutputUtils.getMittenPosition();
  //logger.debug("State - getMittenPosition  - measured: %i\n", mesuredPosition);
	
  int fingerPosition   = FINGER_POSITION_MATRIX[currentState][MITTEN];
  logger.debug("State - getMittenPosition  - from state %i: %i\n", currentState, fingerPosition);

}

int State::getForefingerPosition(){

  //int mesuredPosition  = inputOutputUtils.getForefingerPosition();
  //logger.debug("State - getForefingerPosition  - measured: %i\n", mesuredPosition);
  
  int fingerPosition   = FINGER_POSITION_MATRIX[currentState][FOREFINGER];
  logger.debug("State - getForefingerPosition  - from state %i: %i\n", currentState, fingerPosition);

}

int State::getThumbPosition(){

  logger.debug("State - getThumbPosition\n");

  //int mesuredPosition = inputOutputUtils.getThumbPosition();
  //logger.debug("State - getThumbPosition  - measured: %i\n", mesuredPosition);
  
  int fingerPosition   = FINGER_POSITION_MATRIX[currentState][THUMB];
  logger.debug("State - getThumbPosition  - from state %i: %i\n", currentState, fingerPosition);

}
