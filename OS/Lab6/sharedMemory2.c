#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ALPHABET 'd'
int main(int argc, char *argv[])
{
    pid_t cpid;
    int shmid;
    void *shared_memory = (void *)0;
    char *ptr, ch;
    shmid = shmget((key_t)1234, sizeof(char), 0666 | IPC_CREAT);
    // if (shmid == -1)
    // {
    //     ​perror("shmget");
    //     exit(EXIT_FAILURE);
    // }
    shared_memory = shmat(shmid, (void *)-0, 0);
    // if (shared_memory == (void *)-1)
    // {
    //     ​perror("shmat");
    //     exit(EXIT_FAILURE);
    // }
    ptr = (char *)shared_memory;
    cpid = fork();
    // if (cpid == -1)
    // {
    //     ​perror("fork");
    //     exit(EXIT_FAILURE);
    // }
    if (cpid == 0)
    {
        *ptr = '\0';
        while (*ptr == '\0')
            ;
        ch = *ptr;
        switch (ch)
        {
        case 'z':
            *ptr = 'a';
            break;
        case 'Z':
            *ptr = 'A';
            break;
        default:
            *ptr = ch + 1;
        }
        exit(EXIT_SUCCESS);
    }
    else
    {
        while (*ptr != '\0')
            ;
        *ptr = ALPHABET;
        printf("Message from parent:%c\n", ALPHABET);
        while (*ptr == ALPHABET)
            ;
        printf("Reply from child:%c\n", *ptr);
        exit(EXIT_SUCCESS);
    }
}