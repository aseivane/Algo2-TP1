#include "StateMachine.h"
#include "Interface.h"


/** @brief Initial state. It shows a welcome screen an inits the game typedef
 *          and whats inside it.
 *
 *  @param stateMachine StateMachine pointer
 */
static void initializingState( StateMachine * stateMachine )
{
    initialScreen();

    //the game is initialized
    initGame( &(stateMachine->lifeGame) );
}

/** @brief Input data state. The player enters the amount of alive cells
 *          that are going to be placed initialy and the position of each one.
 *
 *  @param stateMachine StateMachine pointer
 */
static void requestingDataState( StateMachine * stateMachine )
{
    int rowIndex = 0;
    int columnIndex = 0;
 
    //ask for alive cells to place
    int initialCells = askAmountOfAliveCells();

    setInitialCells( &(stateMachine->lifeGame), initialCells);

    for( initialCells; initialCells > 0; initialCells--)
    {
        //ask coordinate for each cell
        rowIndex = askRowIndex();
        columnIndex = askColumnIndex();

        //set it on the game
        setAliveCell( &(stateMachine->lifeGame), rowIndex, columnIndex );
    }
}

/** @brief Playing state. The game runs all the changes in one round according
 *          to the game rules.
 *
 *  @param stateMachine StateMachine pointer
 */
static void playingState(StateMachine * stateMachine)
{
    Game * ptrGame = &(stateMachine->lifeGame);
    playRound( ptrGame );

    //getStatistics( ptrGame );

    printBoard( ptrGame->actualBoard );

    printStatistics( &(ptrGame->statistics) );
}

/** @brief Initialize the state machine with INITIALIZING state
 *
 *  @param stateMachine StateMachine pointer
 */
void init(StateMachine * stateMachine)
{
    stateMachine->currentState = INITIALIZING;
}

/** @brief Runs throgh the state chart and executes the code inside the correspondig state
 *
 *  @param stateMachine StateMachine pointer
 */
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

/** @brief Initialize the state machine with INITIALIZING state
 *
 *  @param stateMachine StateMachine pointer
 *  @return returns true or false answare of the questino
 */
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

/** @brief The player is asked to decide if he/she wants to continue
 *          the game, restart it or end it.
 *
 *  @param -
 *  @return PlayerDecision
 */
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

void setMachineState(StateMachine * stateMachine, MachineState newState)
{
    stateMachine->currentState = newState;
}