#include <stdio.h>
#include "integers.h"

void integers_swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void integers_assignment(void)
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
