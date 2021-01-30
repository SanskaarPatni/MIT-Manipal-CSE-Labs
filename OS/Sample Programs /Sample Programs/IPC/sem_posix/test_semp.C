	#include <stdio.h>
	#include <sys/stat.h>
	#include <semaphore.h>

	int main() 

	{

	sem_t *semp = sem_open("/sem.0", O_CREAT, S_IRWXU, 1);

	if (semp==(sem_t*)-1) 			{ perror("sem_open"); return -1; }

	if (sem_wait(semp)==-1) 			perror("sem_wait");

	if (sem_post(semp)==-1) 			perror("sem_post");

	if (sem_close(semp)==-1) 			perror("sem_close");

	if (sem_unlink("/sem.0") == -1) 			perror("sem_unlink");

	return 0;

	}
