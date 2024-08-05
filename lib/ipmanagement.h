#include <stdio.h>
#include <stdlib.h>
#include "../lib/ipprocessing.h"



extern InputBuffer * new_ipbuff(){
    InputBuffer * buff = (InputBuffer *) malloc(sizeof(InputBuffer));
    buff->buffer = NULL;
    buff->buf_size = 0;
    buff->inputlen = 0;
    return buff;
}

extern void read_ipbuff(InputBuffer * buff){
    getline(&buff->buffer,&buff->buf_size,stdin);
}

extern void debug_ipbuff(InputBuffer * buff){
    printf("\nCommand : %s,Length: %zu",buff->buffer,buff->inputlen);
}

extern void print_prompt(){
    printf("\n>>>");
}
