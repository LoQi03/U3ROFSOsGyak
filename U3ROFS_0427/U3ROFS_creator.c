#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 6666
#define PERM 00666

int main( ) {
int id; 
 
	if ((id = semget(KEY, 1, 0)) < 0) { 
		if ((id = semget(KEY, 1, PERM | IPC_CREAT)) < 0) {
		 	perror(" A szemafor nem nyithato meg. ");
			exit(-1);
		}
	}
	else    {
		perror(" Mar letezik a szemafor. ");
		exit(0);
	}

	if (semctl(id, 0, SETVAL, 1) < 0) {
		perror(" Nem lehetett inicializalni. ");
	} else {
		puts(" Kész is inicializalt a szemafor. ");
	}

	exit(0);
}

