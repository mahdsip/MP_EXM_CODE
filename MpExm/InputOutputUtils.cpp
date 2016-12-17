#include "InputOutputUtils.h"
#include "MsTimer2.h"


/******************************************************************************/
/* PUBLIC INPUT METHODS                                                       */
/******************************************************************************/

void InputOutputUtils::initializeInputElements(){

	logger.debug("InputOutputUtils - initializeInputElements\n");

	myowareSensorController1 = MyoControl(PIN_INPUT_MYOWARE_SENSOR_1);
	myowareSensorController2 = MyoControl(PIN_INPUT_MYOWARE_SENSOR_2);
}

void InputOutputUtils::calibrateInputElements(){

	logger.debug("InputOutputUtils - calibrateInputElements (50segs aprox.)\n");

	logger.debug("InputOutputUtils - calibrate myoware Sensor 1\n");
	myowareSensorController1.calibration();
	logger.debug("InputOutputUtils - calibrate myoware Sensor 2\n");
	myowareSensorController2.calibration();
}

void InputOutputUtils::samplingInputElements(){

	//logger.debug("InputOutputUtils - sampling\n");

	myowareSensorController1.sampling();
	myowareSensorController2.sampling();
}

void InputOutputUtils::resetInputElements(){

  logger.debug("InputOutputUtils - resetInputElements\n");

  myowareSensorController1.calibration();
  myowareSensorController2.calibration();

}

int InputOutputUtils::getMittenPosition(){

  //TODO: What happens if finger position is diferent to current position?
  int mittenPosition = random(0,1);

  logger.debug("InputOutputUtils - getMittenPosition - Mitten position: %i\n", mittenPosition);

  return mittenPosition;

}

int InputOutputUtils::getForefingerPosition(){

  //TODO: What happens if finger position is diferent to current position?
  int forefingerPosition = random(0,2);

  logger.debug("InputOutputUtils - getForefingerPosition - Forefinger position: %i\n", forefingerPosition);

  return forefingerPosition;
}

int InputOutputUtils::getThumbPosition(){

  //TODO: What happens if finger position is diferent to current position?
  int thumbPosition = random(0,2);

  logger.debug("getThumbPosition - Thumb position: %i\n", thumbPosition);

  return thumbPosition;

}

int InputOutputUtils::getTransitionToPerform(){

    logger.debug("InputOutputUtils - getTransitionToPerform\n");

	boolean activation1 = myowareSensorController1.activation();
	//boolean activation1 = random(2);
	logger.debug("InputOutputUtils - myowareSensorController1 - activation: %d\n", activation1);
	boolean activation2 = myowareSensorController2.activation();
	//boolean activation2 = random(2);
	logger.debug("InputOutputUtils - myowareSensorController2 - activation: %d\n", activation2);


	int transition = false;
	if (activation1)
		//|| activation2)
		transition = STATE_FIST;
	else{
		transition = STATE_IDLE;
	}

   //return test.testInputForTransition();
   return transition;
}

/******************************************************************************/
/* PUBLIC OUTPUT METHODS                                                     */
/******************************************************************************/

void InputOutputUtils::initializeOutputElements(){


  logger.debug("InputOutputUtils - initializeOutputElements\n");

  randomSeed(0);

  // Led Stripe Initialization
  ledStripe = Adafruit_NeoPixel(10, PIN_OUTPUT_LED_STRIPE, NEO_GRB + NEO_KHZ800);
  ledStripe.begin();

  ledStripe.setPixelColor(0, ledStripe.Color(0, 0, 0));
  ledStripe.setPixelColor(1, ledStripe.Color(0, 0, 0));
  ledStripe.setPixelColor(2, ledStripe.Color(0, 0, 0));
  ledStripe.setPixelColor(3, ledStripe.Color(0, 0, 0));
  ledStripe.setPixelColor(4, ledStripe.Color(0, 0, 0));
  ledStripe.show();

  delay(5000);

  ledStripe.setPixelColor(0, ledStripe.Color(0, 255, 0));
  ledStripe.setPixelColor(1, ledStripe.Color(0, 255, 0));
  ledStripe.setPixelColor(2, ledStripe.Color(0, 255, 0));
  ledStripe.setPixelColor(3, ledStripe.Color(0, 255, 0));
  ledStripe.setPixelColor(4, ledStripe.Color(0, 255, 0));
  ledStripe.show();

  // Motors initialization
  //motorMitten.attach(PIN_OUTPUT_SERVO_MITTEN);
  //motorForefinger.attach(PIN_OUTPUT_SERVO_FOREFINGER);
  //motorThumb.attach(PIN_OUTPUT_SERVO_THUMB);

  mittenPosition = 0;
  forefingerPosition = 0;
  thumbPosition = 0;

}

void InputOutputUtils::resetOutputElements(){

  logger.debug("InputOutputUtils - resetOutputElements\n");

  randomSeed(0);

  ledStripe.setPixelColor(0, ledStripe.Color(0, 255, 0));
  ledStripe.setPixelColor(1, ledStripe.Color(0, 255, 0));
  ledStripe.setPixelColor(2, ledStripe.Color(0, 255, 0));
  ledStripe.setPixelColor(3, ledStripe.Color(0, 255, 0));
  ledStripe.setPixelColor(4, ledStripe.Color(0, 255, 0));
  ledStripe.show();

  mittenPosition = 0;
  forefingerPosition = 0;
  thumbPosition = 0;

}

void InputOutputUtils::openMitten(){

  logger.debug("InputOutputUtils - openMitten\n");

  // TODO: Don't move if current position is the same as selected
  ledStripe.setPixelColor(0, ledStripe.Color(0, 255, 0));
  ledStripe.setPixelColor(1, ledStripe.Color(0, 255, 0));
  ledStripe.setPixelColor(2, ledStripe.Color(0, 255, 0));
  ledStripe.show();

}

void InputOutputUtils::closeMitten(){

  logger.debug("InputOutputUtils - closeMitten\n");

  // TODO: Don't move if current position is the same as selected
  ledStripe.setPixelColor(0, ledStripe.Color(255, 0, 0));
  ledStripe.setPixelColor(1, ledStripe.Color(255, 0, 0));
  ledStripe.setPixelColor(2, ledStripe.Color(255, 0, 0));
  ledStripe.show();
  
}

void InputOutputUtils::openForefinger(){

  logger.debug("InputOutputUtils - openForefinger\n");

  // TODO: Don't move if current position is the same as selected
  ledStripe.setPixelColor(3, ledStripe.Color(0, 255, 0));
  ledStripe.show();
  
}

void InputOutputUtils::closeForefinger(){

  logger.debug("InputOutputUtils - closeForefinger\n");

  // TODO: Don't move if current position is the same as selected
  ledStripe.setPixelColor(3, ledStripe.Color(255, 0, 0));
  ledStripe.show();

}

void InputOutputUtils::openThumb(){

  logger.debug("InputOutputUtils - openThumb\n");

  // TODO: Don't move if current position is the same as selected
  ledStripe.setPixelColor(4, ledStripe.Color(0, 255, 0));
  ledStripe.show();

}

void InputOutputUtils::closeThumb(){

  logger.debug("InputOutputUtils - closeThumb\n");
  
  // TODO: Don't move if current position is the same as selected
  ledStripe.setPixelColor(4, ledStripe.Color(255, 0, 0));
  ledStripe.show();
  
}


InputOutputUtils inputOutputUtils = InputOutputUtils();
