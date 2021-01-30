#define _POSIX_SOURCE
#include <sys/stat.h>
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>

int main() 
{
  	char new_dir[]="new_dir";

  	if (mkdir(new_dir, S_IRWXU|S_IRGRP|S_IXGRP) != 0)
    		perror("mkdir() error");
  	else if (chdir(new_dir) != 0)
    		perror("first chdir() error");
  	else if (chdir("..") != 0)
    		perror("second chdir() error");
  	else if (rmdir(new_dir) != 0)
    		perror("rmdir() error");
  	else
    		puts("success!");
}
