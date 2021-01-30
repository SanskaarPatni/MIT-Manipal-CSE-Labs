#include<stdio.h>
#include<unistd.h>

int main(void)
{
    	int n, fd[2];
    	pid_t pid;
    	char line[100];

    	if ((pid = fork()) < 0) 
	{
        	perror("fork error");
    	} 
	else 
		if (pid > 0) 					/* parent */
		{       
        		close(fd[0]);
        		write(fd[1], "hello world\n", 12);
    		} 
		else 						/* child */
		{                
        		close(fd[1]);
        		n = read(fd[0], line, MAXLINE);
        		write(STDOUT_FILENO, line, n);
    		}
}
