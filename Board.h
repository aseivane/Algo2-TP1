#ifndef BOARD_H_
#define BOARD_H_

#include "Cell.h"

static const int MAXCOLUMN = 80;
static const int MAXROW = 20;

typedef struct {
    int maxColumn = MAXCOLUMN;
    int maxRow = MAXROW;
    Cell grid[MAXROW][MAXCOLUMN];
} Board;

void initBoard(Board * board, int row, int column);
int getMaxColumns(Board * board);
int getMaxRows(Board * board);
void setCellState( Board * board, CellState newState);
CellState getCellState();
bool isValidPosition();

#endif