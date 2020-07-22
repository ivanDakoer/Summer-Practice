#include "mystring.h"


int main()
{
    char str[BUFSIZ];
    fgets(str, sizeof str, stdin);


    int count = countSymbol(str, 'a');

    printf("count of a = %d\n", count);

    strlenWords(str);
    
    return EXIT_SUCCESS;
}