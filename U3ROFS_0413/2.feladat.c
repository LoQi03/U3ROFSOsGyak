#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
     int pipefd[2];	// 2 eleme tomb, mert ket vege lesz a csonek, ezert ket valtozo neki
     pid_t cpid;	// gyerkoc pidje lesz benne
     char buf;		// bufferke
     char szoveg[32];	// masik buffer a kuldendo szovegnek
     int ret;

     if (pipe(pipefd) == -1) {	// krealunk csovezeteket, es a ket fd a pipefd-ben lesz tarolva
	   perror("pipe");
	   exit(-1);
     }

     printf("%d: fd1: %d, fd2: %d\n",getpid(),pipefd[0],pipefd[1]);

     cpid = fork();
     if (cpid == -1) {
	   perror("fork");
	   exit(-1);
     }

     if (cpid == 0) {   
         /* gyerek vagyok */
        printf("%d: szulo vagyok\n",getpid());

   	   close(pipefd[0]);    /* itt meg az olvaso veget csukjuk le, mert irni fogunk */

	   strcpy(szoveg,"ez itt kerem egy szoveg\0");   // feltoltom a buffert a kuldeni kivant stringgel
	   printf("%d: kuldom a szoveget: %s:%d\n",getpid(),szoveg,strlen(szoveg));

	   write(pipefd[1], szoveg, strlen(szoveg));	// ontunk anyagot a csobe

	   close(pipefd[1]);    /* lecsukom a csatorna fedelet, a masik oldalon EOF lesz */

	   wait(NULL);    /* varjunk gyerekre */

	   exit(0); 

     } else {	/* szulo vagyok */

	   printf("%d: gyerek vagyok\n",getpid());
	   close(pipefd[1]);    /* a gyerek csak olvasni fog, ezert az iras fd-t le is csukom */

	   printf("%d: megnezem mi van a csoben\n%d: ",getpid(),getpid());
	   while (read(pipefd[0], &buf, 1) > 0) {	// olvasunk a cso kimeneterol, amig van mit (1 byteonkent)
		 printf("%c",buf);
	   }
	   printf("\n%d:lezartak a cso masik oldalat\n",getpid());

	   close(pipefd[0]);	/* na itt becsukom mar az olvaso veget is */

   	   exit(0);	// kilep
     }
}