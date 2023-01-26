#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *print_hello(void *arg)
{
    while(1){
        printf("Hello world!\n");
        sleep(1);
    }

    return NULL;
}

int main()
{
    pthread_t thread;
    int status = pthread_create(&thread, NULL, print_hello, NULL);
    if(status != 0){
        printf("Error creating thread\n");
        return 1;
    }
    sleep(5);
    pthread_cancel(thread);
    pthread_join(thread, NULL);
    printf("Thread finished\n");
    return 0;
}