#ifndef INPUT_OUTPUT_UTILS_H
#define INPUT_OUTPUT_UTILS_H

// Library for Servo Motors
#include <Servo.h>
// Library for Led Stripe WS2812B control
#include <Adafruit_NeoPixel.h>

#include "Constants.h"

/*****************************************************************************/
/* PIN DESCRIPTION                                                           */
/*****************************************************************************/
// INPUT pin for MyoWare Sensor 1
#define PIN_INPUT_MYOWARE_SENSOR_1     1
// INPUT pin for MyoWare Sensor 2
#define PIN_INPUT_MYOWARE_SENSOR_2     2

// OUTPUT pin for LED stripe
#define PIN_OUTPUT_LED_STRIPE          6

// OUTPUT pin for mitten related servomotor
#define PIN_OUTPUT_SERVO_MITTEN        4
// OUTPUT pin for forefinger related servomotor
#define PIN_OUTPUT_SERVO_FOREFINGER    5
// OUTPUT pin for thumb related servomotor
#define PIN_OUTPUT_SERVO_THUMB         7


class InputOutputUtils{

  private:

	// INPUT - Mioware Sensor Data 1 
    int miowareSensorData1;
	// INPUT - Mioware Sensor Data 2 
    int miowareSensorData2;

    // INPUT - Mitten fingers position readed from sensors (OPEN|CLOSE)
    int mittenPosition;
	// INPUT - Forefinger finger position readed from sensors (OPEN|CLOSE|TONGS)
    int forefingerPosition;
	// INPUT - Thumb finger position readed from sensors (OPEN|CLOSE|TONGS)
    int thumbPosition;
  
    // OUTPUT - Servo Motors
    Servo servoMitten;
    Servo servoForefinger;
    Servo servoThumb;

    // OUTPUT - LED Stripe
    Adafruit_NeoPixel ledStripe;

  public:

    /*************************************************************************/
    /* INPUT METHODS                                                         */
    /*************************************************************************/

    // Initialization of INPUT sensors
    void initializeInputElements();

    // Reset of INPUT sensors
    void resetInputElements();

	// Identifies the state selected by user from input elements feedback
    // An interpretation and treatment of readed data from sensors will be  
	// needed to perform the required transition to get the selected state 
	// without  ambiguity
    // returns: Transition value
    int getTransitionToPerform();
	
    // Detects mitten position from output elements feedback
    // returns: OPEN|CLOSE
    int getMittenPosition();

    // Detects forefinger position from output elements feedback
    // returns: OPEN|CLOSE|TONGS
    int getForefingerPosition();

    // Detects thumb position from output elements feedback
    // returns: OPEN|CLOSE|TONGS
    int getThumbPosition();


    /**************************************************************************/
    /* OUTPUT METHODS                                                         */
    /**************************************************************************/

    // Initialization of OUTPUT elements
    void initializeOutputElements();

    // Reset of OUTPUT elements
    void resetOutputElements();

    // Moves mitten to OPEN postion if necesary
    void openMitten();

    // Moves mitten to CLOSE postion if necesary
    void closeMitten();

    // Moves forefinger to OPEN postion if necesary
    void openForefinger();

    // Moves forefinger to CLOSE postion if necesary
    void closeForefinger();

    // Moves forefinger to TONGS postion if necesary
    void tongsForefinger();

    // Moves thumb to OPEN postion if necesary
    void openThumb();

    // Moves mitten to CLOSE postion if necesary
    void closeThumb();

    // Moves mitten to TONGS postion if necesary
    void tongsThumb();

};

extern InputOutputUtils inputOutputUtils;

#endif
