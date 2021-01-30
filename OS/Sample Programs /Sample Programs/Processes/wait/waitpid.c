#define _POSIX_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

main() 
{
  	pid_t pid;
  	time_t t;
  	int status;

  	if ((pid = fork()) < 0)
    		perror("fork() error");
  	else if (pid == 0) 
	{
    		sleep(5);
    		exit(1);
  	}
  	else do 
	{
    		if ((pid = waitpid(pid, &status, WNOHANG)) == -1)
      			perror("wait() error");
    		else if (pid == 0) 
		{
      			time(&t);
      			printf("child is still running at %s", ctime(&t));
      			sleep(1);
    		}
    		else 
		{
      			if (WIFEXITED(status))
        			printf("child exited with status of %d\n", WEXITSTATUS(status));
      			else 
				puts("child did not exit successfully");
    		}
  	} 
	while (pid == 0);
}

/*
Output

child is still running at Fri Jun 16 11:05:43 2001
child is still running at Fri Jun 16 11:05:44 2001
child is still running at Fri Jun 16 11:05:45 2001
child is still running at Fri Jun 16 11:05:46 2001
child is still running at Fri Jun 16 11:05:47 2001
child is still running at Fri Jun 16 11:05:48 2001
child is still running at Fri Jun 16 11:05:49 2001
child exited with status of 1*/