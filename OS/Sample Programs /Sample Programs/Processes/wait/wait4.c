#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
main()
{
   	int fpid, status,var;
   	struct rusage rusage;
   	pid_t pid; 
   	printf("Before forking ...\n");
   	pid = fork();
   	if (pid == 0) 
	{
      	printf("Child Process fpid=%d pid=%d ppid=%d\n", pid, getpid(), getppid());
   	} 
	else 
	{
          	wait4(pid,&status,0,&rusage);   
   		printf("Parent Process fpid=%d pid=%d ppid=%d\n",pid, getpid(), getppid());
   	}

	getrusage(RUSAGE_SELF,&rusage);
	printf("%ld\n%ld\n",rusage.ru_maxrss,rusage.ru_nsignals);
   
   	printf("After forking fpid=%d pid=%d ppid=%d\n", pid, getpid(), getppid());
}
