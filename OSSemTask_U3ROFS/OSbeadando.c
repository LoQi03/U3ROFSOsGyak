#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int id1, id2;
    int statusz;
    int st;
    id1=fork();
    id2=fork();
    if(id1==0)
    {
        printf("A gyerekben vagyok %d\n",getpid());
        int idu1=fork();
        int idu2=fork();
        int idu3=fork();
        if(idu1==0)
        {
            printf("Várok 3 mp-t %d \n", getpid());
            sleep(3);
        }
        if(idu2==0)
        {
            printf("Várok 3 mp-t %d\n", getpid());
            sleep(3);
        }
        if(idu3==0)
        {
            printf("Várok 3 mp-t %d\n",getpid());
            sleep(3);
        }
    }
    else{
        wait(&st);
        wait(&st);
        wait(&st);
    }
    if(id2==0)
    {
        printf("Szülőben vagyok! %d\n", getpid());
        int idu1=fork();
        int idu2=fork();
        int idu3=fork();
        if(idu1==0)
        {
            printf("Várok 3 mp-t  %d\n", getpid());
            sleep(3);
        }
        if(idu2==0)
        {
            printf("Várok 3 mp-t %d\n ", getpid());
            sleep(3);
        }
        if(idu3==0)
        {
            printf("Várok 3 mp-t %d\n", getpid());
            sleep(3);
        }
    }
    else{
        wait(&st);
        wait(&st);
        wait(&st);
    }
    return 0;
}