#ifndef __STUDENT_H__
#define __STUDENT_H__

#include "requires.h"
#include "mystring.h"

typedef struct
{
    int day, month, year;
} Date;

#define JUNE 6
#define JULY 7
#define AUG  8

typedef struct
{
    char surname[NAME_SIZE];
    Date birthday;
} Student;

#define _TSTUDENT_ sizeof(Student)

void PrintStuds(Student *students, int length);

#endif