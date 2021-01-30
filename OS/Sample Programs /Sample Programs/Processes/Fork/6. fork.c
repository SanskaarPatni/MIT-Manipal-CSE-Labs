/* forkEx1.c */
#include <stdio.h>

main()
{
   int fpid; 
   printf("Before forking ...\n");
   fpid = fork();
   if (fpid == 0) {
      printf("Child Process fpid=%d\n", fpid);
   } else {
      printf("Parent Process fpid=%d\n", fpid); 
   }
   printf("After forking fpid=%d\n", fpid);   
}
