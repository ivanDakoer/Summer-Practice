#include "student.h"

int main(int argc, char *argv[])
{
    int n, i, k;
    Student *studs;
    const char *fileName = "students.txt";
    FILE *file;
    if ((file = fopen(fileName, "rt")) == NULL) 
    {
        printf("Cant't find file.!");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d\n", &n);

    studs = (Student *) malloc(n * _TSTUDENT_);
    if (studs == NULL) exit(EXIT_FAILURE);

    while (!feof(file))
    {
        fscanf(file, "%s ", studs[i].surname);
        fscanf(file, "%d %d %d\n", &studs[i].birthday.day,
            &studs[i].birthday.month, &studs[i].birthday.year);
        i++;
    }

    fclose(file);

    PrintStuds(studs, n);

    Student *summerStuds = calloc(n, _TSTUDENT_);

    for (i = 0, k = 0; i < n; i++)
    {
        if (JUNE <= studs[i].birthday.month && studs[i].birthday.month <= AUG)
        {
            summerStuds[k++] = studs[i];
        }
    }

    summerStuds = (Student *) realloc(summerStuds, k * sizeof(Student));
    if (summerStuds == NULL) return EXIT_FAILURE;


    char tmp[255];

    for (i = 0; i < k; i++)
    {
        for (int j = 0; j < k - i - 1; j++)
        {
            if (strcmp(summerStuds[j].surname, summerStuds[j + 1].surname) > 0)
            {
                Student tmp = summerStuds[j];
                summerStuds[j] = summerStuds[j + 1];
                summerStuds[j + 1] = tmp;
            }
        }
    }


    PrintStuds(summerStuds, k);
 
    return EXIT_SUCCESS;
}