#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "requires.h"

typedef enum MONTH
{
    DEC = 12, JAN = 1, FEB,
    MAR, APR, MAY,
    JUNE, JULY, AUG,
    SEPT, OCT, NOV
} MONTH;

typedef struct
{
    int day;
    MONTH month;
    int year;
} Date;

typedef struct
{
    char surname[65];
    Date birthday;
} Student;

void PrintStuds(Student *students, int length);

#endif