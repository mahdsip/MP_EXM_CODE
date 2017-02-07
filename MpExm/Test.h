#ifndef TEST_H
#define TEST_H

// Library for Led Stripe WS2812B control
#include <Adafruit_NeoPixel.h>

#include "State.h"

#define TEST_MODE 1

class Test{

  private:

  Adafruit_NeoPixel ledStripe;
  
  public:

	int  testInputForTransition();
	void testInitializeLedStripe();
	void testOutputWithLedStripe(int pos, int r, int g, int b);

  };

#endif
