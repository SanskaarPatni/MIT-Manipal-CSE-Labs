/* 

   This example illustrates one use of fcntl().
   The example will compile only with C/MVS.

 */
#define _POSIX_SOURCE
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#undef _POSIX_SOURCE
#include <signal.h>
#include <stdio.h>

void catcher(int signum) 
{
  	puts("inside catcher...");
}

int main() 
{
  	int p[2], flags;
  	struct sigaction sact;
  	char c;

  	if (pipe(p) != 0)
    		perror("pipe() error");
  	else 
	{
    		sigemptyset(&sact.sa_mask);
    		sact.sa_flags = 0;
    		sact.sa_handler = catcher;
    		sigaction(SIGALRM, &sact, NULL);

    		alarm(10);

    		if (read(p[0], &c, 1) == -1)
      		perror("first read() failed");

    		if ((flags = fcntl(p[0], F_GETFL)) == -1)
      		perror("first fcntl() failed");
    		else if (fcntl(p[0], F_SETFL, flags | O_NONBLOCK) == -1)
      		perror("second fcntl() failed");
    		else 
		{
      		alarm(10);

      		if (read(p[0], &c, 1) == -1)
        			perror("second read() failed");

      		alarm(0);
    		}
    		close(p[0]);
    		close(p[1]);
  	}
}
/*
Output 
inside catcher...
first read() failed: Interrupted function call
second read() failed: Resource temporarily unavailable
Sockets example: 
#define _OPEN_SYS
int s;
int rc;
int flags;

•
•
•

/* Place the socket into nonblocking mode */
rc = fcntl(s, F_SETFL, FNDELAY);

/* See if asynchronous notification is set */
flags = fcntl(s, F_GETFL, 0);
if (flags & FNDELAY)
   /* it is set */
else
   /* it is not */
*/