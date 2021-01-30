#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void *function(void *param)
{
    int *arr = (int *)param;
    int n = arr[0];
    int sum;
    for (int i = 1; i <= n; i++)
    {
        sum += arr[i];
    }
    return (void *)sum;
}

int main(int argc, char const *argv[])
{
    pthread_t thread;
    int n, sum;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    int *arr = (int *)malloc((n + 1) * sizeof(int));
    arr[0] = n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    pthread_create(&thread, 0, &function, (void *)arr);
    pthread_join(thread, (void **)&sum);
    printf("Sum is %d\n", sum);
    return 0;
}