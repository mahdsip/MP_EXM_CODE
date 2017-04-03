#include "StateMachine.h"
#include "Constants.h"

/******************************************************************************/
/* PUBLIC METHODS                                                             */
/******************************************************************************/

void StateMachine::start(){

  logger.debug("STATEMACHINE::start\n");

  state = State();
  // TODO: Puesto a IDLE para que partamos en las pruebas 
  // de un estado desde el que podamos hacer movimientos.
  // Deberiamos arrancar en INNACTIVE
  state.setCurrentState(STATE_IDLE);
  transition = Transition();
}

void StateMachine::executeTransition(){

    logger.debug("STATEMACHINE::execTrans\n");
    
    int currentState = state.getCurrentState();

    int transitionToPeform = transition.getTransitionToPerform(state);

    logger.debug("--Transition: %i\n", transitionToPeform);

    switch(transitionToPeform){

      case INVALID_TRANSITION:
      break;

      case TRANSITION_TO_INACTIVE:
        transition.transitionToInactive();
        state.setCurrentState(STATE_INACTIVE);
      break;

      case TRANSITION_TO_IDLE:
        transition.transitionToIdle();
        state.setCurrentState(STATE_IDLE);
      break;

      case TRANSITION_TO_TONGS:
        if(state.getCurrentState() != STATE_INACTIVE){
          transition.transitionToTongs();
          state.setCurrentState(STATE_TONGS);
        }
      break;

      case TRANSITION_TO_FINGER:
        if(state.getCurrentState() != STATE_INACTIVE){
          transition.transitionToFinger();
          state.setCurrentState(STATE_FINGER);
        }
      break;

      case TRANSITION_TO_CLOSE:
        if(state.getCurrentState() != STATE_INACTIVE){
          transition.transitionToClose();
          state.setCurrentState(STATE_CLOSE);
        }
      break;

      case TRANSITION_TO_FIST:
        if(state.getCurrentState() != STATE_INACTIVE){
          transition.transitionToFist();
          state.setCurrentState(STATE_FIST);
        }
      break;

      default:
      break;

    }
}

void StateMachine::reset(){

  logger.debug("**STATEMACHINE::reset**\n");

  state.reset();
  transition.reset();

}
