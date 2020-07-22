#include "sport.h"

static Champion getChampion();

int writeChampions(Champion *datas, FILE *destination)
{
    if (destination == NULL) return 0;

    for (int i = 0; i < MAX_CHAMPIONS; ++i)
    {
        datas[i] = getChampion();
    }

    fwrite(datas, _TCHAMPION_, MAX_CHAMPIONS, destination);
    
    return 1;
}

int readChampions(Champion *datas, FILE *source)
{
    if (source == NULL) return 0;


    fread(datas, _TCHAMPION_, MAX_CHAMPIONS, source);

    for (int i = 0; i < MAX_CHAMPIONS; i++, printf("\n"))
    {
        printf("%s\t", datas[i].surname);
        for (int mark = 0; mark < MAX_COMPETITION; mark++)
        {
            printf("%d ", datas[i].marks[mark]);
        }
    }
}

static Champion getChampion()
{
    static int how_many = 1;

    Champion champ;

    printf("\nChampion #%d:\n", how_many);

    printf("Surname: ");
    fflush(stdin);
    scanf("%s", champ.surname);


    printf("Marks: ");
    for (int i = 0; i < MAX_COMPETITION; ++i)
    {
        scanf("%d", &champ.marks[i]);
    }
    
    champ.totalMark = 0;
    for (int i = 0; i < MAX_COMPETITION; i++)
    {
        champ.totalMark += champ.marks[i];
    }

    how_many++;

    return champ;
}