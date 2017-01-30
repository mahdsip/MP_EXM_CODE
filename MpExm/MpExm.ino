#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include "Constants.h"
#include "InputOutputUtils.h"
#include "StateMachine.h"

#define LOGLEVEL LOG_LEVEL_DEBUG

StateMachine stateMachine;
int counter = 0;

void setup(){
  
  logger.init(LOG_LEVEL_INFOS, 115200);
  logger.info("\n-------------> Setup\n");

  inputOutputUtils.initializeInputElements();

  delay(5000);

  inputOutputUtils.calibrateInputElements();

  inputOutputUtils.initializeOutputElements();

  stateMachine.start();

}

void loop(){

  logger.debug("\n-------------> Loop (%d)\n", counter);
  counter++;
  stateMachine.executeTransition();
  delay(500);

}

void reset(){

	logger.debug("\n-------------> reset\n", counter);

	inputOutputUtils.initializeInputElements();

	delay(5000);

	inputOutputUtils.calibrateInputElements();

	inputOutputUtils.initializeOutputElements();

	stateMachine.reset();
}
