#include "StateMachine.h"
#include "Interface.h"

void init(StateMachine * stateMachine)
{
    stateMachine->currentState = INITIALIZING;
}

void run(StateMachine * stateMachine)
{
    switch (stateMachine->currentState) 
    {
        case INITIALIZING:
            
        break;

        case REQUESTING_DATA:
        // do something in the stop state
        break;

        case PLAYING:

        break;

        case ENDING:

        break;
    }
}

bool isGameStillPlaying(StateMachine * stateMachine)
{
    if (stateMachine->currentState == ENDING)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

static void initializingState(StateMachine * stateMachine)
{
    int rowIndex = 0;
    int columnIndex = 0;

    //ask for alive cells to place
    int initialCells = askAmountOfAliveCells();

    //the game is initialized
    initGame( &(stateMachine->lifeGame) , initialCells);

    for( initialCells; initialCells > 0; initialCells--)
    {
        //ask coordinate for each cell
        rowIndex = askRowIndex();
        columnIndex = askColumnIndex();

        //set it on the game
        setAliveCell( &(stateMachine->lifeGame), rowIndex, columnIndex );

    }
}