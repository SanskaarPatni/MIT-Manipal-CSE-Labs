	#include <stdio.h>

	#include <unistd.h>

	#include <errno.h>

	#include <fcntl.h>

	#include <sys/stat.h>

	#include <semaphore.h>

	#include <sys/mman.h>



	int main() 

	{

		long siz = sizeof(sem_t) + 1024;

		int shmfd = shm_open ("/shm.0", O_CREAT|O_RDWR, S_IRWXU);

		if (shmfd==-1) 		{ perror("shm_open"); return 1; }

		if (ftruncate(shmfd, siz)==-1) 

				{ perror("ftruncate"); return 2; }

		char* memp = (char*)mmap(0, siz, PROT_READ |PROT_WRITE, 

						MAP_SHARED, shmfd, 0L);

	if (!memp) 			{ perror("mmap"); return 3; }

	(void)close(shmfd);

	if (sem_init((sem_t*)memp,1,1) < 0) { perror("sem_init"); return 4; }

	/* do work with the shared memory and semaphore */

	if (sem_destroy((sem_t*)memp) < 0) { perror("sem_destroy"); return 5; }

	if (shm_unlink("/shm.0") < 0) { perror("shm_unlink"); return 6; }

	return munmap( memp, sizeof(sem_t) + 1024);







	}
