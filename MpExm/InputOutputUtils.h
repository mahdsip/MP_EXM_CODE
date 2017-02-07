#ifndef INPUT_OUTPUT_UTILS_H
#define INPUT_OUTPUT_UTILS_H

#include "Constants.h"
#include "Test.h"
#include "MyoControl.h"

/*****************************************************************************/
/* PIN DESCRIPTION                                                           */
/*****************************************************************************/

// Constants
// PWM Min Value
#define MIN_SPEED     0  
// PWM Max Value
#define MAX_SPEED   255  
// Test value
#define TEST_SPEED   50  

// INPUT pin for tactile switch
//#define PIN_INPUT_SWITH                              1
// OUTPUT pin for LED RGB
//#define PIN_OUTPUT_LED_RGB                          13
// OUTPUT pin for bluetoothpe
//#define PIN_OUTPUT_BLUETOOTH                        15                            

// Accesory Board Detection
#define ACC_BRD 
// Multiplexer Control Crazy Pionut Assignement A
#define MUX_A                                       16 
// Multiplexer Control Crazy Pionut Assignement B
#define MUX_B                                       14 
// Multiplexer Control Crazy Pionut Assignement C
#define MUX_C                                       15 
// Main Board Multiplexer Output
#define MUX_MAIN                                     0
// Acc Board Multiplexer Output 
#define MUX_ACC                                      1 

// INPUT pin for MyoWare Sensor 1
#define PIN_INPUT_MYOWARE_SENSOR_1                   0
// INPUT pin for MyoWare Sensor 2
#define PIN_INPUT_MYOWARE_SENSOR_2                   1

// INPUT pin for mitten related potentiometer
#define PIN_OUTPUT_POTENTIOMETER_MITTEN              2
// INPUT pin for forefinger related potentiometer
#define PIN_OUTPUT_POTENTIOMETER_FOREFINGER          4
// INPUT pin for thumb related potentiometer
#define PIN_OUTPUT_POTENTIOMETER_THUMB               6

// INPUT pin for mitten related amperimeter
#define PIN_OUTPUT_CURRENT_SENSOR_MITTEN             3
// INPUT pin for forefinger related amperimeter
#define PIN_OUTPUT_CURRENT_SENSOR_FOREFINGER         5
// INPUT pin for thumb related amperimeter
#define PIN_OUTPUT_CURRENT_SENSOR_THUMB              7

// OUTPUT pin for mitten related motor
#define PIN_OUTPUT_MOTOR_MITTEN_PWM                  9
#define PIN_OUTPUT_MOTOR_MITTEN                      8
// OUTPUT pin for forefinger related motor
#define PIN_OUTPUT_MOTOR_FOREFINGER_PWM              5
#define PIN_OUTPUT_MOTOR_FOREFINGER                  7
// OUTPUT pin for thumb related motor
#define PIN_OUTPUT_MOTOR_THUMB_PWM                   3
#define PIN_OUTPUT_MOTOR_THUMB                       4

//Motor Control Matrix
const int MOTOR_CONTROL_MATRIX[FINGERS][2] = 
   {{PIN_OUTPUT_MOTOR_MITTEN_PWM, PIN_OUTPUT_MOTOR_MITTEN},
    {PIN_OUTPUT_MOTOR_FOREFINGER_PWM, PIN_OUTPUT_MOTOR_FOREFINGER},
    {PIN_OUTPUT_MOTOR_THUMB_PWM, PIN_OUTPUT_MOTOR_THUMB}};   


// Multiplexor Control Matrix
// MYO_0
#define CONTROL_INPUT_MYOWARE_SENSOR_1          0
//MYO_1
#define CONTROL_INPUT_MYOWARE_SENSOR_2          1
// MPOT_0
#define CONTROL_INPUT_POTENTIOMETER_MITTEN      2
// CS_0
#define CONTROL_INPUT_CURRENT_SENSOR_MITTEN     3
// MPOT_1
#define CONTROL_INPUT_POTENTIOMETER_FOREFINGER  4
// CS_1
#define CONTROL_INPUT_CURRENT_SENSOR_FOREFINGER 5
// MPOT_2
#define CONTROL_INPUT_POTENTIOMETER_THUMB       6
// CS_2
#define CONTROL_INPUT_CURRENT_SENSOR_THUMB      7

// const int muxOut[2] = {MUX_MAIN, MUX_ACC};
// Mux Main and Mux Acc Value Store
// const int muxVal[2][8]; 

class InputOutputUtils{

  private:

	// TODELETE - Test Class
	Test test;

	// INPUT - Myoware Sensor Controllers
	MyoControl myowareSensorController1;
  	MyoControl myowareSensorController2;

	// State to retrieve current finger's position
    State currentState;
    
    // Motor Control method
    void motorControl(int motorID, int motorDir, int motorSpeed);

    // Multiplexor input
    int readMultiplexorInput(int controlId);

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
    int getTransitionToPerform(State state);
	
    // Detects mitten position from output elements feedback
    // returns: OPEN|CLOSE
	// TODO: Two solutions for fingers position
    //  - Detect where the finger is
    //  - Trust where the state says we are
    int getMittenPosition();

    // Detects forefinger position from output elements feedback
    // returns: OPEN|CLOSE
	// TODO: Two solutions for fingers position
    //  - Detect where the finger is
    //  - Trust where the state says we are
    int getForefingerPosition();

    // Detects thumb position from output elements feedback
    // returns: OPEN|CLOSE
	// TODO: Two solutions for fingers position
    //  - Detect where the finger is
    //  - Trust where the state says we are
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
