#include "InputOutputUtils.h"

/******************************************************************************/
/* PUBLIC INPUT METHODS                                                       */
/******************************************************************************/

void InputOutputUtils::initializeInputElements(){

  logger.debug("InputOutputUtils - initializeInputElements\n");

  randomSeed(0);

  accelerometerData   = 0;
  giroscopeData       = 0;
  miowareSensorData1  = 0;
  miowareSensorData2  = 0;

}

void InputOutputUtils::resetInputElements(){

  logger.debug("InputOutputUtils - resetInputElements");

  randomSeed(0);

  accelerometerData   = 0;
  giroscopeData       = 0;
  miowareSensorData1  = 0;
  miowareSensorData2  = 0;

}

int InputOutputUtils::getMittenPosition(){

  int mittenPosition = random(0,1);

  logger.debug("InputOutputUtils - getMittenPosition - Mitten position: %i\n", mittenPosition);

  return mittenPosition;

}

int InputOutputUtils::getForefingerPosition(){

  int forefingerPosition = random(0,2);

  logger.debug("InputOutputUtils - getForefingerPosition - Forefinger position: %i\n", forefingerPosition);

  return forefingerPosition;
}

int InputOutputUtils::getThumbPosition(){

  int thumbPosition = random(0,2);

  logger.debug("getThumbPosition - Thumb position: %i\n", thumbPosition);

  return thumbPosition;

}

int InputOutputUtils::getTransitionToPerform(){

    logger.debug("InputOutputUtils - getTransitionToPerform\n");

    //miowareSensorData1  = analogRead(PIN_INPUT_MYOWARE_SENSOR_1);
    //miowareSensorData2  = analogRead(PIN_INPUT_MYOWARE_SENSOR_2);
	
	Serial.print("\nIntroduce un valor para el estado deseado: \n");
    Serial.print("  (0) STATE_INACTIVE\n");
    Serial.print("  (1) STATE_IDLE\n");
    Serial.print("  (2) STATE_TONGS\n");
    Serial.print("  (3) STATE_CLOSE\n");
    Serial.print("  (4) STATE_CLOSE\n");
    Serial.print("  (5) STATE_FIST\n");

    // send data only when you receive data:
    while(!Serial.available());

    // read the incoming byte:
    int transition = Serial.parseInt();

    logger.debug("InputOutputUtils - getTransitionToPerform - Transtion: %i\n", transition);

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

  // Servo-motors initialization
  //servoMitten.attach(PIN_OUTPUT_SERVO_MITTEN);
  //servoForefinger.attach(PIN_OUTPUT_SERVO_FOREFINGER);
  //servoThumb.attach(PIN_OUTPUT_SERVO_THUMB);

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

void InputOutputUtils::tongsForefinger(){

  logger.debug("InputOutputUtils - tongsForefinger\n");

  // TODO: Don't move if current position is the same as selected
  ledStripe.setPixelColor(3, ledStripe.Color(0, 0, 255));
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

void InputOutputUtils::tongsThumb(){

  logger.debug("InputOutputUtils - tongsThumb\n");

  // TODO: Don't move if current position is the same as selected
  ledStripe.setPixelColor(4, ledStripe.Color(0, 0, 255));
  ledStripe.show();
  
}

InputOutputUtils inputOutputUtils = InputOutputUtils();
