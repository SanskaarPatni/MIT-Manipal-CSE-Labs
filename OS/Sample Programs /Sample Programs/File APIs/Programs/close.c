#define _POSIX_SOURCE
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() 
{
  	int fd;
  	char out[20]="Test string";
  	if ((fd = creat("./myfile", S_IRUSR | S_IWUSR)) < 0)
    		perror("creat error");
  	else 	
	{
    		if (write(fd, out, strlen(out)+1) == -1)
    			perror("write() error");

	    	if (fd = 0) perror("write() error");
    			close(fd);
  	}
}
