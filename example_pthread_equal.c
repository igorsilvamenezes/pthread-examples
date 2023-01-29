#include <pthread.h>
#include <stdio.h>

void *print_hello(void *arg)
{
    printf("Hello from thread!\n");
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    //Create two threads
    pthread_create(&thread1, NULL, print_hello, NULL);
    pthread_create(&thread2, NULL, print_hello, NULL);

    //Compare the two threads
    if(pthread_equal(thread1, thread2)){
        printf("thread1 and thread2 are equal.\n");
    } else {
        printf("thread1 and thread2 are not equal!\n");
    }

    //Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}