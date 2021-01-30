#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define MAX_SIZE 256

typedef struct
{
    int m;
    int n;
    int p;
    int q;
    int arr1[5][5];
    int arr2[5][5];
    int ans[5][5];
} matrix;

void *matrix_mult(void *param)
{
    //created a pointer to that same structure hence no need to return
    matrix *parameter = (matrix *)param;

    for (int i = 0; i < parameter->n; i++)
    {
        for (int j = 0; j < parameter->p; j++)
        {
            parameter->ans[i][j] = 0;
            for (int k = 0; k < parameter->p; k++)
            {
                parameter->ans[i][j] += parameter->arr1[i][k] * parameter->arr2[k][j];
            }
        }
    }
    return NULL;
}

int main()
{
    matrix matrix_multt;
    pthread_t thread;
    matrix_multt.m = 2;
    matrix_multt.n = 2;
    matrix_multt.p = 2;
    matrix_multt.q = 2;
    for (int i = 0; i < matrix_multt.m; i++)
    {
        for (int j = 0; j < matrix_multt.n; j++)
        {
            matrix_multt.arr1[i][j] = 2;
            matrix_multt.arr2[i][j] = 2;
        }
    }
    pthread_create(&thread, 0, &matrix_mult, (void *)&matrix_multt);
    pthread_join(thread, 0);
    for (int i = 0; i < matrix_multt.m; i++)
    {
        for (int j = 0; j < matrix_multt.n; j++)
        {
            printf("%d\t", matrix_multt.ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}