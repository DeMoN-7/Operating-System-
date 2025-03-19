#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<stdlib.h>
#include<unistd.h>

sem_t mutex;
void child_task(){
    sem_wait(&mutex); //lock
    printf("Child process %d acquired lock\n",getpid());
    sleep(2);
    printf("Child process %d releasing lock.\n",getpid());
    sem_post(&mutex);  // Unlock
    exit(0);
}

int main(){
    // Initialize semaphore
    if (sem_init(&mutex, 0, 1))
    {
        perror("sem_init failed");
        return 1;
    }

    pid_t pid;

    for (int i = 0; i < 4; i++) {  // Creating multiple child processes
        pid = fork();

        if (pid < 0) {
            printf("Fork failed.\n");
            return 1;
        } 
        else if (pid == 0) {  
            // Child process
            child_task();
        }
        else
        {
            wait (NULL);
        }
    }



    // Destroy semaphore
    sem_destroy(&mutex);

return 0;


}