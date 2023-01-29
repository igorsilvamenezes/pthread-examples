#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

sem_t mySemaphore;

void * threadFunction(void *arg)
{
    //Wait for the semaphore
    sem_wait(&mySemaphore);
    printf("Thread acquired the semaphore.\n");
    //Do something
    sleep(1);
    printf("Thread is doing something.\n");
    //Release the semaphore
    sem_post(&mySemaphore);
    printf("Thread released the semaphore.\n");
    return NULL;
}

int main()
{
    //Initialize the semaphore with value 1
    sem_init(&mySemaphore, 0, 1);
    pthread_t thread1, thread2;
    //Create the first thread
    pthread_create(&thread1, NULL, threadFunction, NULL);
    //Create the second thread
    pthread_create(&thread2, NULL, threadFunction, NULL);
    //Wait for the first thread to finish
    pthread_join(thread1, NULL);
    //Wait for the second thread to finish
    pthread_join(thread2, NULL);
    int sem_value;
    sem_getvalue(&mySemaphore, &sem_value);
    printf("Semaphore value after all thread finish: %d\n", sem_value);
    //Destroy the semaphore
    sem_destroy(&mySemaphore);
    return 0;
}