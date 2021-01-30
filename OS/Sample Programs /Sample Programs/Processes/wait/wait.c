#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
main()
{
   int fpid, status; 
   printf("Before forking ...\n");
   fpid = fork();
   if (fpid == 0) {
      printf("Child Process fpid=%d pid=%d ppid=%d\n", 
				fpid, getpid(), getppid());
   } else {
      printf("Parent Process fpid=%d pid=%d ppid=%d\n", 
				fpid, getpid(), getppid());
   }
   wait(&status);
   printf("After forking fpid=%d pid=%d ppid=%d\n", 
				fpid, getpid(), getppid());
}
