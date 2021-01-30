#define _POSIX_SOURCE
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() 
{
  	printf("prior to setuid(), euid=%d, uid=%d, effective uid=%d\n",(int)geteuid, (int) getuid(), (int) geteuid());
	system("sudo ls -n a.out");
  	if (setreuid(25,234) != 0)
    		perror("setuid() error");
  	else
	{
    		printf("after setuid(), euid=%d uid=%d, effective uid=%d\n",(int) geteuid, (int) getuid(), (int) geteuid());
		system("sudo ls -n a.out");	
	}
}
/*
Output

before setuid(), uid=0, effective uid=0
after setuid(),    uid=25, effective uid=25*/
