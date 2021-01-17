#include <stdio.h>
#include "delegation.h"

int delegate_square(int x)
{
    return x * x;
}

void delegate_functionpointer(void)
{
     int (*func)(int x); 
    func = delegate_square;  
    printf("%d\n", func(5));
}