#include <semaphore.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    sem_t *mySemaphore;
    //Open the semaphore with value 1
    mySemaphore = sem_open("mySemaphore", O_CREAT, 0644, 1);
    if(mySemaphore == SEM_FAILED){
        printf("Error opening semaphore.\n");
        return 1;
    }
    printf("Semaphore opened successfully.\n");
    //close the semaphore
    sem_close(mySemaphore);
    return 0;
}