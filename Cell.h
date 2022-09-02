#ifndef MAIN_H_
#define MAIN_H_

enum CellState {
    Live,
    Dead
};

typedef struct {
    CellState state;
} Cell ;


void initCell(Cell * cell);
void setState(Cell * cell, CellState newState);
CellState getState(Cell * cell);
#endif