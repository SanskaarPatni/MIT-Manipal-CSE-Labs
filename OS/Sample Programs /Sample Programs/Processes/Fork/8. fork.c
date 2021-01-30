/* forkEx2.c */
#include <stdio.h>

main()
{
   int fpid; 
   printf("Before forking ...\n");
   system("ps");
   fpid = fork();
   system("ps");
   printf("After forking 
		fpid=%d\n", fpid);
}