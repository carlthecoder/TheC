#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node LinkedList_CreateNode(int value)
{
	Node node = malloc(sizeof(*node));

	if (node)
	{
		node->value = value;
		node->next = NULL;
	}

	return node;
}

void LinkedList_AddNode(Node parentNode, int value)
{
	parentNode->next = LinkedList_CreateNode(value);
}

void LinkedList_PrintValues(Node startingNode)
{
	if (startingNode == NULL)
		return;

	int index = 0;
	printf("node %d: %d\n", index, startingNode->value);

	Node iterator = startingNode;
	while (iterator->next)
	{
		iterator = iterator->next;
		printf("node %d: %d\n", ++index, iterator->value);
	}
}

void LinkedList_FreeNodes(Node startingNode)
{
	if (startingNode == NULL)
		return;

	Node iterator = startingNode;

	while (iterator)
	{
		Node currentNode = iterator;
		iterator = iterator->next;
		free(currentNode);
	}
}

void LinkedList_Example(void)
{
	Node root = LinkedList_CreateNode(13);
	LinkedList_AddNode(root, 47);
	LinkedList_PrintValues(root);
	LinkedList_FreeNodes(root);
}