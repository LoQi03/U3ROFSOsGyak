#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int id1 = fork();
    if(id1 == 0)
    {
        /*Első gyerek*/
        int id2 = fork();
        if(id2 == 0)
        {
            /*Masoidik gyerek*/
            int id3=fork();
            if(id3 == 0)
            {
                /*Harmadik gyerek*/
                printf("A harmadik gyerek(%d) vagyok várok 3 secet!\n",getpid());
                sleep(3);
            }
            else
            {
                /*Harmadik szülő*/
                int status;
                if(waitpid(id3,&status,0) == -1)
                {
                    perror("waitpid failed");
                    return EXIT_FAILURE;
                }
                if( WIFEXITED(status))
                {
                    printf("A harmadik szülő vagyok, mivel meghalt a gyerekem (%d) ezért megölöm magam!\n",id3);
                }
            }
            printf("A második gyerek(%d) vagyok várok 3 secet!\n",getpid());
            sleep(3);    
        }
        else
        {
            /*Masoidik szülő*/
            int id3=fork();
            if(id3 == 0)
            {
                /*Harmadik gyerek*/
                printf("A harmadik gyerek(%d) vagyok várok 3 secet!\n",getpid());
                sleep(3);
            }
            else
            {
                /*Harmadik szülő*/
                int status;
                if(waitpid(id3,&status,0) == -1)
                {
                    perror("waitpid failed");
                    return EXIT_FAILURE;
                }
                if(WIFEXITED(status))
                {
                   printf("A harmadik szülő vagyok, mivel meghalt a gyerekem (%d) ezért megölöm magam!\n",id3);
                }
            }
            int status;
            if(waitpid(id2,&status,0) == -1)
            {
                perror("waitpid failed");
                return EXIT_FAILURE;
            }
            if( WIFEXITED(status))
            {
                printf("A második szülő vagyok, mivel meghalt a gyerekem (%d) ezért megölöm magam!\n",id2);
            }
        }
        printf("Az első gyerek(%d) vagyok várok 3 secet!\n",getpid());
        sleep(3); 
    }
    else
    {
        /*Első szülő*/
        int id2 = fork();
        if(id2 == 0)
        {
            /*Masoidik gyerek*/
            int id3=fork();
            if(id3 == 0)
            {
                /*Harmadik gyerek*/
                printf("A harmadik gyerek(%d) vagyok várok 3 secet!\n",getpid());
                sleep(3);
            }
            else
            {
                /*Harmadik szülő*/
                int status;
                if(waitpid(id3,&status,0) == -1)
                {
                    perror("waitpid failed");
                    return EXIT_FAILURE;
                }
                if( WIFEXITED(status))
                {
                    printf("A harmadik szülő vagyok, mivel meghalt a gyerekem (%d) ezért megölöm magam!\n",id3);
                }
            }
            printf("A második gyerek(%d) vagyok várok 3 secet!\n",getpid());
            sleep(3);
        }
        else
        {
             /*Masoidik szülő*/
            int id3=fork();
            if(id3 == 0)
            {
                /*Harmadik gyerek*/
                printf("A harmadik gyerek(%d) vagyok várok 3 secet!\n",getpid());
                sleep(3);
            }
            else
            {
                /*Harmadik szülő*/
                int status;
                if(waitpid(id3,&status,0) == -1)
                {
                    perror("waitpid failed");
                    return EXIT_FAILURE;
                }
                if( WIFEXITED(status))
                {
                    printf("A harmadik szülő vagyok, mivel meghalt a gyerekem (%d) ezért megölöm magam!\n",id3);
                }
            }
            int status;
            if(waitpid(id2,&status,0) == -1)
            {
                perror("waitpid failed");
                return EXIT_FAILURE;
            }
            if( WIFEXITED(status))
            {
                printf("A második szülő vagyok, mivel meghalt a gyerekem (%d) ezért megölöm magam!\n",id2);
            }
        }
        int status;
        if(waitpid(id1,&status,0) == -1)
        {
            perror("waitpid failed");
            return EXIT_FAILURE;
        }
        if( WIFEXITED(status))
        {
            printf("Az első szülő vagyok, mivel meghalt a gyerekem (%d) ezért megölöm magam!\n",id1);
        }
    }
        
}