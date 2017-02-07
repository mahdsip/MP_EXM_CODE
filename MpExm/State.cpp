#include "State.h"

/******************************************************************************/
/* PUBLIC METHODS                                                             */
/******************************************************************************/

State::State(){

	logger.debug("State - State\n");

	currentState = STATE_INACTIVE;
}

int State::getCurrentState(){

	logger.debug("State - getCurrentState - Current state: %i\n", currentState);

	return currentState;
}

void State::setCurrentState(int state){

	logger.info("State - setCurrentState - Modify current state:  %i\n", state);

	currentState = state;
}

void State::reset(){

	logger.debug("State - reset\n");

	currentState = STATE_INACTIVE;
}


int State::getMittenPosition(){
		
	int fingerPosition   = FINGER_POSITION_MATRIX[currentState][MITTEN];
	logger.info("State - getMittenPosition - State [%i] - Position [%i]\n", currentState, fingerPosition);

	return fingerPosition;

}

int State::getForefingerPosition(){
  
	int fingerPosition   = FINGER_POSITION_MATRIX[currentState][FOREFINGER];
	logger.debug("State - getForefingerPosition - State [%i] - Position [%i]\n", currentState, fingerPosition);

	return fingerPosition;

}

int State::getThumbPosition(){

	logger.debug("State - getThumbPosition\n");
  
	int fingerPosition   = FINGER_POSITION_MATRIX[currentState][THUMB];
	logger.debug("State - getThumbPosition - State [%i] - Position [%i]\n", currentState, fingerPosition);

	return fingerPosition;

}
