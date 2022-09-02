#include "Cell.h"

void initCell(Cell * cell, CellState newState)
{
    setState(cell, newState);
}

void setState(Cell * cell, CellState newState)
{
    cell->state = newState;
}

CellState getState(Cell * cell)
{
    return cell->state;
}