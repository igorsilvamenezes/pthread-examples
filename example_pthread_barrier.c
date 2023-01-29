#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_barrier_t barrier;

void *thread1_func(void *arg)
{
    printf("Thread 1 processing for 7 seconds.\n");
    sleep(7);
    printf("Thread 1 done processing, wait for barrier.\n");
    pthread_barrier_wait(&barrier);
    printf("Thread 1 finished.\n");
    return NULL;
}

void *thread2_func(void *arg)
{
    printf("Thread 2 processing for 3 seconds.\n");
    sleep(3);
    printf("Thread 2 done processing, wait for barrier.\n");
    pthread_barrier_wait(&barrier);
    printf("Thread 2 finished.\n");
    return NULL;
}

void *thread3_func(void *args)
{
    printf("Thread 3 processing for 5 seconds.\n");
    sleep(5);
    printf("Thread 3 done processing, wait for barrier.\n");
    pthread_barrier_wait(&barrier);
    printf("Thread 3 finished.\n");
    return NULL;
}

int main()
{
    pthread_t thread1_handle;
    pthread_t thread2_handle;
    pthread_t thread3_handle;

    pthread_barrier_init(&barrier, NULL, 3);

    pthread_create(&thread1_handle, NULL, thread1_func, NULL);
    pthread_create(&thread2_handle, NULL, thread2_func, NULL);
    pthread_create(&thread3_handle, NULL, thread3_func, NULL);

    pthread_join(thread1_handle, NULL);
    pthread_join(thread2_handle, NULL);
    pthread_join(thread3_handle, NULL);

    pthread_barrier_destroy(&barrier);

    printf("All threads completed processing.\n");
    return 0;
}