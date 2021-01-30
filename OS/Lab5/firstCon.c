#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#define FIFO_NAME "/home/sanskaar/180905134-OS/Lab5/fifo"
int main()
{
    int fd1;
    // mkfifo(FIFO_NAME, 0666);
    char str[80];
    int res;
    fd1 = open(FIFO_NAME, O_RDONLY);
    if (fd1 != -1)
    {
        res = read(fd1, str, 80);
        do
        {
            printf("Producer sent %s\n", str);
            res = read(fd1, str, 80);
        } while (res > 0);
        close(fd1);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    printf("Process %d  finished\n", getpid());
    exit(EXIT_SUCCESS);
}