#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *print_message(void *arg)
{
    printf("Thread starting...\n");
    sleep(5);
    printf("Thread finishing...\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;
    char *message = "Thread 1";

    pthread_create(&thread, NULL, print_message, (void *)message);
    pthread_detach(thread);

    printf("Thread detached, Main function continuing...\n");
    sleep(10);
    printf("Main function finising...\n");

    return 0;
}