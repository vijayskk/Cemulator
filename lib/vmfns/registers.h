#include <stdio.h>
#include <stdlib.h>
#include "../defenitions.h"


int * registers; 

void initializeregisters(){
    registers = (int *) malloc(sizeof(int) * REG_SIZE);
}

void printRegisters(){
    printf("(\t");
    for (int i = 1; i <= REG_SIZE; i++)
    {
        printf("%d\t",registers[i]);
    }
    printf(")\n");
}

void destroyregisters(){
    free(registers);
}