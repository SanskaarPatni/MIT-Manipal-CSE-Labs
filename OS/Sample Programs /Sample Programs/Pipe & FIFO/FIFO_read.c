/* reading from FIFO . read.c*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
         int fd;
         char buf[5];
         fd = open("pfile", O_RDONLY);
         read(fd, buf, 5);
         close(fd);
         puts(buf);
}

