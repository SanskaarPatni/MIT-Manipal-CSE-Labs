#define _POSIX_SOURCE
#include <errno.h>
#include <stdio.h>

int main() 
{
  	FILE *stream;
  	char my_file[]="my.file";

  	printf("fileno(stdin) = %d\n", fileno(stdin));
	printf("fileno(stdout) = %d\n", fileno(stdout));
	printf("fileno(stderr) = %d\n", fileno(stderr));

  	if ((stream = fopen(my_file, "w")) == NULL)
    		perror("fopen() error");
  	else 
	{
    		printf("fileno() of the file is %d\n", fileno(stream));
    		fclose(stream);
    		remove(my_file);
  	}
}
