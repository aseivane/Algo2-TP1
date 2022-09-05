#include <iostream>
#include "main.h"
#include "StateMachine.h"

using namespace std;

void main() 
{
	StateMachine mainProgram;
	PlayerDecision decisionSelected;

	init(&mainProgram);

	do
	{
		runCycle( &mainProgram );

		decisionSelected = nextEvent();

		if( decisionSelected == RESTART_GAME)
		{
			setMachineState( &mainProgram, INITIALIZING);
		}

		if( decisionSelected == END_GAME)
		{
			setMachineState( &mainProgram, ENDING);
		}

	}while ( isGameStillPlaying( &mainProgram ) );
	
}