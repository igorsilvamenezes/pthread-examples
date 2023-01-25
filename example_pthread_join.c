#include <pthread.h>
#include <stdio.h>

void *print_hello(void *arg)
{
    printf("Hello world!\n");

    return NULL;
}

int main()
{
    pthread_t thread;
    int status = pthread_create(&thread, NULL, print_hello, NULL);
    if( status != 0 ){
        printf("Erro creating thread\n");
        return 1;
    }

    pthread_join(thread, NULL);
    printf("Thread finished\n");

    return 0;
}