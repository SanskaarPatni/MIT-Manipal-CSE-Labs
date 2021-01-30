/* Write using fifo . write.c*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
main()
{
         int fd;
         fd = open("pfile", O_WRONLY);
         write(fd, "hello", 5);
         close(fd);
}
/*
[test139@cse-lab1-20 fifo_example]$ cc -o rd  read.c
[test139@cse-lab1-20 fifo_example]$ cc -o wr  write.c
[test139@cse-lab1-20 fifo_example]$ ./rd &
[2] 4173
[test139@cse-lab1-20 fifo_example]$ ./wr
hello
[2]-  Exit 7                  ./rd
*/
