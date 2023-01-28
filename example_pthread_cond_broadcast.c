#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_cond_t cond;
pthread_mutex_t mutex;
int shared_variable = 0;

void *check_odd()
{
    while(1){
        pthread_mutex_lock(&mutex); //acquire lock
        if(shared_variable % 2 == 1){
            printf("Thread 1: shared_variable is odd: %d\n", shared_variable);            
        }
        pthread_cond_wait(&cond, &mutex); //Wait for the broadcast signal            
        pthread_mutex_unlock(&mutex); //Release the lock
    }
    return NULL;
}

void *check_even()
{
    while(1){
        pthread_mutex_lock(&mutex); //acquire lock        
        if(shared_variable % 2 == 0){
            printf("Thread 2: shared_variable is even: %d\n", shared_variable);            
        }
        pthread_cond_wait(&cond, &mutex); //Wait for the broadcast signals            
        pthread_mutex_unlock(&mutex); //Release the lock
    }
    return NULL;
}

void *increment_and_broadcast()
{
    while(1){
        pthread_mutex_lock(&mutex); //Acquire the lock
        shared_variable++;
        pthread_cond_broadcast(&cond); //Send the broadcast signal
        pthread_mutex_unlock(&mutex); //Release th lock
        sleep(1); //Introduce a delay of 1 second
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2, thread3;

    pthread_cond_init(&cond, NULL); //Initialize the condition variable
    pthread_mutex_init(&mutex, NULL); //Inicialize the mutex

    pthread_create(&thread1, NULL, check_odd, NULL);
    pthread_create(&thread2, NULL, check_even, NULL);
    pthread_create(&thread3, NULL, increment_and_broadcast, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    pthread_cond_destroy(&cond); //Destroy the condition variable
    pthread_mutex_destroy(&mutex); //Destroy the mutex

    return 0;
}