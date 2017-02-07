#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include "Constants.h"
#include "InputOutputUtils.h"
#include "StateMachine.h"

#define LOGLEVEL LOG_LEVEL_INFOS

StateMachine stateMachine;
int counter = 0;

void setup(){
  
	logger.init(LOGLEVEL, 115200);
	logger.info("\n-------------> Setup\n");

	//inputOutputUtils.initializeInputElements();

	inputOutputUtils.initializeOutputElements();
  
	stateMachine.start();

}

void loop(){

	logger.info("\n-------------> Loop (%d)\n", counter);
	counter++;
	stateMachine.executeTransition();
	delay(5000);

}

void reset(){

	logger.debug("\n-------------> Reset (%d)\n", counter);

	inputOutputUtils.initializeInputElements();

	inputOutputUtils.initializeOutputElements();

	stateMachine.reset();
 
}
