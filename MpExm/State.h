#ifndef STATE_H
#define STATE_H

#include "Constants.h"

class State{

  private:

  // Current state
    int currentState;

  public:

	// Constructor
    State();
	
	// Resets state
    void reset();

	// Getters and setters
    int  getCurrentState();
    void setCurrentState(int state);

	// Detects mitten position
    // TODO: Two solutions for fingers position
    //    - Detects where the finger is
    //    - Trust where the state says we are
    int getMittenPosition();

	// Detects forefinger position
    // TODO: Two solutions for fingers position
    //    - Detects where the finger is
    //    - Trust where the state says we are
    int getForefingerPosition();

	// Detects thumb position
    // TODO: Two solutions for fingers position
    //    - Detects where the finger is
    //    - Trust where the state says we are
    int getThumbPosition();

  };

#endif
