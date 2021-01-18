#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cmath.h"
#include "helpers.h"

int cmath_BiggestCommonDevisor(int a, int b)
{
	if (a == b)
		return b;
	if (a < b)
		Switch((void**)&a, (void**)&b);

	while (a != 0)
	{
		while (a >= b)
			a -= b;		

		if (a != 0)
			Switch((void**)&a, (void**)&b);
	}

	return b;
}

bool cmath_IsPrime(unsigned long long nr)
{
	if (nr == 2)
	{
		return true;
	}
	else if (nr % 2 == 0)
	{
		return false;
	}

	for (unsigned long long i = 3; i <= nr / 2; i += 2)
	{
		if (nr % i == 0)
		{
			return false;
		}
	}

	return true;
}

void cmath_SumToMax(unsigned long long max)
{
	unsigned int x = 0;
	unsigned long long sum = 0;

	while (x <= max)
	{
		sum += x;
		++x;
	}

	printf("The total sum of all numbers up to %llu is: %llu\n", max, sum);
}

void cmath_SumToMaxFml(unsigned long long max)
{
	unsigned long long n = (unsigned long long)max;
	unsigned long long total = (n / 2) * (n + 1);
	printf("The total sum of all numbers up to %llu is: %llu\n", max, total);
}

unsigned long long cmath_SumToMaxRecursive(unsigned long long n)
{
	// Sum to max will cause stack overflow when called with an input set that is too large.
	if (n == 1)
		return 1;
	else
		return n += cmath_SumToMaxRecursive(n - 1);
}

unsigned long long cmath_Factorial(unsigned long long n)
{
	if (n == 1)
		return 1;
	else
		return n *= cmath_Factorial(n - 1);
}