#include "student.h"

int main()
{
    int n = 0;
    int i, k;
    Student *studs;
    FILE *file;

    if ((file = fopen("../src/Students/students.txt", "rt")) == NULL) 
    {
        printf("Cant't find file.!");
        return EXIT_FAILURE;
    }

    fscanf(file, "%d\n", &n);

    studs = (Student *) calloc(n, sizeof(Student));
    if (studs == NULL) return EXIT_FAILURE;

    i = 0;
    while (!feof(file))
    {
        fscanf(file, "%s", studs[i].surname);
        fscanf(file, "%d %d %d", &studs[i].birthday.day,
            &studs[i].birthday.month, &studs[i].birthday.year);
        i++;
    }

    fclose(file);

    PrintStuds(studs, n);

    Student *summerStuds = calloc(n, sizeof(Student));

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