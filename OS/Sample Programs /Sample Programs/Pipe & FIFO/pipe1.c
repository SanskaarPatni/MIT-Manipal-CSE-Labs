/* This example creates an I/O channel. The output shows the data written into one end and read from the other. */

#define _POSIX_SOURCE
#include <unistd.h>
#include <stdio.h>

void reverse(char *s) 
{
  	char *first, *last, temp;

  	first = s;
  	last = s+strlen(s)-1;
  	while (first != last) 
	{
    		temp = *first;
    		*(first++) = *last;
    		*(last--) = temp;
  	}
}

int main() 
{
  	char original[]="This is the original string";
  	char buf[80];
  	int p1[2], p2[2];

  	if (pipe(p1) != 0)
    		perror("first pipe() failed");
  	else 
		if (pipe(p2) != 0)
    			perror("second pipe() failed");
  		else 
			if (fork() == 0) 
			{
    				close(p1[1]);
    				close(p2[0]);
    				if (read(p1[0], buf, sizeof(buf)) == -1)
      					perror("read() error in parent");
    				else 
				{
      					reverse(buf);
      					if (write(p2[1], buf, strlen(buf)+1) == -1)
        					perror("write() error in child");
    				}
    				exit(0);
  			}
  			else 
			{
    				close(p1[0]);
    				close(p2[1]);
    				printf("parent is writing '%s' to pipe 1\n", original);
    				if (write(p1[1], original, strlen(original)+1) == -1)
      					perror("write() error in parent");
    				else 
					if (read(p2[0], buf, sizeof(buf)) == -1)
      						perror("read() error in parent");
    					else 
						printf("parent read '%s' from pipe 2\n", buf);
  			}
}

/*
Output

parent is writing 'This is the original string' to pipe 1
parent read 'gnirts lanigiro eht si sihT' from pipe 2

*/