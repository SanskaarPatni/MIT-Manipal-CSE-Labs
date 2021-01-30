	#include <iostream.h>

	#include <stdio.h>

	#include <unistd.h>

	#include <sys/ipc.h>

	#include <sys/sem.h>



	union semun {

		int	val;

		struct semid_ds *mbuf;

		ushort *array;

	} arg;



	int main() 

	{

	struct semid_ds mbuf;

	arg.mbuf = &mbuf;

	int fd = semget (100, 0, 0);



	if (fd>0 && semctl(fd,0, IPC_STAT,arg)) 					{

	cout << "#semaphores in the set" << arg.mbuf->sem_nsems<< endl;

	arg.mbuf->sem_perm.uid = getuid(); 				// change owner user-ID

	if (semctl(fd,0,IPC_SET,arg)==-1) perror("semctl");

	} 

	else perror("semctl");

	if (semctl(fd,0,IPC_RMID,0)) perror("semctl - IPC_RMID");

	return 0;

	}
