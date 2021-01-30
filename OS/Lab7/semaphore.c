#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

sem_t semaphore;
int a;
void *func1(void *param)
{
    sem_getvalue(&semaphore, &a);
    printf("Before Post Thread 1 %d\n", a);
    sem_post(&semaphore);
    sem_getvalue(&semaphore, &a);
    printf("After Post Thread 1 %d\n", a);
}

void *func2(void *param)
{
    sem_getvalue(&semaphore, &a);
    printf("Before wait Thread 2 %d\n", a);
    sem_wait(&semaphore);
    sem_getvalue(&semaphore, &a);
    printf("After wait Thread 2 %d\n", a);
}

int main()
{
    pthread_t threads[2];
    sem_init(&semaphore, 0, 1);
    pthread_create(&threads[0], 0, func1, 0);
    pthread_create(&threads[1], 0, func2, 0);
    pthread_join(threads[0], 0);
    pthread_join(threads[1], 0);
    sem_destroy(&semaphore);
}