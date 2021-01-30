#define _POSIX_SOURCE
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int g=6;


int main()
{
	int var;
	pid_t pid;

	var=88;
	printf("Before fork()\n");

	if((pid=fork()) < 0)
		perror("fork() error");
	else
		if(pid==0)
		{
			g++;
			var++;		
		}
		else
		{
			sleep(2);
		}
	printf("pid = %d, global variable = %d, Variable = %d\n",getpid(),g,var);
	exit(0);
}
