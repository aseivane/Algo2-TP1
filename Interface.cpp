#include <iostream>
#include "Interface.h"

using namespace std;

void initialScreen()
{
    cout << "Bienvenido al juego de la vida. El mismo cuenta con un tablero de 80x80" << endl;
}

int askAmountOfAliveCells()
{
    int cells;
    cout << "Cantidad de celulas a configurar:" << endl;
    cin >> cells;
    return cells;
}

int askRowIndex()
{
    int rowIndex;
    cout << "Fila:" << endl;
    cin >> rowIndex;
    return rowIndex;
}
int askColumnIndex()
{
    int colIndex;
    cout << "Columna:" << endl;
    cin >> colIndex;
    return colIndex;
}
int askNextStep()
{
    int nextStep;
    cout << "Seleccione que desea hacer:\n"
        << "1. Ejecutar un turno.\n"
        << "2. Reiniciar el juego.\n"
        << "3. Terminar juego.\n"
        <<endl;
    cin >> nextStep;
    return nextStep;
}

void printBoard( Board * board )
{

}
void printStatistics( Statistics * statistics )
{

}