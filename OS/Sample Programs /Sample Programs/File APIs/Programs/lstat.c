#define _POSIX_SOURCE
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>
#include <time.h>

int main() 
{
	char fn[]="temp.file", ln[]="temp.link";
  	struct stat info;
  	int fd;

  	if ((fd = creat(fn, S_IWUSR)) < 0)
    		perror("creat() error");
  	else 
	{
    		close(fd);
    		if (link(fn, ln) != 0)
      			perror("link() error");
    		else 
		{
      			if (lstat(ln, &info) != 0)
        			perror("lstat() error");
      			else 
			{
        			puts("lstat() returned:");
        			printf("  inode:   %d\n",   (int) info.st_ino);
        			printf(" dev id:   %d\n",   (int) info.st_dev);
        			printf("   mode:   %08x\n",       info.st_mode);
        			printf("  links:   %d\n",         info.st_nlink);
        			printf("    uid:   %d\n",   (int) info.st_uid);
        			printf("    gid:   %d\n",   (int) info.st_gid);
        			printf("created:   %s",           ctime(&info.st_createtime));
      			}
      			unlink(ln);
    		}
    		unlink(fn);
  	}
}

/*
Output
lstat() returned:
  inode:   3022
 dev id:   1
   mode:   03000080
  links:   2
    uid:   25
    gid:   500
created:   Fri Jun 16 15:00:00 2001
*/