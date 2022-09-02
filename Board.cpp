#include "Board.h"

void initBoard(Board * board, int row, int column)
{
    setCellState(board, row, column, LIVE);
}

int getMaxColumns(Board * board)
{
    return board->maxColumn;
}

int getMaxRows(Board * board)
{
    return board->maxRow;
}

void setCellState(Board * board, int row, int column, CellState newState)
{
    Cell * recivedCell = &(board->grid[row][column]);
    setState( recivedCell , newState);
}

CellState getCellState(Board * board, int row, int column)
{
    Cell * recivedCell = &(board->grid[row][column]);
    getState( recivedCell );
}

bool isValidPosition(Board * board, int row, int column)
{
    if( row < board->maxRow && column < board->maxColumn)
    {
        return true;
    }
    else
    {
        return false;
    }
}