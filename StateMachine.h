#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "Game.h"
#include "Interface.h"

enum MachineState {
    INITIALIZING,
    REQUESTING_DATA,
    PLAYING,
    ENDING
};

typedef struct {
    MachineState currentState;
    Game lifeGame;


} StateMachine ;

void init(StateMachine * stateMachine);
void run(StateMachine * stateMachine);
bool isGameStillPlaying(StateMachine * stateMachine);
static void initializingState(StateMachine * stateMachine);

#endif