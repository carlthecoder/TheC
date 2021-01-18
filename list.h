#ifndef LIBKIT_CTC_LIST_H
#define LIBKIT_CTC_LIST_H

typedef struct List_p* List;

enum ListType
{
    lt_char,
    lt_uchar,
    lt_short,
    lt_ushort,
    lt_int,
    lt_uint,
    lt_long,
    lt_ulong,
    lt_longlong,
    lt_ulonglong,
    lt_float,
    lt_double,
};

List List_Create(enum ListType type);
enum ListType List_GetType(List list);
unsigned int List_GetCount(List list);
unsigned int List_GetBufferLength(List list);
void* List_GetItem(List list, int index);
void List_Append(List list, void* value);
void List_Destroy(List list);
void List_PrintDetails(List list);

#endif // !LIBKIT_LIST