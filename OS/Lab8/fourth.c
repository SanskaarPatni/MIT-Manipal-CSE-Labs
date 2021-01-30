#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *sum_odd(void *a)
{
    int *arr = (int *)a;
    int n = arr[0];
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (arr[i] % 2 != 0)
            sum += arr[i];
    }
    return (void *)sum;
}

void *sum_even(void *a)
{
    int *arr = (int *)a;
    int n = arr[0];
    int sum = 0;
    for (int i = 1; i < n + 1; i++)
    {
        if (arr[i] % 2 == 0)
            sum += arr[i];
    }
    return (void *)sum;
}

int main()
{
    int n;
    printf("Enter the size of array:\n");
    scanf("%d", &n);

    int *arr = (int *)malloc(sizeof(int) * (n + 1));
    arr[0] = n;
    printf("Enter %d numbers:\n", n);
    for (int i = 1; i < n + 1; i++)
        scanf("%d", &arr[i]);

    int ans1 = 0, ans2 = 0;
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &sum_odd, (void *)arr);
    pthread_join(thread1, (void **)&ans1);

    pthread_create(&thread2, NULL, &sum_even, (void *)arr);
    pthread_join(thread2, (void **)&ans2);

    printf("Odd numbers sum of array is %d\n", ans1);
    printf("Even numbers sum of array is %d\n", ans2);
    return 0;
}