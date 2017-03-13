#include "InputOutputUtils.h"

/******************************************************************************/
/* INITIALIZATION INPUT METHODS                                               */
/******************************************************************************/

void InputOutputUtils::initializeInputElements() {

	logger.debug("InputOutputUtils - initializeInputElements (50segs aprox.)\n");

	myowareSensorController1 = MyoControl(CONTROL_INPUT_MYOWARE_SENSOR_1);
	myowareSensorController2 = MyoControl(CONTROL_INPUT_MYOWARE_SENSOR_2);
  
	logger.info("InputOutputUtils - initializeInputElements - Calibrate myoware Sensor 1\n");
	myowareSensorController1.calibration();
	logger.info("InputOutputUtils - initializeInputElements - Calibrate myoware Sensor 2\n");
	myowareSensorController2.calibration();
	
	//test.testInitializeLedStripe();

}

void InputOutputUtils::resetInputElements() {

	logger.debug("InputOutputUtils - resetInputElements\n");

	myowareSensorController1.calibration();
	myowareSensorController2.calibration();

}

/******************************************************************************/
/* INITIALIZATION OUTPUT METHODS                                              */
/******************************************************************************/

void InputOutputUtils::initializeOutputElements() {


	logger.info("InputOutputUtils - initializeOutputElements\n");

	// Initialize motors pinout
	pinMode(MUX_A, OUTPUT);
	pinMode(MUX_B, OUTPUT);
	pinMode(MUX_C, OUTPUT);
  
	// Initialize motors pinout
	pinMode(PIN_OUTPUT_MOTOR_MITTEN_PWM, OUTPUT);
	pinMode(PIN_OUTPUT_MOTOR_MITTEN, OUTPUT);
	pinMode(PIN_OUTPUT_MOTOR_FOREFINGER_PWM, OUTPUT);
	pinMode(PIN_OUTPUT_MOTOR_FOREFINGER, OUTPUT);
	pinMode(PIN_OUTPUT_MOTOR_THUMB_PWM, OUTPUT);
	pinMode(PIN_OUTPUT_MOTOR_THUMB, OUTPUT);
  
	logger.info("InputOutputUtils - initializeOutputElements - Initialize mitten\n");
	initialFingerControl(MITTEN, CONTROL_INPUT_POTENTIOMETER_MITTEN);
	delay(1000);

	//logger.info("InputOutputUtils - initializeOutputElements - Open forefinger\n");
	//initialFingerControl(FOREFINGER, CONTROL_INPUT_POTENTIOMETER_FOREFINGER);
	//delay(1000);

	//logger.info("InputOutputUtils - initializeOutputElements - Open thumb\n");
	//initialFingerControl(THUMB, CONTROL_INPUT_POTENTIOMETER_THUMB);
	//delay(1000);
	
	//test.testOutputWithLedStripe(0,0,0);
	//delay(2000);
	//test.testOutputWithLedStripe(0,255,0);

}

void InputOutputUtils::resetOutputElements() {

	logger.debug("InputOutputUtils - resetOutputElements\n");

	initializeOutputElements();

}


/******************************************************************************/
/* FINGERS POSITION                                                           */
/******************************************************************************/

int InputOutputUtils::getMittenPosition() {

	//TODO: What happens if finger position is diferent to current position?
	// Tenedremos que revisar en qué posicion se encuentar el dedo realmente para 
	// restaurar la posicion si es necesario.
	int mittenPosition = currentState.getMittenPosition();

	logger.info("InputOutputUtils - getMittenPosition - Mitten position: %i\n", mittenPosition);

	return mittenPosition;

}

int InputOutputUtils::getForefingerPosition() {

	// TODO: What happens if finger position is diferent to current position?
	// Tenedremos que revisar en qué posicion se encuentar el dedo realmente para 
	// restaurar la posicion si es necesario.
	int forefingerPosition = currentState.getForefingerPosition();

	logger.debug("InputOutputUtils - getForefingerPosition - Forefinger position: %i\n", forefingerPosition);

	return forefingerPosition;
}

int InputOutputUtils::getThumbPosition() {

	//TODO: What happens if finger position is diferent to current position?
	// Tenedremos que revisar en qué posicion se encuentar el dedo realmente para 
	// restaurar la posicion si es necesario.
	int thumbPosition = currentState.getThumbPosition();

	logger.debug("getThumbPosition - Thumb position: %i\n", thumbPosition);

	return thumbPosition;

}

/******************************************************************************/
/* TRANSITIONS                                                                */
/******************************************************************************/

int InputOutputUtils::getTransitionToPerform(State state) {

	logger.debug("InputOutputUtils - getTransitionToPerform\n");

	currentState = state;

	boolean activation1 = myowareSensorController1.activation();
	logger.info("InputOutputUtils - myowareSensorController1 - activation: %d\n", activation1);
	boolean activation2 = myowareSensorController2.activation();
	logger.info("InputOutputUtils - myowareSensorController2 - activation: %d\n", activation2);

	int transitionTo = 0;
	if(//activation1 ||
	   activation2){
		transitionTo = STATE_FIST;
	}else{
		transitionTo = STATE_IDLE;
	}

	/*
	// Misma prueba un poco mas evolucionada
	int transitionTo = 0;
	if (!activation1 && !activation2){
		logger.info("InputOutputUtils - IDLE\n");
		transitionTo = STATE_IDLE;
	}else if (!activation1 && activation2) {
		logger.info("InputOutputUtils - FINGERS\n");
		transitionTo = STATE_FINGER;
	} else if (activation1 && !activation2) {
		logger.info("InputOutputUtils - TONGS\n");
		transitionTo = STATE_TONGS;
	} else {
		logger.info("InputOutputUtils - FIST\n");
		transitionTo = STATE_FIST;
	}
	*/
	
	/*
  	// TODELETE: Funcionalidad que permite hacer tests con el motor
  	// sin depender de los sensores
	static int i = 0;
	int transitionTo = 0;
	transitionTo = ((i++)%STATES_NUMBER);
	*/

	return transitionTo;
	
}


void InputOutputUtils::openMitten() {

	logger.debug("InputOutputUtils - openMitten\n");

  // TODO - Mucho cuidado!!! Estoy hay que recuperarlo
	//if(getMittenPosition() == CLOSE){
		logger.info("InputOutputUtils - openMitten - OPEN\n");
		//test.testOutputWithLedStripe(0,0,255,0);
		//test.testOutputWithLedStripe(1,0,255,0);
		//test.testOutputWithLedStripe(2,0,255,0);
		fingerControl(MITTEN, OPEN, CONTROL_INPUT_POTENTIOMETER_MITTEN);
	//}

}

void InputOutputUtils::closeMitten() {

	logger.debug("InputOutputUtils - closeMitten\n");

  // TODO - Mucho cuidado!!! Estoy hay que recuperarlo
	//if(getMittenPosition() == OPEN){
		logger.info("InputOutputUtils - closeMitten - CLOSE\n");
		//test.testOutputWithLedStripe(0,255,0,0);
		//test.testOutputWithLedStripe(1,255,0,0);
		//test.testOutputWithLedStripe(2,255,0,0);
		fingerControl(MITTEN, CLOSE, CONTROL_INPUT_POTENTIOMETER_MITTEN);
	//}
}

void InputOutputUtils::openForefinger() {

	logger.debug("InputOutputUtils - openForefinger\n");

	if(getForefingerPosition() == CLOSE){
		logger.debug("InputOutputUtils - openForefinger - OPEN\n");
		//test.testOutputWithLedStripe(3,0,255,0);
		//fingerControl(FOREFINGER, OPEN, CONTROL_INPUT_POTENTIOMETER_FOREFINGER);	
	}
}

void InputOutputUtils::closeForefinger() {

	logger.debug("InputOutputUtils - closeForefinger\n");

	if(getForefingerPosition() == OPEN){
		logger.debug("InputOutputUtils - closeForefinger - CLOSE\n");
		//test.testOutputWithLedStripe(3,255,0,0);
		//fingerControl(FOREFINGER, CLOSE,CONTROL_INPUT_POTENTIOMETER_FOREFINGER);
	}
}

void InputOutputUtils::openThumb() {

	logger.debug("InputOutputUtils - openThumb\n");

	if(getThumbPosition() == CLOSE){
		logger.debug("InputOutputUtils - openThumb - OPEN\n");
		//test.testOutputWithLedStripe(4,0,255,0);
		//fingerControl(THUMB, OPEN, CONTROL_INPUT_POTENTIOMETER_THUMB);
	}

}

void InputOutputUtils::closeThumb() {

	logger.debug("InputOutputUtils - closeThumb\n");

	if(getThumbPosition() == CLOSE){
		logger.debug("InputOutputUtils - closeThumb - CLOSE\n");
		//test.testOutputWithLedStripe(4,255,0,0);
		//fingerControl(THUMB,CLOSE,CONTROL_INPUT_POTENTIOMETER_THUMB);
	}

}


/******************************************************************************/
/* PCB CONTROLS                                                               */
/******************************************************************************/


void InputOutputUtils::initialFingerControl(int motorId,  int controlId){

  logger.info("InputOutputUtils - fingerControl\n");

  int initialPosition = multiplexorRead(controlId);
  int finalPosition = initialPosition;
  logger.info("InputOutputUtils - fingerControl - Initial position: %d\n", initialPosition);

  if(finalPosition < 200){
  while(finalPosition < 200){
	  motorControl(motorId, CLOSE, 100);
	  delay(100);
	  finalPosition = multiplexorRead(controlId);
  }
  motorControl(motorId, CLOSE, MOTOR_SPEED_MIN);
  }

  if(finalPosition > 800){
  while(finalPosition > 800){
  	  motorControl(motorId, OPEN, 100);
  	  delay(100);
  	  finalPosition = multiplexorRead(controlId);
  }
  motorControl(motorId, OPEN, MOTOR_SPEED_MIN);
  }


  logger.info("InputOutputUtils - fingerControl - finalPosition: %d\n", finalPosition);

}


void InputOutputUtils::fingerControl(int motorId, int motorDir, int controlId){

  logger.info("InputOutputUtils - fingerControl\n");

  int initialPosition = multiplexorRead(controlId);
  int finalPosition = initialPosition;
  logger.info("InputOutputUtils - fingerControl - Initial position: %d\n", initialPosition);

  if(initialPosition > 200){

	  motorControl(motorId, CLOSE , MOTOR_SPEED);
	  delay(500);
	  motorControl(motorId, CLOSE, MOTOR_SPEED_MIN);
	  finalPosition = multiplexorRead(controlId);

  }else if (initialPosition < 1000){

	  motorControl(motorId, OPEN , MOTOR_SPEED);
	  delay(500);
	  motorControl(motorId, OPEN, MOTOR_SPEED_MIN);
	  finalPosition = multiplexorRead(controlId);
  }
  
  logger.info("InputOutputUtils - fingerControl - Final position: %d\n", finalPosition);
      
  /*
	motorControl(motorId, motorDir, MOTOR_SPEED); 
	// Manual Stop
	if(motorDir){
    multiplexorRead(controlId);
    delay(1000);
		//while(multiplexorRead(controlId) > 200);
  }else{
    multiplexorRead(controlId);
    delay(1000);
		//while(multiplexorRead(controlId) < 400);
	}	
	motorControl(motorId, motorDir, MOTOR_SPEED_MIN);
 */

}



void InputOutputUtils::motorControl(int motorID, int motorDir, int motorSpeed) {

   logger.info("InputOutputUtils - motorControl\n");

	// Forward Direction --> CLOSE --> 1
	if (motorDir) { 
    logger.info("InputOutputUtils - motorControl - forward direction - CLOSE\n");
		digitalWrite(MOTOR_CONTROL_MATRIX[motorID][1], LOW);
		analogWrite(MOTOR_CONTROL_MATRIX[motorID][0], motorSpeed);
	// Backward Direction --> OPEN --> 0
	} else {
    logger.info("InputOutputUtils - motorControl - backward direction - OPEN\n");
		digitalWrite(MOTOR_CONTROL_MATRIX[motorID][1], HIGH);
		analogWrite(MOTOR_CONTROL_MATRIX[motorID][0], (MOTOR_SPEED_MAX - motorSpeed));
	}
  
}


int InputOutputUtils::multiplexorRead(int controlId){

	// Main Multiplexer (vs Acc Multiplexer)
		
	// Lecture Sensors through 74HC4051 Multiplexer
	// Entry channel selection for 74HC4051
	
	logger.info("InputOutputUtils - multiplexorRead - input[%i]\n", controlId);

	int cA = controlId & 0x01;   
	int cB = (controlId>>1) & 0x01;     
	int cC = (controlId>>2) & 0x01;   
	
	digitalWrite(MUX_A, cA);
	digitalWrite(MUX_B, cB);
	digitalWrite(MUX_C, cC);
  
	int readedValue = analogRead(MUX_MAIN);

	logger.info("InputOutputUtils - multiplexorRead - output[%i]\n", readedValue);
	
	return readedValue;

}

InputOutputUtils inputOutputUtils = InputOutputUtils();
