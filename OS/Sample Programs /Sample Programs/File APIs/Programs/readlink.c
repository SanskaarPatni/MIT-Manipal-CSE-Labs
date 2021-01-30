#define _POSIX_SOURCE 1
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#undef _POSIX_SOURCE

int main() 
{
  	char fn[]="readlink.file";
  	char sl[]="readlink.symlink";
  	char buf[30];
  	int  fd;

  	if ((fd = creat(fn, S_IWUSR)) < 0)
    		perror("creat() error");
  	else 
	{
    		close(fd);
    		if (symlink(fn, sl) != 0)
      			perror("symlink() error");
    		else 
		{
      			if (readlink(sl, buf, sizeof(buf)) < 0)
        			perror("readlink() error");
      			else 
				printf("readlink() returned '%s' for '%s'\n", buf, sl);

      			unlink(sl);
    		}
    		unlink(fn);
  	}
}


/*Output
readlink() returned 'readlink.file' for 'readlink.symlink'
*/