#include "forkpattern.h"
#include <sys/wait.h>

void pattern1 (int numberOfThings) { 
    for (int ix = 0; ix < numberOfThings; ix++) {
        int id = fork(); 

        if (id == 0) {  
            printf("Parent: created child %d (PID: %d)\n", ix + 1, getpid());

            int sleepTime = rand() % 8 + 1;  
            printf("Process %d (PID: %d) created: will sleep for %d seconds\n", ix + 1, getpid(), sleepTime); 
            sleep(sleepTime);

            printf("Process %d (PID: %d) exiting\n", ix + 1, getpid());
            exit(0);  
        } 
    }

    while (wait(NULL) > 0) {}
}

void pattern2 (int index, int numberOfThings) {
    if (index >= numberOfThings) {
        int sleepTime = rand() % 8 + 1; 
        printf("Child %d (PID: %d) [no children created] sleeping %d seconds\n", index, getpid(), sleepTime);
        sleep(sleepTime); 
        printf("Child %d (PID: %d) exiting.\n", index, getpid());
        exit(0);  
    }

    int id = fork();

    if (id == 0) {
        printf("Child %d (PID: %d): starting\n", index, getpid());
        int sleepTime = rand() % 8 + 1; 
        sleep(sleepTime);
        
        printf("Child %d (PID: %d), sleeping %d seconds after creating child %d\n", index, getpid(), sleepTime, index + 1);
        pattern2(index + 1, numberOfThings);
    } else if (id > 0) {
        wait(NULL);
        printf("Child %d (PID: %d) has exited\n", index, id);
    }
    
}