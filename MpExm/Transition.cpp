#include "Transition.h"

/******************************************************************************/
/* PUBLIC METHODS                                                             */
/******************************************************************************/

Transition::Transition(){
	logger.debug("TRANSITION::Transition\n"); 
  className = "Transition";
}

void Transition::reset(){

	logger.debug("TRANSITION::reset\n"); 

	transitionToInactive();
}

int Transition::getTransitionToPerform(State state){

	logger.debug("TRANSITION::getTrans\n"); 

	return inputOutputUtils.getTransitionToPerform(state);
}

void Transition::transitionToInactive(){

	logger.debug("TRANSITION::trans2Inact\n"); 

	openMitten();
	openForefinger();
	openThumb();
}

void Transition::transitionToIdle(){

	logger.debug("TRANSITION::trans2Idle\n"); 

	openMitten();
	openForefinger();
	openThumb();
}

void Transition::transitionToTongs(){

	logger.debug("TRANSITION::transToTongs\n"); 

	openMitten();
	closeForefinger();
	closeThumb();
}

void Transition::transitionToFinger(){

	logger.debug("TRANSITION::trans2Finger\n"); 

	closeMitten();
	openForefinger();
	closeThumb();
}

void Transition::transitionToClose(){

	logger.debug("TRANSITION::trans2Close\n"); 

	closeMitten();
	closeForefinger();
	openThumb();
}

void Transition::transitionToFist(){

	logger.debug("TRANSITION::trans2Fist\n",className); 

	closeMitten();
	closeForefinger();
	closeThumb();
}

/******************************************************************************/
/* PRIVATE METHODS                                                            */
/******************************************************************************/

  void Transition::openMitten(){

    logger.debug("TRANSITION::openMitten\n"); 
    inputOutputUtils.openMitten();
  }

  void Transition::closeMitten(){

    logger.debug("TRANSITION::closeMitten\n"); 
    inputOutputUtils.closeMitten();
  }

  void Transition::openForefinger(){

    logger.debug("TRANSITION::openForefinger\n"); 
    inputOutputUtils.openForefinger();
  }

  void Transition::closeForefinger(){

    logger.debug("TRANSITION::closeForefinger\n"); 
    inputOutputUtils.closeForefinger();
  }

  void Transition::openThumb(){

    logger.debug("TRANSITION::openThumb\n"); 
    inputOutputUtils.openThumb();
  }

  void Transition::closeThumb(){

    logger.debug("TRANSITION::closeThumb\n"); 
    inputOutputUtils.closeThumb();
  }
