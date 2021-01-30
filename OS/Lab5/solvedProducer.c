#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <limits.h>
// #define FIFO_NAME "/home/student/180905134/OS/Lab5/fifo.txt"
#define FIFO_NAME "/home/sanskaar/180905134-OS/Lab5/fifosolved"
#define BUFFER_SIZE 80
#define TEN_MEG 1024 * 1024 * 10

int main()
{
    int pipe_fd;
    int res;
    int open_mode = O_WRONLY;
    int bytes_sent = 0;
    char buffer[BUFFER_SIZE + 1];
    if (access(FIFO_NAME, F_OK) == -1)
    {
        res = mkfifo(FIFO_NAME, 0777);
        if (res != 0)
        {
            fprintf(stderr, "Could not create fifo");
            exit(EXIT_FAILURE);
        }
    }
    printf("Process %d opening FIFO O_WRONLY\n", getpid());
    pipe_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), pipe_fd);
    if (pipe_fd != -1)
    {
        while (1)
        {
            //printf("Im the mf empty %s", buffer);
            scanf("%s", &buffer);
            res = write(pipe_fd, buffer, strlen(buffer) + 1);
            buffer[0] = '\0';
            if (res == -1)
            {
                fprintf(stderr, "Write error on pipe\n");
                exit(EXIT_FAILURE);
            }
            bytes_sent += res;
        }
        close(pipe_fd);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    printf("Process %d  finished\n", getpid());
    exit(EXIT_SUCCESS);
}