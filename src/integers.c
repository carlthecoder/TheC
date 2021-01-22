#include <stdio.h>
#include <string.h>
#include <math.h>
#include "../headers/integers.h"

void Integers_Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Integers_Assignment(void)
{
    // C can assign numbers in decimal, binary, octal, and hex
    int decnr = 15;
    int binnr = 0b1111;
    int octnr = 017;
    int hexnr = 0xF; 

    printf("Decimal 15 is:\t%4d\n", decnr);
    printf("Binary 1111 is:\t%4d\n", binnr);
    printf("Octal 17 is:\t%4d\n", octnr);
    printf("Hex F is:\t%4d\n", hexnr);
}

int Integers_ParseInt(char* intstring)
{    
    int nrLength = strlen(intstring);
    int integer = 0;
    int power = 0;
    for (int i = nrLength-1; i >= 0; i--)
    {
        integer += (intstring[i] - '0') * pow(10, power++);
    }
    
    return integer;
}


// todo: recursive integer parse
unsigned long long Integers_RecursiveParse(char *intstring)
{   
    if (*intstring == '\0')
    {
        return 0;
    }
    
    int power = strlen(intstring) -1;

    unsigned long long x = (*intstring - '0') * pow(10, power) + Integers_RecursiveParse(intstring + 1);

    return x;
}