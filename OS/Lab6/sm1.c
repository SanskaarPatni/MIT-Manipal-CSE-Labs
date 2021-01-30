#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int main()
{
    // ftok to generate unique key
    key_t key = ftok("shmfile", 65);

    // shmget returns an identifier in shmid
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // shmat to attach to shared memory
    char *str = (char *)shmat(shmid, (void *)0, 0);
    while (1)
    {
        printf("Write Data :\n");
        gets(str);
        printf("Data written in memory: %s\n", str);
        if (strcmp(str, "end") == 0)
        {
            break;
        }
    }
    //detach from shared memory
    shmdt(str);

    return 0;
}
