#include <pthread.h>
#include <stdio.h>

int shared_variable = 0;
pthread_mutex_t lock;

void *thread1_function(){
    while(1){
        pthread_mutex_lock(&lock); //Acquire lock before accessing shared variable
        shared_variable++; //Incremant shared variable
        printf("Thread 1: shared_variable = %d\n", shared_variable);
        pthread_mutex_unlock(&lock); //Release lock after accessing shared variable
    }
    pthread_exit(NULL);    
}

void *thread2_function(){
    while(1){
        pthread_mutex_lock(&lock); //Acquire lock before accessing shared variable
        shared_variable--; //Decrement shared variable
        printf("Thread 2: shared_variable = %d\n", shared_variable); //Release lock after accessing shared variable
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL); //Initialize mutex

    //Create two threads
    pthread_create(&thread1, NULL, thread1_function, NULL);
    pthread_create(&thread2, NULL, thread2_function, NULL);

    //Wait fot threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_exit(NULL);
}