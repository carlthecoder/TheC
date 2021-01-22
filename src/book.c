#include "../headers/book.h"

// The struct is defined in the source file so that it cannot be accessed directly.
// Because it is static it can only be seen in this file.
typedef struct Book__t
{
	char* title;
	char* author;
	int pages;
} sBook;

Book Book_Create(char* title, char* author, int pages)
{
	if (!title || ! author)
	{
		fprintf(stderr, "Book creation failed, please enter all the required info");
		return NULL;
	}
	

	// Assign memory for the struct
	sBook* tmpBook = (sBook*)malloc(sizeof(sBook));

	if (!tmpBook)
	{
		return NULL;
	}	
	
	tmpBook->pages = pages;

	int titleLength = strlen(title) + 1;
	int authorLength = strlen(author) + 1;

	// Assign memory for the title and author strings. (the length of the title +1 for the null char)
	tmpBook->title = malloc(sizeof(char) * titleLength);
	tmpBook->author = malloc(sizeof(char) * authorLength); 

	if (!tmpBook->title || !tmpBook->author)
	{
		free(tmpBook);
		return NULL;		
	}

	strncpy(tmpBook->title, title, titleLength);
	strncpy(tmpBook->author, author, authorLength);

	return (Book)tmpBook;
}

void Book_Destroy(Book* book)
{
	sBook *tmpbook = (sBook*)(*book);

	free(tmpbook->title);
	tmpbook->title = NULL;

	free(tmpbook->author);
	tmpbook->author = NULL;

	free(tmpbook);
	tmpbook = NULL;

	*book = NULL;
}

char* Book_GetTitle(Book book)
{
	sBook *sbook = (sBook*)book;
	return sbook->title;
}

void Book_SetTitle(Book book, char* title)
{
	sBook *sbook = (sBook*)book;	
	sbook->title = realloc(sbook->title, sizeof(char) + strlen(title) + 1);
	
	if (sbook->title)
	{
		strncpy(sbook->title, title, strlen(title) + 1);
	}
	else
	{
		// do nothing when realloc returns a nullpointer
	}	
}

int Book_GetPages(Book book)
{
	sBook* sbook = (sBook*)book;
	return sbook->pages;
}

void Book_SetPages(Book book, int pages)
{
	sBook *sbook = (sBook*)book;
	sbook->pages = pages;
}

void Book_Print(Book book)
{
	sBook *sbook = (sBook*)book;	
	printf("Book:\t%s\nAuthor:\t%s\nPages:\t%4d\n", sbook->title, sbook->author, sbook->pages);
}
