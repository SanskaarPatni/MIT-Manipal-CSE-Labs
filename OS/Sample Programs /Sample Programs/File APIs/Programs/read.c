/* 

   This example opens a file and reads input.

 */
#define _POSIX_SOURCE
#include <fcntl.h>
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>

int main() 
{
  	int ret, fd;
  	char buf[1024];

  	system("ls -l / >| ls.output");

  	if ((fd = open("ls.output", O_RDONLY)) < 0)
    		perror("open() error");
  	else 
	{
    		while ((ret = read(fd, buf, sizeof(buf)-1)) > 0) 
		{
      		buf[ret] = 0x00;
      		printf("block read: \n<%s>\n", buf);
    		}
    		close(fd);
  	}

  	unlink("ls.output");
}

/*
Output 
block read:
<total 0
drwxr-xr-x   3 USER1    SYS1           0 Apr 16 07:59 bin
drwxr-xr-x   2 USER1    SYS1           0 Apr  6 10:20 dev
drwxr-xr-x   4 USER1    SYS1           0 Apr 16 07:59 etc
drwxr-xr-x   2 USER1    SYS1           0 Apr  6 10:15 lib
drwxrwxrwx   2 USER1    SYS1           0 Apr 16 07:55 tmp
drwxr-xr-x   2 USER1    SYS1           0 Apr  6 10:15 u
drwxr-xr-x   6 USER1    SYS1           0 Apr  6 10:15 usr
>*/
c