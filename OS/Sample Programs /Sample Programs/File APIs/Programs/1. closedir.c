#define _POSIX_SOURCE
#include <dirent.h>
#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdio.h>

int main() 
{
  	DIR *dir;
  	struct dirent *entry;
  	int count;

  	if ((dir = opendir("/")) == NULL)
    		perror("opendir() error");
  	else 
	{
	    	count = 0;
    		while ((entry = readdir(dir)) != NULL) 
     			printf("directory entry %03d: %s\n", ++count, entry->d_name);
     		closedir(dir);
  	}
}

