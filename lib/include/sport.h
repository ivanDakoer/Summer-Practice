#ifndef __SPORT_H__
#define __SPORT_H__

#include "requires.h"

#define MAX_CHAMPIONS   3

#define MAX_COMPETITION 5

#define WRITE   1
#define PRINT   2 
#define WINNER  3
#define EXIT    4

typedef struct Champion
{
    char surname[NAME_SIZE];
    int marks[MAX_COMPETITION];
    int totalMark;
} Champion;

#define _TCHAMPION_ sizeof(Champion)

int writeChampions(Champion *datas, FILE *destination);

int readChampions(Champion *datas, FILE *source);

#endif 