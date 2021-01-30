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
    int fd;
    char arr[80];
    int num = 0;
    char numString[5];
    int res;
    if (access(FIFO_NAME, F_OK) == -1)
    {
        res = mkfifo(FIFO_NAME, 0777);
        if (res != 0)
        {
            fprintf(stderr, "Could not create fifo");
            exit(EXIT_FAILURE);
        }
    }
    fd = open(FIFO_NAME, O_WRONLY);
    if (fd != -1)
    {
        while (1)
        {
            printf("Enter set of 4 integers\n");
            for (int i = 0; i < 4; i++)
            {
                scanf("%d", &num);
                sprintf(numString, "%d", num);
                strncat(arr, " ", 1);
                strcat(arr, numString);
            }
            write(fd, arr, strlen(arr) + 1);
            arr[0] = '\0';
        }
        close(fd);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    printf("Process %d  finished\n", getpid());
    exit(EXIT_SUCCESS);
}