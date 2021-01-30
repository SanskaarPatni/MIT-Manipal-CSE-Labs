#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
sem_t mutex, writerbolock;
int readcount = 0, data = 0;

void *reader(void *arg)
{
    int f = (int)arg;
    sem_wait(&mutex);
    readcount += 1;
    //ek saath sab readers readd karenge
    if (readcount == 1)
        sem_wait(&writerbolock);
    sem_post(&mutex);
    //Reading is performed
    printf("Data read by user %d is %d \n", f, data);
    sleep(2);
    sem_wait(&mutex);
    readcount -= 1;
    if (readcount == 0)
    {
        sem_post(&writerbolock);
    }
    sem_post(&mutex);
}

void *writer(void *arg)
{
    int f = (int)arg;
    sem_wait(&writerbolock);
    data++;
    printf("Data written by writer %d is %d \n", f, data);
    sem_post(&writerbolock);
}
int main()
{
    int i, b;
    pthread_t rtid[10], wtid[10];
    sem_init(&mutex, 0, 1);
    sem_init(&writerbolock, 0, 1);
    printf("Input Data amount: ");
    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        //passing the user id to the function
        pthread_create(&wtid[i], NULL, writer, (void *)i);
        pthread_create(&rtid[i], NULL, reader, (void *)i);
    }
    for (i = 0; i < n; i++)
    {
        pthread_join(wtid[i], NULL);
        pthread_join(rtid[i], NULL);
    }
    printf("\n");
    return 0;
}
