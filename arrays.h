#ifndef LIBKIT_CTC_INT_ARRAYS_H
#define LIBKIT_CTC_INT_ARRAYS_H

typedef unsigned int uint;
typedef unsigned long long ullong;



typedef struct iArray_p* iArray; // Handle to an array of ints

iArray iArray_Create(void);
void iArray_Destroy(iArray array);
void iArray_Append(iArray* array_ref, int nr);
int  iArray_GetItem(iArray array, uint index);
void iArray_SetItem(iArray array, uint index, int nr);
ullong iArray_GetLength(iArray array);
void iArray_Print(iArray array);
void iArray_InsertionSort(iArray array, uint length);


// todo:
// delete(), pop() delete_at() pop_at()

// Note:
// this int array can hold up to about 132,500,000 items when using on x86;
// on an x64 machine it can hold up to about 3,000,000,000 items, before the system starts behaving weirdly;
#endif