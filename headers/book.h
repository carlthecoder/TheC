#ifndef LIBKIT_CTC_BOOK_H
#define LIBKIT_CTC_BOOK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create an incomplete type and provide a pointer to it;
struct Book_t;
typedef struct Book_t* Book;

Book Book_Create(char* title, char* author, int pages);
void Book_Destroy(Book* book);
char* Book_GetTitle(Book book);
void Book_SetTitle(Book book,char* newTitle);
int Book_GetPages(Book book);
void Book_SetPages(Book book, int pages);
void Book_Print(Book book);

#endif