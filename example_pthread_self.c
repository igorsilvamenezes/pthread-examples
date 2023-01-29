#include <pthread.h>
#include <stdio.h>

void *print_hello(void *args)
{
    printf("Hello world. Greetings from thread %ld\n", (long)pthread_self());
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;
    pthread_create(&thread, NULL, print_hello, NULL);
    pthread_exit(NULL);
}