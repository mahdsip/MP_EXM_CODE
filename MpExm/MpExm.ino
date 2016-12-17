#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include "Constants.h"
#include "InputOutputUtils.h"
#include "StateMachine.h"
#include "MsTimer2.h"

#define LOGLEVEL LOG_LEVEL_DEBUG

StateMachine stateMachine;
int counter = 0;

void samplingInputElements(){
	inputOutputUtils.samplingInputElements();
}

void setup(){
  
  logger.init(LOGLEVEL, 115200);
  logger.debug("\n-------------> Setup\n");

  inputOutputUtils.initializeInputElements();

  MsTimer2::set(1, samplingInputElements);
  MsTimer2::start();

  delay(5000);

  inputOutputUtils.calibrateInputElements();

  inputOutputUtils.initializeOutputElements();

  stateMachine.start();

}

void loop(){

  logger.debug("\n-------------> Loop (%d)\n", counter);
  counter++;
  stateMachine.executeTransition();
  delay(5000);

}

void reset(){

	logger.debug("\n-------------> reset\n", counter);

	inputOutputUtils.initializeInputElements();

	MsTimer2::set(1, samplingInputElements);
	MsTimer2::start();

	delay(5000);

	inputOutputUtils.calibrateInputElements();

	inputOutputUtils.initializeOutputElements();

	stateMachine.reset();
}
