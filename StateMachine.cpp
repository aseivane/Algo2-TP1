#include "StateMachine.h"
#include "Interface.h"

void init(StateMachine * stateMachine)
{
    stateMachine->currentState = INITIALIZING;
}

void runCycle(StateMachine * stateMachine)
{
    switch (stateMachine->currentState) 
    {
        case INITIALIZING:
            // welcome and declarations befor game starts
            initializingState( stateMachine );
            stateMachine->currentState = REQUESTING_DATA;
        break;

        case REQUESTING_DATA:
            // data reques for initial state of the came
            requestingDataState(stateMachine);
            stateMachine->currentState = PLAYING;
        break;

        case PLAYING:
            // tasks to do on every game round
            playingState(stateMachine);
        break;

        case ENDING:
            break;
    }
}

bool isGameStillPlaying( StateMachine * stateMachine )
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

void initializingState( StateMachine * stateMachine )
{
    initialScreen();
}

static void requestingDataState( StateMachine * stateMachine )
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

static void playingState(StateMachine * stateMachine)
{
    playRound( &(stateMachine->lifeGame) );

    getStatistics( &(stateMachine->lifeGame) );

    printGameScreen( &(stateMachine->lifeGame) );
}

PlayerDecision nextEvent()
{
    int answer = askNextStep();
    PlayerDecision decision;
    switch (answer) 
    {
        case 0:
            decision = PLAY_NEXT_ROUND;
        break;

        case 1:
            decision = RESTART_GAME;
        break;

        case 2:
            decision = END_GAME;
        break;

        default:
            decision = INVALID;
        break;
    }

    return decision;
}
