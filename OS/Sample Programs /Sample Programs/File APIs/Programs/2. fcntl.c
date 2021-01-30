/* Fcntl, locking files*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define PACKAGE "crlock"

int main(void) 
{
 	int fd = 0;
 	int i = 5;

 	for(; i > 0; i--) 
	{
  		if((fd = open("locked.file", O_RDWR|O_CREAT|O_EXCL, 0444)) == -1) 
		{
   			fprintf(stderr, "%s [%d]: Error - file already locked ...\n", PACKAGE, getpid());
   			sleep(1);
  		} 
		else 
		{
   			fprintf(stdout, "%s [%d]: Now I am the only one with access :-)\n", PACKAGE, getpid());
   			sleep(1);
   			close(fd);
   			unlink("locked.file");
   			sleep(1);
  		} /* else */
 	} /* while */
 	return 0;
}
