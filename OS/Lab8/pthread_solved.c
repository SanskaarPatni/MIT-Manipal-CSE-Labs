#include <pthread.h>
#include <stdio.h>
void *function(void *param)
{
    int id = (int)param;
    printf("Start thread %i\n", id);
    return (void *)id;
    //NO
    // int *id = (int *)param;
    // printf("Start thread %i\n", *id);
    // return (void *)*id;
}

int main(int argc, char const *argv[])
{
    pthread_t thread[10];
    int return_value[10];
    for (int i = 0; i < 10; i++)
    {
        //NO
        //pthread_create(&thread[i], 0, &function, (void *)i);
        pthread_create(&thread[i], 0, &function, (void *)i);
    }
    for (int i = 0; i < 10; i++)
    {
        pthread_join(thread[i], (void **)&return_value[i]);
        printf("End thread %i\n", return_value[i]);
    }

    return 0;
}
