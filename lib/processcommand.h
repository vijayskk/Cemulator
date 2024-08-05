#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vmfns/system.h"

typedef struct Token{
    char content[30];
    size_t length;
} Token;

typedef struct CommandBuffer{
    Token tokens[10];
    int tokencount;
}CommandBuffer;

void handleExit(){
    kill();
    printf("bye\n");
}


// -----------------Process Here------------------------------
int getRegister(char *);

void processCommand(CommandBuffer * cmdBuff){
    if ( strcmp( cmdBuff->tokens[0].content,"CLOSE") == 0 && cmdBuff->tokencount == 1)
    {
        atexit(handleExit);
        exit(0);
    }

    else if ( strcmp( cmdBuff->tokens[0].content,"STATUS") == 0 && cmdBuff->tokencount == 1)
    {
        run(STATUS,0,0);
    }

    else if ( strcmp( cmdBuff->tokens[0].content,"START") == 0 && cmdBuff->tokencount == 1)
    {
        run(START,0,0);
    }

    else if ( strcmp( cmdBuff->tokens[0].content,"HLT") == 0 && cmdBuff->tokencount == 1)
    {
        run(HLT,0,0);
    }
    
    else if( strcmp(cmdBuff->tokens[0].content,"MOV") == 0 ){
        if (cmdBuff->tokencount == 3 && strcmp(cmdBuff->tokens[1].content,"") != 0 && strcmp(cmdBuff->tokens[2].content,"") != 0 )
        {
            if (getRegister(cmdBuff->tokens[1].content) != 0)
            {
                int arg = atoi(cmdBuff->tokens[2].content);
                run(MOV,getRegister(cmdBuff->tokens[1].content),getRegister(cmdBuff->tokens[2].content) == 0?arg:getRegister(cmdBuff->tokens[2].content));
            }else{
                printf("NO SUCH REGISTER");
            }
        }else{
            printf("VALUE EXPECTED");
        }
    }
    
    else if( strcmp(cmdBuff->tokens[0].content,"ADD") == 0 ){
        if (cmdBuff->tokencount == 3 && strcmp(cmdBuff->tokens[1].content,"") != 0 && strcmp(cmdBuff->tokens[2].content,"") != 0 )
        {
            if (getRegister(cmdBuff->tokens[1].content) != 0)
            {
                int arg = atoi(cmdBuff->tokens[2].content);
                run(ADD,getRegister(cmdBuff->tokens[1].content),getRegister(cmdBuff->tokens[2].content) == 0?arg:getRegister(cmdBuff->tokens[2].content));
            }else{
                printf("NO SUCH REGISTER");
            }
        }else{
            printf("VALUE EXPECTED");
        }
    }

    else if( strcmp(cmdBuff->tokens[0].content,"SUB") == 0 ){
        if (cmdBuff->tokencount == 3 && strcmp(cmdBuff->tokens[1].content,"") != 0 && strcmp(cmdBuff->tokens[2].content,"") != 0 )
        {
            if (getRegister(cmdBuff->tokens[1].content) != 0)
            {
                int arg = atoi(cmdBuff->tokens[2].content);
                run(SUB,getRegister(cmdBuff->tokens[1].content),getRegister(cmdBuff->tokens[2].content) == 0?arg:getRegister(cmdBuff->tokens[2].content));
            }else{
                printf("NO SUCH REGISTER");
            }
        }else{
            printf("VALUE EXPECTED");
        }
    }

    else if( strcmp(cmdBuff->tokens[0].content,"POP") == 0 && cmdBuff->tokencount == 1){

        run(POP,atoi(cmdBuff->tokens[1].content),0);
    }

    else if( strcmp(cmdBuff->tokens[0].content,"PSH") == 0 ){
        if (cmdBuff->tokencount == 2 && strcmp(cmdBuff->tokens[1].content,"") != 0 )
        {
            run(PSH,atoi(cmdBuff->tokens[1].content),0);
        }else{
            printf("VALUE EXPECTED");
        }
    }

    else if(cmdBuff->tokencount == 1 && strcmp(cmdBuff->tokens[0].content,"") == 0){
        ;
    }

    else{
        printf("ERROR: Bad Command!!!");
    }
}

int getRegister(char * reg){
    if (strcmp(reg, "A") == 0)
    {
        return A;
    }
    else if (strcmp(reg, "B") == 0)
    {
        return B;
    }
    else if (strcmp(reg, "DPTR") == 0)
    {
        return DPTR;
    }
    else if (strcmp(reg, "R1") == 0)
    {
        return R1;
    }
    else if (strcmp(reg, "R2") == 0)
    {
        return R2;
    }
    else if (strcmp(reg, "R3") == 0)
    {
        return R3;
    }
    else if (strcmp(reg, "R4") == 0)
    {
        return R4;
    }
    else if (strcmp(reg, "R5") == 0)
    {
        return R5;
    }
    else if (strcmp(reg, "R6") == 0)
    {
        return R6;
    }
    else if (strcmp(reg, "R7") == 0)
    {
        return R7;
    }
    else if (strcmp(reg, "R8") == 0)
    {
        return R8;
    }
    else if (strcmp(reg, "R9") == 0)
    {
        return R9;
    }
    else if (strcmp(reg, "R0") == 0)
    {
        return R0;
    }
    else {
        return 0;
    }
    
}