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

bool isAlive(Cell * cell)
{
    if ( ALIVE == cell->state) return true;
    if ( DEAD == cell->state) return false;
}