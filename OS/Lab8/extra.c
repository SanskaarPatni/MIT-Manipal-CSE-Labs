#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 256
struct odd_array
{
    int limit;
    int arr[MAX];
};
void *generate_odd(void *param)
{
    struct odd_array *o = (struct odd_array *)param;
    for (int i = 2; i < 10; i++)
    {
        if (i % 2 != 0)
            o->arr[o->limit++] = i;
    }
    return NULL;
}

int main()
{
    struct odd_array *f;
    f->limit = 0;
    pthread_t thread;
    pthread_create(&thread, 0, *generate_odd, (void *)f);
    pthread_join(thread, 0);
    for (int i = 0; i < f->limit; i++)
    {
        printf("%d ", f->arr[i]);
    }
    printf("\n");
}