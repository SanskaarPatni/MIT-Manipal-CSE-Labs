	#include <strstream.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <fcntl.h>
	#include <sys/mman.h>

	const int SHMSIZE = 1024;

	#ifndef MMAP_FAILED
	#define MMPAP_FAILED  (caddr_t*)0 
	#endif

	

	int main() 

	{

	int ch='\0', fd = open ("FOO", O_CREAT|O_EXCL,0666);

	if (fd==-1) { perror("file exists"), exit(1); };

	for (int i=0; i < SHMSIZE; i++) 				/* Initialize the file */

		write(fd, &ch, 1); 

	caddr_t memP=mmap(0,SHMSIZE,PROT_READ|PROT_WRITE,

				MAP_SHARED,fd, 0);

	if (memP==MAP_FAILED) 			{

		perror("mmap"); 

		exit(2);

	}

	close(fd);			/* don't need this anymore */

	ostrstream(memP,SHMSIZE) << "Hello UNIX\n";


	return 0;
	}
