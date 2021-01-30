#define _POSIX_SOURCE
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() 
{
  	char fn[]="test.file";
  	char sln[]="test.symlink";
  	int fd;

  	if ((fd = creat(fn, S_IWUSR)) < 0)
    		perror("creat() error");
  	else 
	{
    		close(fd);
    		puts("before symlink()");
    		system("ls -il test.*");
    		if (symlink(fn, sln) != 0) 
		{
      			perror("symlink() error");
      			unlink(fn);
    		}
    		else 
		{
      			puts("after symlink()");
      			system("ls -il test.*");
      			unlink(fn);
      			puts("after first unlink()");
      			system("ls -il test.*");
      			unlink(sln);
    		}
  	}
}

/*Output
before symlink()
 4030 --w-------   1 MVSUSR1  SYS1     0 Apr 20 13:57 test.file

after symlink()
 4030 --w-------   1 MVSUSR1  SYS1     0 Apr 20 13:57 test.file
 4031 l---------   1 MVSUSR1  SYS1     9 Apr 20 13:57 test.symlink -> test.file
after first unlink()
 4031 l---------   1 MVSUSR1  SYS1     9 Apr 20 13:57 test.symlink -> test.file
*/