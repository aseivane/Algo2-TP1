#include "Game.h"

void initGame( Game * game)
{
    // asign boards
    game->state = NOT_STARTED;
    game->actualBoard = &(game->board1);
    game->auxBoard = &(game->board2);

    initStatistics( &(game->statistics) );

    initBoard( game->actualBoard );
    initBoard( game->auxBoard );
}

void setInitialCells( Game * game, int initialCells )
{
    setAliveCells( &(game->statistics), initialCells );
}

void playRound( Game * game )
{
    
    static const int maxRows = getMaxRows( game->actualBoard);
    static const int maxCols = getMaxColumns( game->actualBoard);
    int aliveNeighbours;

    clearLastRoundStat( &(game->statistics) );

    // run through the matrix looking for changes
    for( int rowIndex; rowIndex < maxRows ; rowIndex++)
    {
        for( int colIndex; colIndex < maxRows ; colIndex++)
        {
            // get the alive neighbours of the cell to decide the future of the cell
            aliveNeighbours = getAliveNeighbours( game->actualBoard, rowIndex, colIndex);

            // what happens if it's alive?
            if ( cellIsAlive( game->actualBoard, rowIndex, colIndex ) )
            {
                // ok, it's alive. Should we kill it?
                if( cellShouldDie( aliveNeighbours ) ) 
                {
                    // kill the cell
                    killCell( game, rowIndex, colIndex );

                    //add it to the statistics
                    newDeathStat( &(game->statistics) );
                }
            }
            // if it's not alive, is dead
            else
            {   
                // there is no life in here. Should it born out of the blue?
                if( cellShouldBorn( aliveNeighbours ) ) 
                {
                    // set the cell alive
                    bornCell( game, rowIndex, colIndex ); //push!

                    //add it to the statistics
                    newBornStat( &(game->statistics) );
                }
            }
        }
    }

    // ok every cell has their state. Calculate the statistics
    updateStatistics( &(game->statistics));

    //now the axiliary board is the actual one
    swapBoards( game );
}

/** @brief Return the Satitistics of the game
 *
 *  @param game game typedef that contains the statistics
 *  @return Statistics typedef
 */
Statistics getStatistics( Game * game )
{
    return game->statistics;
}

/** @brief Sets the cell status for the fist round
 *
 *  @param game game typedef containing the board
 *  @param rowIndex y coordinate
 *  @param columnIndex x coordinate
 */
void setAliveCell( Game * game, int rowIndex, int columnIndex )
{
    setCellState( game->actualBoard, rowIndex, columnIndex, ALIVE);
}


static bool cellShouldDie( int aliveNeighbours)
{
    static const int twoNeighbours = 2;
    static const int threeNeighbours = 3;
    // overpopuleted
    if( aliveNeighbours > threeNeighbours) return true;
    // alone
    if( aliveNeighbours < twoNeighbours) return true;

    return false;
}

static bool cellShouldBorn( int aliveNeighbours)
{
    // exactly 3 neighbours
    static const int threeNeighbours = 3;
    if( aliveNeighbours == threeNeighbours) return true;

    return false;
}

static void killCell( Game * game, int rowIndex, int columnIndex )
{
    setCellState( game->auxBoard, rowIndex, columnIndex, DEAD);
}

static void bornCell( Game * game, int rowIndex, int columnIndex )
{
    setCellState( game->auxBoard, rowIndex, columnIndex, ALIVE);
}

static void swapBoards( Game * game )
{
    Board * auxPtr = game->actualBoard;
    game->actualBoard = game->auxBoard;
    game->auxBoard = auxPtr;
}