#ifndef GAME_H_
#define GAME_H_

#include "Board.h"
#include "Statistics.h"

enum GameState {
    FINISHED,
    PLAYING,
    NOT_STARTED
};

typedef struct {
    GameState state;
    Board board1;
    Board board2;
    Board * actualBoard;
    Board * auxBoard;
    Statistics statistics;
} Game ;

void initGame( Game * game );
void playRound( Game * game );
Statistics getStatistics( Game * game );
void setInitialCells( Game * game, int initialCells );
void setAliveCell( Game * game, int rowIndex, int columnIndex );

static bool cellShouldDie( int aliveNeighbours);
static bool cellShouldBorn( int aliveNeighbours);


#endif