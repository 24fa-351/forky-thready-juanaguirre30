#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "forkpattern.h" 

int main (int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error: Expected 2 arguments - number of things and pattern number.\n");
        return 1;
    } 

    int numberOfThings = atoi(argv[1]);
    int patternNumber = atoi(argv[2]);
    int index = 0; 

    if (numberOfThings < 1 || numberOfThings > 256) {
        printf("Error: Number of things must be between 1 and 256.\n");
        return 1;
    }

    if (patternNumber < 1 || patternNumber > 2) {
            printf("Error: Pattern number must be 1 or 2.\n");
            return 1;
        }    

    srand(time(NULL));

    if (patternNumber == 1) {
        pattern1 (numberOfThings);
    } else {
        pattern2 (index, numberOfThings); 
    }

    return 0; 
}