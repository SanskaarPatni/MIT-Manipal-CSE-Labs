#define _POSIX_SOURCE 1
#include <unistd.h>
#include <stdio.h>

int main() 
{
  	printf("real group id is %d\neffective group id is %d\n", (int) getgid(),(int)getegid());
  	if (setgid(0) != 0)
    		perror("setgid() error");
  	else
    		printf("real group id was changed to %d\neffective group id was changed to %d\n",(int) getgid(), (int) getegid());
}

