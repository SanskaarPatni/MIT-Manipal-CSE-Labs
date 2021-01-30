#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define MAX_SIZE 256

typedef struct
{
    int m;
    int n;
    int arr[5][5];
} matrix;

void *matrix_mult(void *param)
{
    //created a pointer to that same structure hence no need to return
    matrix *parameter = (matrix *)param;
    matrix ans;
    ans.m = parameter->n;
    ans.n = (parameter + 1)->m;
    for (int i = 0; i < parameter->n; i++)
    {
        for (int j = 0; j < (parameter + 1)->m; j++)
        {
            ans.arr[i][j] = 0;
            for (int k = 0; k < parameter->m; k++)
            {
                ans.arr[i][j] += parameter->arr[i][k] * (parameter + 1)->arr[k][j];
            }
        }
    }
    return (void *)ans;
}

int main()
{
    matrix matrix_multt[2];
    matrix ans;
    pthread_t thread;
    matrix_multt[0].m = 2;
    matrix_multt[0].n = 2;
    matrix_multt[1].m = 2;
    matrix_multt[1].n = 2;
    for (int i = 0; i < matrix_multt[0].m; i++)
    {
        for (int j = 0; j < matrix_multt[0].n; j++)
        {
            matrix_multt[0].arr[i][j] = 2;
            matrix_multt[1].arr[i][j] = 2;
        }
    }
    pthread_create(&thread, 0, &matrix_mult, (void *)&matrix_multt);
    pthread_join(thread, (void **)&ans);
    for (int i = 0; i < ans.m; i++)
    {
        for (int j = 0; j < ans.n; j++)
        {
            printf("%d\t", ans.arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}