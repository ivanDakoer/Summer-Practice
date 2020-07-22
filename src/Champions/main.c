// ⦁	Відомі бали, набрані кожним з 20 спортсменів - п'ятиборців у кожному з п'яти видів спорту. Визначити прізвище спортсмена - переможця змагань.

#include "sport.h"

int main()
{
    const char *fileName = "sport.dat";
    const char *outputFile = "winner.txt";

    int choice;
    do {
        printf("\t\t\t1. Input data\n");
        printf("\t\t\t2. Output data\n");
        printf("\t\t\t3. Show Winner\n");
        printf("\t\t\t4. Exit\n\n\n");
        printf("> ");
        scanf("%d", &choice);
        switch (choice)
        {
            case WRITE:
            {
                Champion *chmps = (Champion *) malloc(_TCHAMPION_ * MAX_CHAMPIONS);
                if (chmps == NULL) return EXIT_FAILURE;

                FILE *dest;

                fopen_s(&dest, fileName, "wb");
                if (dest == NULL) return EXIT_FAILURE;
                if (writeChampions(chmps, dest) == 0) return EXIT_FAILURE;
                fclose(dest);

                free(chmps);

                system("cls");
                break;
            }
            case PRINT:
            {
                FILE *src;
                Champion *chmps = (Champion *) malloc(_TCHAMPION_ * MAX_CHAMPIONS);
                if (chmps == NULL) return EXIT_FAILURE;
                
                fopen_s(&src, fileName, "rb");
                if (readChampions(chmps, src) == 0) return EXIT_FAILURE;
                fclose(src);

                free(chmps);

                system("pause");
                system("cls");
                break;
            }
            case WINNER:
            {
                FILE *src;
                Champion *chmps = (Champion *) malloc(_TCHAMPION_ * MAX_CHAMPIONS);
                if (chmps == NULL) return EXIT_FAILURE;
                fopen_s(&src, fileName, "rb");
                readChampions(chmps, src);
                fclose(src);

                Champion winner = chmps[0];

                for (int i = 1; i < MAX_CHAMPIONS; i++)
                {
                    if (winner.totalMark < chmps[i].totalMark)
                        winner = chmps[i];
                }

                printf("Winner: %16s\t%d\n", winner.surname, winner.totalMark);

                FILE *output;
                fopen_s(&output, outputFile, "wt");
                fclose(output);

                free(chmps);

                system("pause");
                system("cls");
                break;
            }
            case EXIT:
            {
                return EXIT_SUCCESS;
            }
        }
    } while (choice != 4);
    
}