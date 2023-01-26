#include <pthread.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void *myThreadFunction(void *args)
{
    while(1){
        printf("Running...\n");
        sleep(1);
    }
    return NULL;
}

int main()
{
    pthread_t thread;
    int sig = SIGINT;
    int ret;

    pthread_create(&thread, NULL, myThreadFunction, NULL);

    sleep(5); //wait for 5 seconds before sending the signal

    ret = pthread_kill(thread, sig);
    if(ret != 0){
        printf("Error: pthread_kill returned %d\n", ret);
    }

    pthread_join(thread, NULL); //wait for thread to finish
    printf("Thread finished\n");

    return 0;
}