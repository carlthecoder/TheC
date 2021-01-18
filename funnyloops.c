#include "funnyloops.h"

void funnyloops_EvenTriangleABC(int rows)
{
	for (int row = 0; row < rows; row++)
	{
		int spaces = rows - (row + 1);

		for (int i = 0; i < spaces; i++)
		{
			printf(" ");
		}

		int length = (row * 2) + 1;

		for (char c = 'A'; c < length + 'A'; c++)
		{
			if (ispunct(c))
				putchar('_');
			else
				putchar(c);
		}

		printf("\n");
	}
}

void funnyloops_RightTriangleABC()
{
	for (int i = 0; i < 10; i++)
	{
		for (char c = 'A'; c < 'A' + i + 1; c++)
		{
			putchar(c);
		}

		printf("\n");
	}
}