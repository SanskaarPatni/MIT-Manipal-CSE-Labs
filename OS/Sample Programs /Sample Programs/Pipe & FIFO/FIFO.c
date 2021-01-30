#define _POSIX_SOURCE
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() 
{
  	char fn[]="temp.fifo";
  	char out[20]="FIFO's are fun!", in[20];
  	int rfd, wfd;

  	if (mkfifo(fn, S_IRWXU) != 0)
    		perror("mkfifo() error");
  	else 
	{
    		if ((rfd = open(fn, O_RDONLY|O_NONBLOCK)) < 0)
      			perror("open() error for read end");
    		else 
		{
      			if ((wfd = open(fn, O_WRONLY)) < 0)
        			perror("open() error for write end");
      			else	 
			{
        			if (write(wfd, out, strlen(out)+1) == -1)
          				perror("write() error");
        			else 
					if (read(rfd, in, sizeof(in)) == -1)
          					perror("read() error");
        				else 
						printf("read '%s' from the FIFO\n", in);
        			close(wfd);
      			}
      			close(rfd);
    		}
    		unlink(fn);
  	}
}

/*
Output

read 'FIFO's are fun!' from the FIFO */
