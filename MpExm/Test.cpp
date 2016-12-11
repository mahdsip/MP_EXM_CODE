#include "State.h"

/******************************************************************************/
/* PUBLIC METHODS                                                             */
/******************************************************************************/


int Test::testInputForTransition(){

	logger.debug("State - testInputForTransition");
  
	Serial.print("\nIntroduce un valor para el estado deseado: \n");
    Serial.print("  (0) STATE_INACTIVE\n");
    Serial.print("  (1) STATE_IDLE\n");
    Serial.print("  (2) STATE_TONGS\n");
    Serial.print("  (3) STATE_FINGER\n");
    Serial.print("  (4) STATE_CLOSE\n");
    Serial.print("  (5) STATE_FIST\n");

    // send data only when you receive data:
    while(!Serial.available());

    // read the incoming byte:
	int transition = Serial.parseInt();

	return transition;
}
