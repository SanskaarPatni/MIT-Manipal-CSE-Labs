#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int buff[5], f = 0, r = -1;
sem_t mutex, full, empty;
void *produce(void *arg)
{
    int i;
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&empty);
        sem_wait(&mutex);
        printf("Produced item is %d\n", i);
        buff[(++r) % 5] = i;
        sleep(1);//this sleep is important
        sem_post(&mutex);
        sem_post(&full);
        // sleep(1); is comment ko hatadenge toh alternate produce consume
        // printf(" Producer full %u\n", full);
    }
}
void *consume(void *arg)
{
    int item, i;
    for (int i = 0; i < 10; i++)
    {
        sem_wait(&full);
        // printf("Consumer full %u\n", full);
        sem_wait(&mutex);
        item = buff[(f++) % 5];
        printf("Consumed item is %d\n", item);
        sleep(1);//this sleep is important
        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main()
{
    pthread_t threads[2];
    sem_init(&mutex, 0, 1);
    sem_init(&full, 0, 0);
    sem_init(&empty, 0, 5);
    pthread_create(&threads[0], 0, produce, 0);
    pthread_create(&threads[1], 0, consume, 0);
    pthread_join(threads[0], 0);
    pthread_join(threads[1], 0);
}
