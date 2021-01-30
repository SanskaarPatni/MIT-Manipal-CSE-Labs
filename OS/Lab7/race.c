#include <pthread.h>
#include <stdio.h>

volatile int counter = 0;

void *count(void *param)
{
    counter++;
    printf("%d\n", counter);
}
int main()
{
    pthread_t thread1, thread2;
    pthread_create(&thread1, 0, count, 0);
    pthread_create(&thread2, 0, count, 0);
    pthread_join(thread1, 0);
    pthread_join(thread2, 0);
    return 0;
}