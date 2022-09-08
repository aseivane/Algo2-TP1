#ifndef STATISTICS_H_
#define STATISTICS_H_

typedef struct {
    int aliveCells;
    int lastRoundNewbornCells;
    int lastRoundDeadCells;
    int avgBorns;
    int avgDeaths;
    int round;
} Statistics;

void initStatistics( Statistics * statistics);
void updateStatistics( Statistics * statistics);
void clearLastRoundStat( Statistics * statistics );
void setAliveCells( Statistics * statistics, int initialCells );
void newDeathStat( Statistics * statistics );
void newBornStat( Statistics * statistics );

#endif