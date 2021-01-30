#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int status;
    pid_t pid;
    printf("Fork program starting..\n");
    pid = fork();
    if (pid == -1)
    {
        perror("Fork Failed");
        exit(1);
    }
    else if (pid == 0)
    {
        execl("/bin/ls", "ls", "-l", NULL);
    }
    else
    {
        wait(NULL);
        printf("Child complete");
        exit(0);
    }
}