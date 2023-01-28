#include <pthread.h>
#include <stdio.h>

pthread_cond_t cond; //declare a condition variable
pthread_mutex_t mutex; //declare a mutex
int shared_variable = 0; //shared variable

void *thread1_function()
{
    while(1){
        pthread_mutex_lock(&mutex); //acquire lock

        while(shared_variable <=0){
            pthread_cond_wait(&cond, &mutex); //wait for condition
        }
        shared_variable--; //decrement shared variable
        printf("Thread 1: shared_variable = %d\n", shared_variable);

        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(0);
}

void *thread2_function()
{
    while(1){
        pthread_mutex_lock(&mutex); //acquire lock

        shared_variable++; //increment shared variable
        printf("thread 2: shared_variable = %d\n", shared_variable);
        pthread_cond_signal(&cond); //signal the condition variable

        pthread_mutex_unlock(&mutex); //release lock
    }
    pthread_exit(0);
}

int main()
{
    pthread_t thread1, thread2; //declare threads
    pthread_cond_init(&cond, NULL); //initialize the condition variable
    pthread_mutex_init(&mutex, NULL); //initialize the mutex

    //create threads
    pthread_create(&thread1, NULL, thread1_function, NULL);
    pthread_create(&thread2, NULL, thread2_function, NULL);

    //wait for threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    //destroy the condition variable and mutex
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);

    return 0;
}