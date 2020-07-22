#include "student.h"

void PrintStuds(Student *students, int count)
{
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        printf("%s %d %d %d\n", 
            students[i].surname, 
            students[i].birthday.day, 
            students[i].birthday.month, 
            students[i].birthday.year);
    }
}