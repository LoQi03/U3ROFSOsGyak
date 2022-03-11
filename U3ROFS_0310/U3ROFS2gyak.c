#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char *par;
    char q;
    do
    {
        printf("Kerek egy parancsot: ");
        scanf("%s",par);
        system(par);
        puts(par);
        scanf("%c",&q);
        printf("%c",q);
    }
    while(!(q=='n'));
    return 0;
}
