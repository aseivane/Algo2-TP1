#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "Game.h"

enum PlayerDecision {
    PLAY_NEXT_ROUND,
    RESTART_GAME,
    END_GAME,
    INVALID
};

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
void runCycle(StateMachine * stateMachine);
bool isGameStillPlaying(StateMachine * stateMachine);
void setMachineState(StateMachine * stateMachine, MachineState newState);
PlayerDecision nextEvent();
/*
static void initializingState(StateMachine * stateMachine);
static void requestingDataState(StateMachine * stateMachine);
static void playingState(StateMachine * stateMachine);
*/
#endif