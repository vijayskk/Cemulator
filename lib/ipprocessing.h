#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../lib/processcommand.h"


typedef struct InputBuffer{
    char * buffer;
    size_t buf_size;
    size_t inputlen;
} InputBuffer;




CommandBuffer * tokenizeCmd(InputBuffer * buff){
    CommandBuffer * cmdBuff = (CommandBuffer *) malloc(sizeof(CommandBuffer));
    cmdBuff->tokencount = 0;

    int i = 0 , length = 0;
    while(1){
        char temp[30] = "";
        while(1){
            if (buff->buffer[i] == ' ' || buff->buffer[i] == '\n')
            {
                strcpy(cmdBuff->tokens[cmdBuff->tokencount].content,temp);
                cmdBuff->tokens[cmdBuff->tokencount].length = length;
                cmdBuff->tokencount++;
                length = 0;
                break;
            }

            if (buff->buffer[i] == '\n')
            {
                break;
            }

            temp[length] = buff->buffer[i];
            i++;
            length++;
        }
        if (buff->buffer[i] == '\n')
        {
            break;
        }
        i++;
    }
    return cmdBuff;
}

void processInput(InputBuffer * buff){
    CommandBuffer * cmdBuff =  tokenizeCmd(buff);
    processCommand(cmdBuff);
}