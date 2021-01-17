#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "printing.h"
#include "sorting.h"

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

    print_intarray(arr, length);
    sorting_mergesort(arr, length);
    print_intarray(arr, length);
}