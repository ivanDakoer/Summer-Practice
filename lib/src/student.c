#include "student.h"

void PrintStuds(Student *students, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%s %d %d %d\n", students[i].surname, 
            students[i].birthday.day, 
            students[i].birthday.month, 
            students[i].birthday.year);
    }
    printf("\n");
}