#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
pthread_mutexattr_t attr;

int main()
{
    //Initialize the mutex attribute object
    pthread_mutexattr_init(&attr);

    //Set the mutex type to be a recursive mutex
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);

    //Initialize the mutex with the attribute
    pthread_mutex_init(&mutex, &attr);

    //Use the mutex as needed

    //Destroy the attribute object
    pthread_mutexattr_destroy(&attr);

    //Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}