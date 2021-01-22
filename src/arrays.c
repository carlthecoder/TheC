#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../headers/arrays.h"

typedef struct
{
	unsigned long long length;
	unsigned long long allocated;
	int data[];
} iArray_t;


iArray iArray_Create(void)
{
	iArray_t* t = malloc((sizeof *t) + 16 * sizeof(int));
	t->length = 0;	
	t->allocated = 16;

	// struct and array can be allocated separately but then the array memory
	// is not guaranteed to come straight after the memory of the struct.
	// Doing it like above has some advantages:
	//  - only a single call to malloc
	//  - memory is continuous and so access is faster
	
	//iArray_t* _t = malloc(sizeof * _t);
	//_t->array = malloc(sizeof(*_t->array) * _t->allocated);

	return (iArray)t;
}

void iArray_Destroy(iArray array)
{
	iArray_t* t = (iArray_t*)array;

	free(t->data);
	free(t);
	t = NULL;

	printf("int_array has been destroyed.\n");
}

void iArray_Append(iArray* array_ref, int nr)
{
	iArray_t* t = (iArray_t*)*array_ref;

	if (t->length >= t->allocated)
	{
		t->allocated *= 2;
		printf("reallocating buffer. New  size: %llu\n", t->allocated);
		*array_ref = realloc(t, (size_t)((sizeof *t) + t->allocated * sizeof(int)));
		t = (iArray_t*)*array_ref;
	}

	t->data[t->length++] = nr;
}

int iArray_GetItem(iArray array, uint index)
{
	iArray_t* t = (iArray_t*)array;
	return t->data[index];
}

void iArray_SetItem(iArray array, uint index, int nr)
{
	iArray_t* t = (iArray_t*)array;
	t->data[index] = nr;
}

ullong iArray_GetLength(iArray array)
{
	iArray_t* _t = (iArray_t*)array;
	return _t->length;
}

void iArray_Print(iArray array)
{
	iArray_t* t = (iArray_t*)array;

	printf("[");
	for (uint i = 0; i < t->length; i++)
	{
		if (i == t->length - 1)
			printf("%d]", t->data[i]);
		else
			printf("%d, ", *(t->data + i));
	}
}

void iArray_InsertionSort(iArray array, uint length)
{
	iArray_t* t = (iArray_t*)array;

	for (size_t i = 1; i < length; ++i)
	{
		bool done = false;
		while (i >= 0 && !done)
		{
			if (i > 0 && t->data[i] < t->data[i - 1])
			{
				int temp = t->data[i - 1];
				t->data[i - 1] = t->data[i];
				t->data[i] = temp;
				i -= 1;
			}
			else
			{
				done = true;
			}
		}
	}
}