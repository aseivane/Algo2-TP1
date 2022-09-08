#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "Statistics.h"

typedef struct {
    Board board1;
    Board board2;
    Board * actualBoard;
    Board * auxBoard;
    Statistics statistics;
} Game ;

void initGame( Game * game );
void playRound( Game * game );
// getters
Statistics getStatistics( Game * game );
// setters
void setInitialCells( Game * game, int initialCells );
void setAliveCell( Game * game, int rowIndex, int columnIndex );

/*
static bool cellShouldDie( int aliveNeighbours);
static bool cellShouldBorn( int aliveNeighbours);
static void killCell( Game * game, int rowIndex, int columnIndex );
static void bornCell( Game * game, int rowIndex, int columnIndex );
static void swapBoards( Game * game );
*/
#endif