#include <pthread.h>
#include <stdio.h>

pthread_mutex_t mutex;
int shared_resource = 0;

void *thread_func(void *arg)
{
    for(int i = 0; i < 1000000; i++){
        pthread_mutex_lock(&mutex);
        shared_resource++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t thread1, thread2;

    int status = pthread_create(&thread1, NULL, thread_func, NULL);
    if(status != 0){
        printf("Error creating thread 1\n");
        return 1;
    }

    status = pthread_create(&thread2, NULL, thread_func, NULL);
    if(status != 0){
        printf("Error creating thread 2\n");
        return 1;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Valor final do recurso compartilhada: %d\n", shared_resource);
    pthread_mutex_destroy(&mutex);
    return 0;
}