#include <pthread.h>
#include <stdio.h>

//Declare a mutex
pthread_mutex_t my_mutex;

int main()
{
    int ret;

    //Initialize the mutex
    ret = pthread_mutex_init(&my_mutex, NULL);
    if(ret != 0){
        printf("Error initializing mutex\n");
        return -1;
    }

    //Destroy the mutrex
    pthread_mutex_destroy(&my_mutex);

    return 0;
}