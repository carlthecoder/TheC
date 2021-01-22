#include "../headers/syshelpers.h"
#include <stdio.h>

void SystemHelpers_PrintDatatypeSizes(void)
{
	printf("Size of datatypes in bytes:\n");
	printf("char :\t\t %zd\n", sizeof(char));
	printf("uchar :\t\t %zd\n", sizeof(unsigned char));

	printf("short :\t\t %zd\n", sizeof(short));
	printf("ushort :\t %zd\n", sizeof(unsigned short));

	printf("int :\t\t %zd\n", sizeof(int));
	printf("uint :\t\t %zd\n", sizeof(unsigned int));

	printf("long :\t\t %zd\n", sizeof(long));
	printf("ulong :\t\t %zd\n", sizeof(unsigned long));

	printf("long long :\t %zd\n", sizeof(long long));
	printf("ulonglong :\t %zd\n", sizeof(unsigned long long));
}

void SystemHelpers_CharacterCopy(void)
{
	// A small program that reads characters from the standard input(stdin) and writes them to the standard output (stdout)
	// This can be used to echo keyboard input.
	// But by redirecting the standard input / output (File Descriptors) it will also work to read/write input/output to/from files.
	// This is done by using pipes when running the program from a command line:
	//		./main.c < inputFile.ext > outputFile.ext
	// this provides either (when not redirecting output) cat or copy functionality..

	char c;
	while ((c = getchar()) != EOF)
	{
		putchar(c);
	}
}
