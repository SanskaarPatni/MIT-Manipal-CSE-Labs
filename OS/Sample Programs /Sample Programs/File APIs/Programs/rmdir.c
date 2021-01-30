#define _OPEN_SYS
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/stat.h>
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>

int main() 
{
  	char new_dir[]="new_dir";
  	char new_file[]="new_dir/new_file";
  	int  fd;

  	if (mkdir(new_dir, S_IRWXU|S_IRGRP|S_IXGRP) != 0)
    		perror("mkdir() error");
  	else if ((fd = creat(new_file, S_IWUSR)) < 0)
    		perror("creat() error");
  	else 
	{
	    	close(fd);
    		unlink(new_file);
  	}

  	if (rmdir(new_dir) != 0)
    		perror("rmdir() error");
  	else
    		puts("removed!");
}
