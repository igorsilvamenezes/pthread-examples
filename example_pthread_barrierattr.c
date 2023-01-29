#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 3
#define NUM_SEG_SLEEP 3

pthread_barrier_t myBarrier;
pthread_barrierattr_t myBarrierAttr;

void *thread_function(void *arg)
{
    int thread_id = *((int *) arg);
    printf("Thread %d starting processing...\n", thread_id);
    sleep( NUM_SEG_SLEEP + thread_id); //simulate different processing times
    printf("Thread %d finished processing.\n", thread_id);

    int ret = pthread_barrier_wait(&myBarrier);
    if(ret == PTHREAD_BARRIER_SERIAL_THREAD)
        printf("Thread %d is the last thread arriving at the barrier.\n", thread_id);

    printf("Thread %d passed the barrier.\n", thread_id);        
}

int main()
{
    int thread_ids[NUM_THREADS];
    int pshared;
    pthread_t threads[NUM_THREADS];

    pthread_barrier_init(&myBarrier, &myBarrierAttr, NUM_THREADS);

    pthread_barrierattr_getpshared(&myBarrierAttr, &pshared);
    printf("Barrier initial sharing type: %d\n", pshared);

    pthread_barrierattr_setpshared(&myBarrierAttr, PTHREAD_PROCESS_SHARED);

    pthread_barrierattr_getpshared(&myBarrierAttr, &pshared);
    printf("Barrier new sharing type: %d\n", pshared);

    for(int i = 0; i< NUM_THREADS; i++)
    {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_barrier_destroy(&myBarrier);
    pthread_barrierattr_destroy(&myBarrierAttr);

    printf("All threads completed processing.\n");
    return 0;
}