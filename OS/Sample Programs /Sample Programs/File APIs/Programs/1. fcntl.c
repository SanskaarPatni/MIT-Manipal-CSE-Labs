/*Locking and Unlocking a File

The following example demonstrates how to place a lock on bytes 100 to 109 of a file and then later remove it. F_SETLK is used to perform a non-blocking lock request so that the process does not have to wait if an incompatible lock is held by another process; instead the process can take some other action.*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


int main(int argc, char *argv[])
{
   	int fd;
    	struct flock fl;


    	fd = open("testfile", O_RDWR);
    	if (fd == -1)        /* Handle error *//* Make a non-blocking request to place a write lock on bytes 100-109 of testfile */


		fl.l_type = F_WRLCK;
    		fl.l_whence = SEEK_SET;
    		fl.l_start = 100;
    		fl.l_len = 10;

    	if (fcntl(fd, F_SETLK, &fl) == -1) 
	{
        	if (errno == EACCES || errno == EAGAIN) 
		{
            		printf("Already locked by another process\n");   /* We can't get the lock at the moment */
        	} 
		else 
		{
            		/* Handle unexpected error */;
        	}
    	} 
	else 
	{ 
		/* Lock was granted... */
       		/* Perform I/O on bytes 100 to 109 of file */
   		/* Unlock the locked bytes */


        	fl.l_type = F_UNLCK;
        	fl.l_whence = SEEK_SET;
        	fl.l_start = 100;
        	fl.l_len = 10;
        	if (fcntl(fd, F_SETLK, &fl) == -1)	/* Handle error */;
	}
    	exit(EXIT_SUCCESS);
} /* main */
