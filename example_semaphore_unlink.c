#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    sem_t *mySemaphore;
    mySemaphore = sem_open("mySemaphore", O_CREAT   , 0644, 1);
    if(mySemaphore == SEM_FAILED){
        printf("Error opening semaphore.\n");
        return 1;
    }
    //do something with semaphore
    //..
    //Unlink the semaphore
    sem_unlink("mySemaphore");
    return 0;
}