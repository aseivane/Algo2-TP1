#include "main.h"
#include "StateMachine.h"

int main() 
{
	StateMachine mainProgram;
	PlayerDecision decisionSelected;

	// set first state for the main program state machine
	init(&mainProgram);

	do
	{
		// runs a cycle on the state machine to move to the next state
		runCycle( &mainProgram );

		/* after the code inside the state is executed, asks for
		* an external event to decide the next step 
		*/
		if(PLAYING == mainProgram.currentState ) 
		{
			decisionSelected = nextEvent();
		}
		
		/* if the player decides to restar the game, the machine
		* goes to the initial state and repeats the process
		*/
		if( decisionSelected == RESTART_GAME)
		{
			setMachineState( &mainProgram, INITIALIZING);
		}

		/* if the player decides to end the game,
		* the state is changed to that state
		*/
		if( decisionSelected == END_GAME)
		{
			setMachineState( &mainProgram, ENDING);
		}

	}while ( isGameStillPlaying( &mainProgram ) ); // if the state is endig, exit the loop
	
}