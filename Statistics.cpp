#include "Statistics.h"

/** @brief Inits statistics to value 0
 *
 *  @param statistics
 */
void initStatistics( Statistics * statistics)
{
    statistics->aliveCells = 0;
    statistics->lastRoundNewbornCells = 0;
    statistics->lastRoundDeadCells = 0;
    statistics->avgBorns = 0;
    statistics->avgDeaths = 0;
    statistics->round = 0;
}

/** @brief Update statistics values
 *
 *  @param statistics
 */
void updateStatistics( Statistics * statistics)
{
    const int newBorns = statistics->lastRoundNewbornCells;
    const int newDeaths = statistics->lastRoundDeadCells;
    statistics->aliveCells = statistics->aliveCells + newBorns - newDeaths;

    statistics->round++;
    statistics->avgBorns = (int)(statistics->avgBorns + newBorns)/statistics->round;
    statistics->avgDeaths = (int)(statistics->avgDeaths + newDeaths)/statistics->round;
}

/** @brief Clears last round borns and deaths
 *
 *  @param statistics
 */
void clearLastRoundStat( Statistics * statistics )
{
    statistics->lastRoundDeadCells = 0;
    statistics->lastRoundNewbornCells = 0;
}

/** @brief Configure first round alive cells
 *
 *  @param statistics
 */
void setAliveCells( Statistics * statistics, int initialCells )
{
    statistics->aliveCells = initialCells;
}

/** @brief Increases the deaths in the round
 *
 *  @param statistics
 */
void newDeathStat( Statistics * statistics )
{
    statistics->lastRoundDeadCells++;
}

/** @brief Increases the borns in the round
 *
 *  @param statistics
 */
void newBornStat( Statistics * statistics )
{
    statistics->lastRoundNewbornCells++;
}