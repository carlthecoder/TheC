#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <string.h>

// Global external variables are assigned by default.
// Declare them at the top of the file, but avoid their use as much as possible
int globalExternal; 

// Declaration of a global external declared and defined in another module
// an extern declaration cannot have an assignment
extern int globalExternalFromOtherFile;

// Static external variables are only visible within this file.
// They aren't globally available, using these can make modules resemble classes
// like globals they are automatically assigned when not explicitly assigned
static int staticExternal;


// Functions are the main logical unit in C.
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

void numbers_binocthex()
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

int delegate_square(int x)
{
    return x * x;
}

void delegate_functionpointer(void)
{
     int (*func)(int x); 
    func = delegate_square;
    int x = func(5);
    printf("%d\n", x);
}


void Swap(int* arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = arr[i];
}

int Print_intarray(int* arr, int length)
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

int sorting_mergesort(int* arr, int length)
{
    if (arr == NULL || length <= 0)
        return EXIT_FAILURE;

    // pointers to the split groups
    int *grp1;
    int *grp2;

    // position markers for the groups
    int grpIndex1 = 0;
    int grpIndex2 = 0; 

    // the sorted list per group
    int sorted[length];

    if (length > 1)
    {
        int len1 = length / 2;
        int len2 = length - len1; 

        grp1 = arr;
        grp2 = arr + len1;

        sorting_mergesort(grp1, len1);
        sorting_mergesort(grp2, len2);

        for (int i = 0; i < length; i++)
        {
            if (grpIndex1 == len1)
            {
                sorted[i] = grp2[grpIndex2++];
            }
            else if(grpIndex2 == len2)
            {
                sorted[i] = grp1[grpIndex1++];
            }
            else if (grp1[grpIndex1] < grp2[grpIndex2])
            {
                sorted[i] = grp1[grpIndex1++];
            }
            else
            {
                sorted[i] = grp2[grpIndex2++];
            }
        }

        // copy the sorted result to the array, this will allow the next recursion to get the sorted array
        memcpy(arr, sorted, length * sizeof(int));        
    }
    return 0;   
}

void sorting_example(void)
{
    int arr[] = {2,31,13,54,1,8,7,13,8,47,22,66,14,8,6,2,3,5,1,13,47,23,25,75,33,32,22,13,8};
    int sizeofArr = sizeof(arr);
    int sizeofElem = sizeof(arr[0]);
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("sizeof int:\t%5ld\n", sizeof(int));
    printf("sizeof element:\t%5d\n", sizeofElem);
    printf("sizeof array:\t%5d\n", sizeofArr);
    printf("sizeof element:\t%5d\n", length);

    Print_intarray(arr, length);
    sorting_mergesort(arr, length);
    Print_intarray(arr, length);
}

// The main starting point of a C program:
int main(int argc, char** argv)
{  
    return 0;
}
