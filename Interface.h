#ifndef INTERFACE_H_
#define INTERFACE_H

#include "Game.h"

void initialScreen();
int askAmountOfAliveCells();
int askRowIndex();
int askColumnIndex();
int askNextStep();
void printGameScreen( Game * game );
void printBoard( Board * board );
void printStatistics( Statistics * statistics );

#endif