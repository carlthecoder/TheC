#include "../headers/examples.h"
#include "../headers/book.h"
#include "../headers/list.h"
#include "../headers/symbolics.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <wchar.h>

void Examples_Book(void)
{
	Book book = Book_Create("Alice in Wonderland", "Lewis Carrol", 347);

	Book_Print(book);
	printf("%s has %d pages.\n", Book_GetTitle(book), Book_GetPages(book));

	Book_SetTitle(book, "The mystical adventures of Sphere...");
	Book_SetPages(book, 445);

	Book_Print(book);
	printf("%s has %d pages.\n", Book_GetTitle(book), Book_GetPages(book));

	if (book)
	{
		free(book);
		book = NULL;
	}
}

void Examples_Book2(void)
{
	Book book = Book_Create("Alice in wonderland", NULL, 293);
    
    if (!book)
        return;    

    Book_Print(book);
    Book_Destroy(&book);
}

void Examples_Malloc(void)
{
	// the length of a char array holds the null terminator. So an array of 15 elements can hold 14 chars (+1 null terminator)
	char* str = (char*)malloc(sizeof(char) * 15);
	int* x = (int*)calloc(1, sizeof(int));
	*x = 5;

	strcpy(str, "Hohoho");

	printf("%s\n", str);
	printf("%d\n", *x);

	strcpy(str, "hahahahahahaha");
	printf("%s\n", str);
	printf("%d\n", *x);

	str = realloc(str, sizeof(char) * 16);	// to prevent memory leaks, in actual code the return of realloc should be stored in a temp pointer and null checked
	strcpy(str, "hahahahahahahax");
	printf("%s\n", str);
	printf("%d\n", *x);

	str = realloc(str, sizeof(char) * 17);
	strcpy(str, "hahahahahahahaxx");
	printf("%s\n", str);
	printf("%d\n", *x);

	free(str);
	free(x);
}

void Examples_PrintNumber(void)
{
	unsigned long long nr = 12345678901234567890llu;

	//printf("UL printed as integer %d\n", nr); 
	//printf("UL printed as integer %lld\n", nr);
	printf("UL printed as integer %llu\n", nr);

	printf("%f\n", 8.9);
	printf("%.1f\n", 8.9);
	printf("%.2f\n", 8.9);
	printf("%.4f\n", 8.9);
}

void Examples_Bool(void)
{
	bool a = true;
	if (a)
	{
		printf("C has bool defined in stdbool.h\n");
	}
}

void Examples_ReadChar(void)
{
	char c;
	int counter = 0;
	char readinput[256];

	printf("Enter input: ");

	while ((c = getchar()) != EOF && counter < 256)
	{
		readinput[counter] = c;
		++counter;
	}

	printf("%s\n", readinput);
	printf("\a\n");
}

void Examples_PrintWideString(void)
{
	char* t = "Bart Simpson\n";
	wchar_t* wt = L"Homer Simpson\n";

	printf("%s", t);
	printf("%ls", wt);
}

void Examples_LogicalSignedUnsignedIssue(void)
{
	// watch out when doing logical checks using signed with unsigned integers
	// an implicit conversion can occur which will result in an error.
	// e.g. i is implicitly converted to an unsigned integer, becoming 2��-1 instead of -1
	int i = -1;
	int max = 20;

	if (i < max)
	{
		printf("i is smaller than max\n");
	}
	else
	{
		printf("i is bigger than max\n");
	}
}

void Examples_ReadInput(void)
{
	char name[50];
	printf("Enter your name: \n");
	fgets(name, (int)strlen(name), stdin);
	//getline(name, 50, stdin);				// getline is posix and not available on windows

	int age;
	printf("Enter your age: \n");
	scanf("%d", &age);						// scanf reads up to the first white space.

	printf("Hello %s, you are %d.\n", name, age);
}

void Examples_WriteFile(char name[], int age)
{    
	// Create a FILE* handle;
	// Use fopen to open the file and store the returned handle in the FILE* handle. Note parameter for writing "w" or appending "a"
	// Use fprintf to write formatted output to the file
	FILE* handle = fopen("out.txt", "a");
	fprintf(handle, "%s in service for %d years.\n", name, age);
	fclose(handle);

	// Following code writes a basic hello world source file
	FILE* hndl = fopen("C:/Users/Carl/Desktop/MyFile.c", "w");
	fprintf(hndl, "#include <stdio.h>\n");
	fprintf(hndl, "\n");
	fprintf(hndl, "int main()\n{\n");
	fprintf(hndl, "\tprintf(\"Hello World!\\n\");\n");
	fprintf(hndl, "\treturn 0;\n");
	fprintf(hndl, "}\n");
	fclose(hndl);
}

void Examples_ReadFile(void)
{
    FILE* handle =  fopen("out.txt", "r");

    char line[255];

    while(fgets(line, 255, handle))
    {
        printf("%s", line);
    }    

    fclose(handle);
}

void Examples_DynamicArray(void)
{
	#define EMPTY_LINE printf("\n");
	
    unsigned int* p;
    p = calloc(10, sizeof(int));

    for (unsigned int i = 0; i < 10; ++i)
    {
		// p[1] is the same as *(p + 1)
        
		//p[i]= i *10;
        *(p + i) = i * 10;
    }
    
    for (unsigned int i = 0; i < 10; i++)
    {
        printf("\t%d\t", p[i]);
    }

    EMPTY_LINE

    for (unsigned int i = 0; i < 10; i++)
    {
        printf("%p \t", &p[i]);
    }

    EMPTY_LINE

    // This prints the value of the pointer. i.e. the adress that it holds. This is not the adress of the pointer itself
    for (unsigned int i = 0; i < 10; i++)
    {
        printf("%p \t", &p[i]);
    }

    EMPTY_LINE

    printf("The p variable holds the  and points to the first index of the array: %p\n", p);

    free(p);
}

void Examples_List(void)
{
	List list = List_Create(lt_float);
	List_PrintDetails(list);

	printf("\n");

	for (int i = 0; i < 5000; ++i)
	{
		// long long* ptr = GetListItem(list, i);
		//*ptr = i * 3;
		float val = i * 300.125f;
		List_Append(list, &val);
	}

	for (int i = 0; i < 5000; ++i)
	{
		float* ptr = List_GetItem(list, i);
		printf("Index %d: %.2f \n", i, *ptr);
	}

	List_PrintDetails(list);

	List_Destroy(list);
}

void Examples_WcharCompare(void)
{
	// Compares wide char arrays

	wchar_t* name1 = L"Bart";
	wchar_t* name2 = L"bart";

	if (wcscmp(name1, name2) != 0)
		printf("DIFFERENT");
	else
		printf("SAME");
}

float Examples_DSqrt(float number)
{
	// weird square root approximation from Eskil Steenberg
	int i;
	double x, y;

	x = number * 0.5;
	y = number;

	i = *(int*)&y;
	i = 0x5f3759df - (i >> 1);

	y = *(float*)&i;
	y = y * (1.5 - (x * y * y));
	y = y * (1.5 - (x * y * y));

	return number * (float)y;
}

void Examples_Sizeof(void)
{
	// This example needs the Macros.h header
	int a[17];
	int *b = &a[0];

	MacroFuncs_PrintIntValue((int)sizeof a);					// The size of the whole array
	MacroFuncs_PrintIntValue((int)(sizeof a / (sizeof *a)));		// The item count of the array = the size of total array / size of a single element

	MacroFuncs_PrintIntValue((int)sizeof b);					// size of a pointer to array
	MacroFuncs_PrintIntValue((int)sizeof *b);				// size of the first element of the array
}

void Examples_FormatSpecifiersDatatypes(void)
{
	char x = 76;

	printf("x is decimal: %d\n", x);
	printf("x is letter: %c\n", x);
	printf("x is hex: %x\n", x);
	printf("x is octal: %o\n", x);
}

// callbacks
static int cb_square(int x) { return x * x; }
static int cb_cube(int x) { return x * x * x; }
// functions with callbacks as parameters
static void perform_CallBack(int nr, int (*func)(int)) { printf("%d\n", func(nr)); }
static void perform_CallBack2(int nr, int func(int)) { printf("%d\n", func(nr)); }

void Examples_Callback(void)
{
	perform_CallBack(5, cb_square);
	perform_CallBack2(5, cb_cube);
}


int Examples_PlusPlus(int* index)
{
	return (*index += 1) -1;
}

void Examples_StringsAreStaticUnique(void)
{
    char *tptr = "just some text";
    char aptr[] = "just some text";

    // the pointer holds the address of the string literal
    printf("%s\n", tptr);
    printf("%p\n", tptr);

    // the array holds the same value, but has a different address
    printf("%s\n", aptr);
    printf("%p\n", aptr);

    // note that the address of the string is the same as the address of the pointer 
    printf("%s\n", "just some text");
    printf("%p\n", "just some text");
}

void Examples_strcpy(char *dest, char *src)
{
    // make clever use of pointer arithmetic, incrementation and comparison all at once
    while((*dest++ = *src++) != '\0')
    ;
}