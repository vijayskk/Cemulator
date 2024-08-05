#include "../lib/ipmanagement.h"
#include "../lib/startupmgr.h"
#include <string.h>

int main()
{
    InputBuffer * buff = new_ipbuff();
    welcomeMessage();
    while (1==1)
    {
        print_prompt();
        read_ipbuff(buff);
        processInput(buff);
    }
    
    return 0;
}
