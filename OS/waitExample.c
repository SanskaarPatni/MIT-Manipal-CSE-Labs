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
        printf("Im the child");
        printf("Im the child");
        int n = 0;
        while (n < 10)
        {
            n++;
        }
        printf("Im the child");
        exit(0);
    }
    else
    {
        wait(&status);
        printf("Im the parent %d\n", status);
        exit(0);
    }
}
