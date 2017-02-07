#include "Transition.h"

/******************************************************************************/
/* PUBLIC METHODS                                                             */
/******************************************************************************/

Transition::Transition(){
	logger.debug("Transition - Transition\n");
}

void Transition::reset(){

	logger.debug("Transition - reset\n");

	transitionToInactive();
}

int Transition::getTransitionToPerform(State state){

	logger.debug("Transition - getTransitionToPerform\n");

	return inputOutputUtils.getTransitionToPerform(state);
}

void Transition::transitionToInactive(){

	logger.debug("Transition - transitionToInactive\n");

	openMitten();
	openForefinger();
	openThumb();
}

void Transition::transitionToIdle(){

	logger.debug("Transition - transitionToIdle\n");

	openMitten();
	openForefinger();
	openThumb();
}

void Transition::transitionToTongs(){

	logger.debug("Transition - transitionToTongs\n");

	openMitten();
	closeForefinger();
	closeThumb();
}

void Transition::transitionToFinger(){

	logger.debug("Transition - transitionToFinger\n");

	closeMitten();
	openForefinger();
	closeThumb();
}

void Transition::transitionToClose(){

	logger.debug("Transition - transitionToClose\n");

	closeMitten();
	closeForefinger();
	openThumb();
}

void Transition::transitionToFist(){

	logger.debug("Transition - transitionToFist\n");

	closeMitten();
	closeForefinger();
	closeThumb();
}

/******************************************************************************/
/* PRIVATE METHODS                                                            */
/******************************************************************************/

  void Transition::openMitten(){

    logger.debug("Transition - openMitten\n");
    inputOutputUtils.openMitten();
  }

  void Transition::closeMitten(){

    logger.debug("Transition - closeMitten\n");
    inputOutputUtils.closeMitten();
  }

  void Transition::openForefinger(){

    logger.debug("Transition - openForefinger\n");
    inputOutputUtils.openForefinger();
  }

  void Transition::closeForefinger(){

    logger.debug("Transition - closeForefinger\n");
    inputOutputUtils.closeForefinger();
  }

  void Transition::openThumb(){

    logger.debug("Transition - openThumb\n");
    inputOutputUtils.openThumb();
  }

  void Transition::closeThumb(){

    logger.debug("Transition - closeThumb\n");
    inputOutputUtils.closeThumb();
  }
