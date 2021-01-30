#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;
	if((pid=fork())==0)
	{
		perror("fork() : ");
	}
	else if(pid==0)
	{	
		if(execl("/home/visionx/Desktop/Chapter\ 4/interpreter/testinterp","testinterp","asdf","asdfasdf2er", (char *)0) < 0)
			perror("Error : ");
		
	}
	if(waitpid(pid,NULL,0) < 0)
		perror("waitpid error : ");
	exit(0);
}
