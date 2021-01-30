#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *function(void *param)
{
    int *arr = (int *)param;
    int n = arr[0];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t thread;
    int n = atoi(argv[1]);
    int *arr = (int *)malloc((n) * sizeof(int));
    arr[0] = n;

    pthread_create(&thread, 0, &function, (void *)arr);
    pthread_join(thread, 0);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
