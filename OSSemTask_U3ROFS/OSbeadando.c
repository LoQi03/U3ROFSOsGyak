#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main(){
    int id1, id2;
    int statusz;
    int st;
    id1=fork();
    if(id1==0)
    {
        //a gyerekben vagyok
        int idu1=fork();
        if(idu1==0)
        {
            printf("Várok 3 mp-t %d \n", getpid());
            sleep(3);
        }
        else
        {
        wait(&st);
        }
        int idu2=fork();
        if(idu2==0)
        {
            printf("Várok 3 mp-t %d \n", getpid());
            sleep(3);
        }
        else
        {
        wait(&st);
        }
        int idu3=fork();
        if(idu3==0)
        {
            printf("Várok 3 mp-t %d \n", getpid());
            sleep(3);
        }
        else
        {
        wait(&st);
        }
    }
    else{
        //szülőben vagyok
        int idu1=fork();
        if(idu1==0)
        {
            printf("Várok 3 mp-t %d \n", getpid());
            sleep(3);
        }
        else
        {
        wait(&st);
        }
        int idu2=fork();
        if(idu2==0)
        {
            printf("Várok 3 mp-t %d \n", getpid());
            sleep(3);
        }
        else
        {
        wait(&st);
        }
        int idu3=fork();
        if(idu3==0)
        {
            printf("Várok 3 mp-t %d \n", getpid());
            sleep(3);
        }
        else
        {
        wait(&st);
        }
    }
    return 0;
}