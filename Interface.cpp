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
    cout << "Cantidad de celulas a configurar: ";
    cin >> cells;
    cout << endl;
    return cells;
}

int askRowIndex()
{
    int rowIndex;
    cout << "Fila: ";
    cin >> rowIndex;
    return rowIndex;
}
int askColumnIndex()
{
    int colIndex;
    cout << "Columna: ";
    cin >> colIndex;
    cout  << endl;
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
    static const int maxRows = getMaxRows( board);
    static const int maxCols = getMaxColumns( board);

    // run through the matrix looking for changes
    for( int rowIndex = 0; rowIndex < maxRows ; rowIndex++)
    {
        for( int colIndex = 0; colIndex < maxCols ; colIndex++)
        {
            if( cellIsAlive( board, rowIndex, colIndex ) )
            {
                cout<<1;
            }
            else
            {
                cout<<0;
            }
        }
        cout<<endl;
    }
}

void printStatistics( Statistics * statistics )
{
    cout<<"Celulas vivas: " << statistics->aliveCells<<endl;
    cout<<"Celulas nacidad en el ultimo turno: "<< statistics->lastRoundNewbornCells <<endl;
    cout<<"Celulas muertas en el ultimo turno: "<< statistics->lastRoundDeadCells <<endl;
    cout<<"Promedio de nacimientos: " << statistics->avgBorns << endl;
    cout<<"Promedio de muertes: " << statistics->avgDeaths << endl <<endl;
}