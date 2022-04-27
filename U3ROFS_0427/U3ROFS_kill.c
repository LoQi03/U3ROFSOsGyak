/* F�jln�v: mutex-takarito.c
   Feladata a mutex-creator.c �ltal k�sz�tett szemafor t�rl�se.
   K�sz�tette: dr. Vad�sz D�nes
   D�tum: 2006. febru�r
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 6666
#define PERM 00666

int main() {

        int id; 		

	if ((id = semget(KEY, 1, 0)) < 0) { 
		perror(" Mar nem letezik a szemafor. ");
		exit(-1);
	}

	if (semctl(id, 0, IPC_RMID, 0) < 0) {
		perror(" Nem sikerullt torolni.");
		exit(-1);
	}

	puts(" A szemafort megsz�ntett�k. \n");
	exit(0);
}

