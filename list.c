#include "list.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    enum ListType type;
    unsigned int count;
    unsigned int length;
    void* array;
} List_t;

List List_Create(enum ListType type)
{
    // assign memory for the struct.
    List_t* tmpList = malloc(sizeof *tmpList);

    tmpList->type = type;
    tmpList->count = 0;
    tmpList->length = 16;

    // assign memory for the internal array
    if (type == lt_char || type == lt_uchar) 
        tmpList->array = calloc(tmpList->length, sizeof(char));
    else if (type == lt_short || type == lt_ushort)
        tmpList->array = calloc(tmpList->length, sizeof(short)); 
    else if (type == lt_int || type == lt_uint)
        tmpList->array = calloc(tmpList->length, sizeof(int));
    else if (type == lt_long || type == lt_ulong)
        tmpList->array = calloc(tmpList->length, sizeof(long));
    else if (type == lt_longlong || type == lt_ulonglong)
        tmpList->array = calloc(tmpList->length, sizeof(long long));
    else if (type == lt_float)
        tmpList->array = calloc(tmpList->length, sizeof(float));
    else if (type == lt_double)
        tmpList->array = calloc(tmpList->length, sizeof(double));
    
    return (List)tmpList;
}

enum ListType List_GetType(List list)
{
    List_t* tmpList = (List_t*)list;
    return tmpList->type;
}

unsigned int List_GetCount(List list)
{
    List_t* tmpList = (List_t*)list;
    return tmpList->count;
}

unsigned int List_GetBufferLength(List list)
{
    List_t* tmpList = (List_t*)list;
    return tmpList->length;
}

void* List_GetItem(List list, int index)
{
    List_t* tmpList = (List_t*)list;

    enum ListType type = List_GetType(list);

    switch (type)
    {
        case lt_char:
            return (char*)tmpList->array + index;
        case lt_uchar:
            return (unsigned char*)tmpList->array + index;
        case lt_short:
            return (short*)tmpList->array + index;
        case lt_ushort:
            return (unsigned short*)tmpList->array + index;
        case lt_int:
            return (int*)tmpList->array + index;                
        case lt_uint:
            return (unsigned int*)tmpList->array + index;
        case lt_long:
            return (long*)tmpList->array + index;
        case lt_ulong:
            return (unsigned long*)tmpList->array + index;            
        case lt_longlong:
            return (long long*)tmpList->array + index;
        case lt_ulonglong:
            return (unsigned long long*)tmpList->array + index;
        case lt_float:
            return (float*)tmpList->array + index;
        case lt_double:
            return (double*)tmpList->array + index;
    }
    
    return NULL;
}

void ReallocArray(void** array, enum ListType type, unsigned int length)
{
     printf("Resizing array...\n");

    if (type == lt_char || type == lt_uchar)
        *array = realloc(*array, length * sizeof(char));     
    else if (type == lt_short || type == lt_ushort)
        *array = realloc(*array, length * sizeof(short));     
    else if (type == lt_int || type == lt_uint)
        *array = realloc(*array, length * sizeof(int));     
    else if (type == lt_long || type == lt_ulong)
        *array = realloc(*array, length * sizeof(long));     
    else if (type == lt_longlong || type == lt_ulonglong)
        *array = realloc(*array, length * sizeof(long long));
    else if (type == lt_float)
        *array = realloc(*array, length * sizeof(float)); 
    else if (type == lt_double)
        *array = realloc(*array, length * sizeof(double));

    printf("Array resized to bufferSize: %d\n", length);
}

void List_Append(List list, void* value)
{
    List_t* tmpList = (List_t*)list;
    enum ListType type = List_GetType(list);

    // Copy and reallocate memory if the buffer is full.
    if (tmpList->count >= tmpList->length)
    {
        tmpList->length *= 2;   
        ReallocArray(&tmpList->array, type, tmpList->length);
    }

    if (type == lt_char)
        ((char*)tmpList->array)[tmpList->count] = *(char*)value;
    else if (type == lt_uchar)
        ((unsigned char*)tmpList->array)[tmpList->count] = *(unsigned char*)value; 
    else if (type == lt_short)
        ((short*)tmpList->array)[tmpList->count] = *(short*)value;  
    else if (type == lt_ushort)
        ((unsigned short*)tmpList->array)[tmpList->count] = *(unsigned short*)value;   
    else if (type == lt_int)
        ((int*)tmpList->array)[tmpList->count] = *(int*)value;   
    else if (type == lt_uint)
        ((unsigned int*)tmpList->array)[tmpList->count] = *(unsigned int*)value; 
    else if (type == lt_long)
        ((long*)tmpList->array)[tmpList->count] = *(long*)value;
    else if (type == lt_ulong)
        ((unsigned long*)tmpList->array)[tmpList->count] = *(unsigned long*)value; 
    else if (type == lt_longlong)
        ((long long*)tmpList->array)[tmpList->count] = *(long long*)value;
    else if (type == lt_ulonglong)
        ((unsigned long long*)tmpList->array)[tmpList->count] = *(unsigned long long*)value; 
    else if (type == lt_float)
        ((float*)tmpList->array)[tmpList->count] = *(float*)value;
    else if (type == lt_double)
        ((double*)tmpList->array)[tmpList->count] = *(double*)value;

    ++tmpList->count;    
}

void List_Destroy(List list)
{
    List_t* tmpList = (List_t*)list;

    // Free memory for internal array
    free(tmpList->array);
    tmpList->array = NULL;

    // Free memory for struct
    free(tmpList);
}

void List_PrintDetails(List list)
{
    printf("Item count of list: %d\n", List_GetCount(list));
    printf("Bufferlength of list: %d\n\n", List_GetBufferLength(list));
}