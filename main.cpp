#include <iostream>
#include "StateMachine.h"

using namespace std;

void main() 
{
	StateMachine mainProgram;

	init(&mainProgram);

	if( isGameStillPlaying( &mainProgram ))
	{
		run( &mainProgram );
	}
}