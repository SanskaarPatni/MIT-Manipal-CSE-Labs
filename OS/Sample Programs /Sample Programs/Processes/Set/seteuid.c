#define _POSIX1_SOURCE 2
#include <unistd.h>
#include <stdio.h>

int main() 
{
  	printf("your effective user id is %d\n", (int) geteuid());
  	if (seteuid(25) != 0)
    		perror("seteuid() error");
  	else
    		printf("your effective user id was changed to %d\n",(int) geteuid());
}
/*
Output

your effective user id is 0
your effective user id was changed to 25*/
