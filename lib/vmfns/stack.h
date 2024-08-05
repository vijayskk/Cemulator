#include <stdio.h>
#include <stdlib.h>
#include "../defenitions.h"

int sp = 0;

int * stack; 

void initializeStack(){
    sp = 0;
    stack = (int *) malloc(sizeof(int) * STACK_SIZE);
}

void printStack(){
    printf("[\t");
    for (int i = 1; i <= sp; i++)
    {
        printf("%d\t",stack[i]);
    }
    printf("]\n");
}

void destroyStack(){
    free(stack);
}