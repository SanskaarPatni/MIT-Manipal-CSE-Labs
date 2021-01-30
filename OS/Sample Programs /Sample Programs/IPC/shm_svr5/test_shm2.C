	#include <iostream.h>

	#include <stdio.h>

	#include <unistd.h>

	#include <sys/ipc.h>

	#include <sys/shm.h>

	int main()

	{

	struct shmid_ds sbuf;

	int fd = shmget (100, 1024, 0);

	if (fd>0 && shmctl(fd, IPC_STAT,&sbuf)) 					{

	cout << "shared memory size if: " << sbuf.shm_segsz << endl;

	sbuf.shm_perm.uid = getuid(); 				// change owner user-ID

	if (shmctl(fd,IPC_SET,&sbuf)==-1) perror("shmctl");

	} 

	else perror("shmctl");

	if (shmctl(fd,IPC_RMID,0)) perror("shmctl - IPC_RMID");

	return 0;

	}
