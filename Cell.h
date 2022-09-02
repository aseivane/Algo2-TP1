#ifndef CELL_H_
#define CELL_H_

enum CellState {
    DEAD,
    ALIVE
};

typedef struct {
    CellState state;
} Cell ;

void initCell(Cell * cell);
void setState(Cell * cell, CellState newState);
CellState getState(Cell * cell);
bool isAlive(Cell * cell);

#endif