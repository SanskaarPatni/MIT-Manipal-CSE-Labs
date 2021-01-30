#define _POSIX_SOURCE
#include <errno.h>
#include <stdio.h>

int main() 
{
  	FILE *stream;
  	char hfs_file[]="./hfs_file", mvs_ds[]="//mvs.ds";

  	printf("fileno(stdin) = %d\n", fileno(stdin));

  	if ((stream = fopen(hfs_file, "w")) == NULL)
    		perror("fopen() error for HFS file");
  	else 
	{
    		printf("fileno() of the HFS file is %d\n", fileno(stream));
    		fclose(stream);
    		remove(hfs_file);
  	}

  	if ((stream = fopen(mvs_ds, "w")) == NULL)
    		perror("fopen() error for MVS data set");
  	else 
	{
    		errno = 0;
    		printf("fileno() returned %d for MVS data set,\n",fileno(stream));
    		printf(" errno=%s\n", strerror(errno));
    		fclose(stream);
    		remove(mvs_ds);
  	}
}
