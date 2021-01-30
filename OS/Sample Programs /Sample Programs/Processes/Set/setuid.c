#define _POSIX_SOURCE
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() 
{
  	printf("prior to setuid(), real uid=%d, effective uid=%d\n",(int) getuid(), (int) geteuid());
  	if (setuid(25) != 0)
    		perror("setuid() error");
  	else
    		printf("after setuid(), real uid=%d, effective uid=%d\n",(int) getuid(), (int) geteuid());
//	system("sudo ls -n setuid.c");
}
/*
Output

before setuid(), uid=0, effective uid=0
after setuid(),    uid=25, effective uid=25*/
