	#include <iostream.h>

	#include <stdio.h>
	#include <stdlib.h>

	#include <string.h>

	#include <sys/stat.h>

	#include <sys/ipc.h>

	#include <sys/shm.h>



	int main() 

	{

	int perms = S_IRWXU | S_IRWXG | S_IRWXO;

	int fd = shmget (100, 1024, IPC_CREAT | perms);

	if (fd==-1) perror("shmget"), exit(1);

	char* addr = (char*)shmat(fd, 0, 0);

	if (addr==(char*)-1) perror("shmat"), exit(1);

	strcpy( addr, "Hello");

	if (shmdt(addr)==-1) perror("shmdt");

	return 0;

	}
