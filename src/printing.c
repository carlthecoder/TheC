#include <stdlib.h>
#include <stdio.h>
#include "../headers/printing.h"

int print_intarray(int* arr, int length)
{
    if (arr == NULL || length <= 0) 
        return EXIT_FAILURE;
    
    printf("[ ");
    
    for (int i = 0; i < length; i++)
    {
        
        printf("%d", arr[i]);
        if (i != length -1)
            printf(",");        
    }

    printf(" ]\n");

    
    return EXIT_SUCCESS;    
}