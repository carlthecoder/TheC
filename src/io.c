#include <stdio.h>
#include <stdlib.h>
#include "../headers/io.h"

void io_charcopy(void)
{    
    int c = 0;
    while ( (c = getchar()) != EOF )
    {
        putchar(c);
    }
}

void io_readfilebyline(void)
{
    char *line = malloc(sizeof(char) * 255);
    
    FILE* file;
    file = fopen("lorem.txt", "r");
    
    while(fgets(line, 255, file) != NULL)
    {
        printf("%s\n", line);
    }
}