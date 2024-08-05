#include "../defenitions.h"
#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "memory.h"
#include "registers.h"

// --------- Variables --------------
bool isRunning;
int pc = 0;

// --------- Declarations --------------
void eval(int, int, int);

void start()
{
    isRunning = true;
    initializeStack();
    initializeMemory();
    initializeregisters();
}

void kill(){
    isRunning = false;
    destroyStack();
    destroyMemory();
    destroyregisters();
}

// --------- Main --------------
int run(int instr, int v1, int v2)
{
    eval(instr, v1, v2);
    pc++;

    return 0;
}

void eval(int instr, int v1, int v2)
{
    if (instr == START)
    {
        start();
    }
    if (instr == STATUS)
    {
        printf(isRunning?"ACTIVE":"STOPPED");
    }
    else if (!isRunning)
    {
        printf("VM NOT STARTED");
        return;
    }
    
    switch (instr)
    {
    case HLT:
        kill();
        printf("VM Stopped");
        break;
    case PSH:
        sp++;
        stack[sp] = v1;
        printStack();
        break;
    case POP:
        if (sp >0)
        {
            stack[sp] = 0;
            sp--;
            printStack();
            break;
        }else{
            printf("STACK EMPTY\n");
            printStack();
        }
    case MOV:
        if (v1>=0)
        {
            printf("REGISTER EXPECTED");
            break;
        }
        if (v2 < 0)
        {
            registers[v1 * -1] = registers[v2 * -1];
        }else{
            registers[v1 * -1] = v2;
        }
        printRegisters();
        break;
    case INC:
        registers[-v1]++;
        printRegisters();
        break;
    case DEC:
        registers[-v1]--;
        printRegisters();
        break;

    case ADD:
        if (v1>=0)
        {
            printf("REGISTER EXPECTED");
            break;
        }
        if (v1 != -1)
        {
            printf("USE ONLY ACCUMULATOR");
            break;
        }
        
        if (v2 < 0)
        {
            registers[1] += registers[v2 * -1];
        }else{
            registers[1] += v2;
        }
        printRegisters();
        break;
    case SUB:
        if (v1>=0)
        {
            printf("REGISTER EXPECTED");
            break;
        }
        if (v1 != -1)
        {
            printf("USE ONLY ACCUMULATOR");
            break;
        }
        
        if (v2 < 0)
        {
            registers[1] -= registers[v2 * -1];
        }else{
            registers[1] -= v2;
        }
        printRegisters();
        break;
    case MOVX:
        if (v1 < 0 && v1 != -3)
        {
            registers[-v1] = memory[registers[-3]];
        }else{
            printf("BAD REGISTER");
        }
        break;
    default:
        break;
    }
}
