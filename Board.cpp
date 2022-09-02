#include "Board.h"

/** @brief initialize board
 *
 *  @param board pointer to Board typedef
 *  @param row y coordinates
 *  @param column x coordinate
 */
void initBoard(Board * board, int row, int column)
{
    setCellState(board, row, column, ALIVE);
}

/** @brief Returns the columns of the grid
 *
 *  @param board pointer to Board typedef
 *  @return int maxColumn
 */
int getMaxColumns(Board * board)
{
    return board->maxColumn;
}

/** @brief Returns the rows of the grid
 *
 *  @param board pointer to Board typedef
 *  @return -
 */
int getMaxRows(Board * board)
{
    return board->maxRow;
}

/** @brief Returns the message fields in a given matrix.
 *
 *  @param board pointer to Board typedef
 *  @param row y coordinates
 *  @param column x coordinate
 *  @param newState new state to set
 *  @return -
 */
void setCellState(Board * board, int row, int column, CellState newState)
{
    Cell * recivedCell = &(board->grid[row][column]);
    setState( recivedCell , newState);
}

/** @brief Returns the message fields in a given matrix.
 *
 *  @param board pointer to Board typedef
 *  @param row y coordinates
 *  @param column x coordinate
 *  @return cell
 */
CellState getCellState(Board * board, int row, int column)
{
    Cell * recivedCell = &(board->grid[row][column]);
    return getState( recivedCell );
}

/** @brief Returns the message fields in a given matrix.
 *
 *  @param board pointer to Board typedef
 *  @param row y coordinates
 *  @param column x coordinate
 *  @return -
 */
bool isValidPosition(Board * board, int row, int column)
{
    if( row <= board->maxRow && column <= board->maxColumn)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/** @brief Returns the message fields in a given matrix.
 *
 *  @param ptrMessage pointer to the start of the message.
 *  @param ptrTalker pointer to the talker from wich get the message.
 *  @param fieldsArray matrix to copy the values
 *  @return -
 */
int getNeighbourCount(Board * board, int row, int column)
{
    // aux variables
    int aliveCount = 0;
    Cell * ptrCurrentCell;

    //run throgh the matrix 
    for( int rowIndex = row - 1 ; rowIndex <= row + 1; rowIndex++)
    {
        for( int columnIndex = column - 1 ; columnIndex <= column + 1; columnIndex++)
        {
            // if the position is within the limits of the matrix, check if its alive
            if( isValidPosition(board, rowIndex, columnIndex) )
            {
                ptrCurrentCell = &(board->grid[rowIndex][columnIndex]);
                if( isAlive( ptrCurrentCell ) )
                    aliveCount++;
            }
        }
    }

    //if the center cell is alive, substract from the total cont
    ptrCurrentCell = &(board->grid[row][column]);

    if( isAlive( ptrCurrentCell) )
        aliveCount--;
    
    return aliveCount;
}