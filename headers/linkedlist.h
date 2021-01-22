#ifndef LIBKIT_CTC_LINKEDLIST_H
#define LIBKIT_CTC_LINKEDLIST_H


struct node_t
{
	int value;
	struct node_t* next;
};	

typedef struct node_t* Node;

Node LinkedList_CreateNode(int value);

void LinkedList_AddNode(Node parentNode, int value);

void LinkedList_PrintValues(Node startingNode);

void LinkedList_FreeNodes(Node startingNode);

void LinkedList_Example(void);

#endif // !LIBKIT_LINKEDLIST
