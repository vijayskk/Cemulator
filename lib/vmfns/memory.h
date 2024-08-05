#include <stdio.h>
#include <stdlib.h>
#include "../defenitions.h"

int mp = 0;

int * memory; 

void initializeMemory(){
    mp = 0;
    memory = (int *) malloc(sizeof(int) * MEM_SIZE);
}

void printMemory(){
    printf("{\t");
    for (int i = 1; i <= mp; i++)
    {
        printf("%d\t",memory[i]);
    }
    printf("}\n");
}

void destroyMemory(){
    free(memory);
}