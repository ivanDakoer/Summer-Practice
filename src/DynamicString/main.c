#include "requires.h"

int main()
{
    char tmp[BUFSIZ];
    
    fgets(tmp, sizeof tmp, stdin);

    char *str = (char *) malloc(sizeof tmp + 1);

    

    return EXIT_SUCCESS;
}