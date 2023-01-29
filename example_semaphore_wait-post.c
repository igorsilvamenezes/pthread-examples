#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

sem_t mySemaphore;

void *thread1_func(void *arg)
{
    printf("Thread 1 waiting for semaphore\n");
    sem_wait(&mySemaphore);
    printf("Thread 1 acquired semaphore\n");
    sleep(1);
    printf("Thread 1 releasing semaphore\n");
    sem_post(&mySemaphore);
    pthread_exit(NULL);
}

void *thread2_func(void *arg)
{
    printf("Thread 2 waiting for semaphore\n");
    sem_wait(&mySemaphore);
    printf("Thread 2 acquired semaphore\n");
    sleep(1);
    printf("Thread 2 releasing semaphore\n");
    sem_post(&mySemaphore);
    pthread_exit(NULL);
}

int main()
{
    sem_init(&mySemaphore, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread1_func, NULL);
    pthread_create(&thread2, NULL, thread2_func, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    sem_destroy(&mySemaphore);
    return 0;
}