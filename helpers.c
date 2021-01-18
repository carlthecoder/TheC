#include "helpers.h"

void Switch(void** a, void** b)
{
	void* tmp = *b;
	*b = *a;
	*a = tmp;
}