#ifndef BOARD_H_
#define BOARD_H_

#include "Cell.h"

static const int MAXCOLUMN = 80;
static const int MAXROW = 20;

typedef struct {
    int maxColumn;
    int maxRow;
    Cell grid[MAXROW][MAXCOLUMN];
    int aliveCells;
} Board;

void initBoard(Board * board);
int getMaxColumns(Board * board);
int getMaxRows(Board * board);
void setCellState(Board * board, int row, int column, CellState newState);
CellState getCellState(Board * board, int row, int column);
bool isValidPosition(Board * board, int row, int column);
int getAliveNeighbours(Board * board, int row, int column);

#endif