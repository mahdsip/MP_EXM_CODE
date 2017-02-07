#include "Test.h"

/******************************************************************************/
/* PUBLIC METHODS                                                             */
/******************************************************************************/

int Test::testInputForTransition(){

  int transition = 0;
  
	if (TEST_MODE){
	
		logger.debug("State - testInputForTransition");
  
		logger.info("\nIntroduce un valor para el estado deseado: \n");
		logger.info("  (0) STATE_INACTIVE\n");
		logger.info("  (1) STATE_IDLE\n");
		logger.info("  (2) STATE_TONGS\n");
		logger.info("  (3) STATE_FINGER\n");
		logger.info("  (4) STATE_CLOSE\n");
		logger.info("  (5) STATE_FIST\n");

		// send data only when you receive data:
		while(!Serial.available());

		// read the incoming byte:
		transition = Serial.parseInt();
	}

	return transition;
  
}

void Test::testInitializeLedStripe(){

	if(TEST_MODE){
  
		ledStripe = Adafruit_NeoPixel(10, 13, NEO_GRB + NEO_KHZ800);
		ledStripe.begin();
	
		ledStripe.setPixelColor(0, ledStripe.Color(0, 0, 0));
		ledStripe.setPixelColor(1, ledStripe.Color(0, 0, 0));
		ledStripe.setPixelColor(2, ledStripe.Color(0, 0, 0));
		ledStripe.setPixelColor(3, ledStripe.Color(0, 0, 0));
		ledStripe.setPixelColor(4, ledStripe.Color(0, 0, 0));
		ledStripe.show();
	
		ledStripe.setPixelColor(0, ledStripe.Color(0, 255, 0));
		ledStripe.setPixelColor(1, ledStripe.Color(0, 255, 0));
		ledStripe.setPixelColor(2, ledStripe.Color(0, 255, 0));
		ledStripe.setPixelColor(3, ledStripe.Color(0, 255, 0));
		ledStripe.setPixelColor(4, ledStripe.Color(0, 255, 0));
		ledStripe.show();
   
	}
	
}


void Test::testOutputWithLedStripe(int pos, int r, int g, int b){

    if(TEST_MODE){

	    ledStripe.setPixelColor(pos, ledStripe.Color(r, g, b));
	    ledStripe.show();
   
    }
}
