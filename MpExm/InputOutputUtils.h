#ifndef INPUT_OUTPUT_UTILS_H
#define INPUT_OUTPUT_UTILS_H

// Library for Servo Motors
#include <Servo.h>
// Library for Led Stripe WS2812B control
#include <Adafruit_NeoPixel.h>

#include "Constants.h"
#include "Test.h"
#include "MyoControl.h"

/*****************************************************************************/
/* PIN DESCRIPTION                                                           */
/*****************************************************************************/

// INPUT pin for tactile switch
#define PIN_INPUT_SWITH                              1

// INPUT pin for MyoWare Sensor 1
#define PIN_INPUT_MYOWARE_SENSOR_1                   A0
// INPUT pin for MyoWare Sensor 2
#define PIN_INPUT_MYOWARE_SENSOR_2                   A1

// INPUT pin for mitten related potentiometer
#define PIN_OUTPUT_POTENTIOMETER_MITTEN              4
// INPUT pin for forefinger related potentiometer
#define PIN_OUTPUT_POTENTIOMETER_FOREFINGER          5
// INPUT pin for thumb related potentiometer
#define PIN_OUTPUT_POTENTIOMETER_THUMB               6

// INPUT pin for mitten related amperimeter
#define PIN_OUTPUT_AMPERIMETER_MITTEN                7
// INPUT pin for forefinger related amperimeter
#define PIN_OUTPUT_AMPERIMETER_FOREFINGER            8
// INPUT pin for thumb related amperimeter
#define PIN_OUTPUT_AMPERIMETER_THUMB                 9

// OUTPUT pin for mitten related motor
#define PIN_OUTPUT_MOTOR_MITTEN                     10
// OUTPUT pin for forefinger related motor
#define PIN_OUTPUT_MOTOR_FOREFINGER                 11
// OUTPUT pin for thumb related motor
#define PIN_OUTPUT_MOTOR_THUMB                      12

// OUTPUT pin for LED stripe
#define PIN_OUTPUT_LED_STRIPE                        3

// OUTPUT pin for LED RGB
#define PIN_OUTPUT_LED_RGB                          13

// OUTPUT pin for bluetoothpe
#define PIN_OUTPUT_BLUETOOTH                        15


class InputOutputUtils{

  private:

	// INPUT - Myoware Sensor Controllers
	MyoControl myowareSensorController1;
	MyoControl myowareSensorController2;

    // INPUT - Mitten fingers position readed from sensors (OPEN|CLOSE)
    int mittenPosition;
	// INPUT - Forefinger finger position readed from sensors (OPEN|CLOSE)
    int forefingerPosition;
	// INPUT - Thumb finger position readed from sensors (OPEN|CLOSE)
    int thumbPosition;
  
    // OUTPUT - Motors
    Servo mototMitten;
    Servo mototForefinger;
    Servo motorThumb;

    // OUTPUT - LED Stripe
    Adafruit_NeoPixel ledStripe;

	// TODO - Declarar el resto de los elementos

	// TODELETE - Test Class
	Test test;

  public:

    /*************************************************************************/
    /* INPUT METHODS                                                         */
    /*************************************************************************/

	// TODO - Llevarlo a la librería cuando corrija el embuclamiento
	void sampling();

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
    // returns: OPEN|CLOSE
    int getForefingerPosition();

    // Detects thumb position from output elements feedback
    // returns: OPEN|CLOSE
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

       // Moves thumb to OPEN postion if necesary
    void openThumb();

    // Moves mitten to CLOSE postion if necesary
    void closeThumb();

};

extern InputOutputUtils inputOutputUtils;

#endif
