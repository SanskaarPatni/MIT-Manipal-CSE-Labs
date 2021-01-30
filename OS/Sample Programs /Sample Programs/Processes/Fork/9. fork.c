/* forkEx3.c */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
main()
{
   int fpid; 
   printf("Before forking ...\n");
   if((fpid = fork())== 0) {
      printf("Child Process fpid=%d pid=%d ppid=%d\n", 
      		fpid, getpid(), getppid());
   } else {
      printf("Parent Process fpid=%d pid=%d ppid=%d\n", 
      		fpid, getpid(), getppid());
   }
   printf("After forking fpid=%d pid=%d ppid=%d\n", 
      		fpid, getpid(), getppid());
}
