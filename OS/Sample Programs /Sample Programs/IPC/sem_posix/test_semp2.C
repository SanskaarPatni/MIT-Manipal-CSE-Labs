	#include <iostream.h>
	#include <stdio.h>
	#include <malloc.h>
	#include <semaphore.h>

	int main() {
	int val;

	sem_t *semp = (sem_t*)malloc(sizeof(sem_t));

	if (!semp) { perror("malloc"); return 1; }

	if (sem_init (semp, 0, 1 )==-1) { perror("sem_init"); return 2; }

	if (sem_getvalue(semp, &val)==0) 

		cout << "semaphore value: " << val << endl;

	if (sem_destroy(semp) == -1) perror("sem_destroy");

	return 0;

	}
