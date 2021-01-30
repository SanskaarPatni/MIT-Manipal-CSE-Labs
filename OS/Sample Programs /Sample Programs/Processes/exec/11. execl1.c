/* execEx2.c */
#include <sys/types.h>
#include <unistd.h> 
#include <stdio.h>

main()
{
   int fpid;
   printf("Before execing ...\n");
   fpid = fork();
   if (fpid == 0) {
     execl("/bin/date", "date", 0);
   }
   printf("After exec and fpid=%d\n",fpid);   
}
