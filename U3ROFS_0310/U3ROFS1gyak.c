#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
    if(!system("dir"))
    {
        for(int i =0; i < 3; i++)
        {
            printf("KORTE!\n");
        }
    }
    system("color a");
    system("Nincs ilyen parancs");
    return 0;
}
