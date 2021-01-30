/* 

   This example writes a certain amount of bytes to a file, using write().

 */
#define _POSIX_SOURCE
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#undef _POSIX_SOURCE
#include <stdio.h>

#define mega_string_len 1000000

int main() 
{
  	char *mega_string;
  	int  fd, ret;
  	char fn[]="write.file";

  	if ((mega_string = (char*) malloc(mega_string_len)) == NULL)
    		perror("malloc() error");
  	else if ((fd = creat(fn, S_IWUSR)) < 0)
    		perror("creat() error");
  	else 
	{
    		memset(mega_string, '0', mega_string_len);
    		if ((ret = write(fd, mega_string, mega_string_len)) == -1)
      		perror("write() error");
    		else 
			printf("write() wrote %d bytes\n", ret);
    		close(fd);
    		unlink(fn);
  	}
}

/*
Output 
write() wrote 1000000 bytes
*/