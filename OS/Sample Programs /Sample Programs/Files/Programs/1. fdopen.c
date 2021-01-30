#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
 
int main() 
{
  	char fn[]="fdopen.file";
  	FILE *stream;
  	int  fd;
 
  	if ((fd = creat(fn, S_IWUSR)) < 0)
    		perror("creat() error");
  	else 
	{
    		if ((stream = fdopen(fd, "w")) == NULL) 
		{
      			perror("fdopen() error");
      			close(fd);
    		}
    		else 	
		{
      			fputs("This is a test", stream);
      			fclose(stream);
    		}
    		unlink(fn);
  	}
}
