/* execEx1.c */
#include <stdio.h>
#include <unistd.h>

main()
{
   printf("Before execing ...\n");
   execl("/bin/date", "date", 0);
   printf("After exec\n");   
	exit(10);
}
