#include <Arduino.h>

#include "Logging.h"
#include "InputOutputUtils.h"

#ifndef CONSTANTS_H
#define CONSTANTS_H

/*****************************************************************************/
/* GENERAL                                                                   */
/*****************************************************************************/

// Identifies open position
#define OPEN                  0
// Identifies close position
#define CLOSE                 1
// Identifies tongs position
#define TONGS                 2

// Number of finger elements
#define FINGERS               3
// Identifies mitten fingers
#define MITTEN                0
// Identifies forefinger finger
#define FOREFINGER            1
// Identifies thumb finger
#define THUMB                 2

/*************************************************************************/
/* STATES                                                                */
/*************************************************************************/
// State Number
#define STATES_NUMBER                 6
// Inactive state (inactivo)
#define STATE_INACTIVE                0
// Resting/Initial state. Open hand (reposo)
#define STATE_IDLE                     1
// Tongs state. Thumb + forefinger (pinza)
#define STATE_TONGS                    2
// Finger state. Forefinger  (señalar)
#define STATE_FINGER                   3
// Close state. Mitten + forefinger (ok)
#define STATE_CLOSE                    4
// Fist state. Mitten + forefinger + thumb (cerrado, puño)
#define STATE_FIST                     5


/*************************************************************************/
/* TRANSITIONS                                                           */
/*************************************************************************/
// Transition Number
#define TRANSITIONS_NUMBER             6

// Transition to inactive state
#define INVALID_TRANSITION            -1
// Transition to inactive state
#define TRANSITION_TO_INACTIVE         0
// Transition to resting/initial state
#define TRANSITION_TO_IDLE             1
// Transition to Tongs state
#define TRANSITION_TO_TONGS            2
// Transition to finger state
#define TRANSITION_TO_FINGER           3
// Transition to close state
#define TRANSITION_TO_CLOSE            4
// Transition to fist state
#define TRANSITION_TO_FIST             5

// Fingers position matrix from states definition
// TODO: Considerar todos los posibles estados

const int FINGER_POSITION_MATRIX[STATES_NUMBER][FINGERS] = {

 // MITTEN   FORE  THUMB
    { OPEN,  OPEN,  OPEN  }, // STATE_INACTIVE
    { OPEN,  OPEN,  OPEN  }, // STATE_IDLE
    { OPEN,  TONGS, TONGS }, // STATE_TONGS
    { CLOSE, OPEN,  CLOSE }, // STATE_FINGER
    { CLOSE, CLOSE, OPEN  }, // STATE_CLOSE
    { CLOSE, CLOSE, CLOSE }  // STATE_FIST
};


#endif
