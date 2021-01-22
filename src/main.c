#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "../headers/book.h"
#include "../headers/integers.h"

// Global external variables are assigned by default.
// Declare them at the top of the file, but avoid their use as much as possible
//int globalExternal; 

// Declaration of a link to a global external declared and defined in another module
// an extern declaration cannot have an assignment
//extern int globalExternalFromOtherFile;

// Static external variables are only visible within this file.
// They aren't globally available, using these can make modules resemble classes
// like globals they are automatically assigned when not explicitly assigned
//static int staticExternal;

typedef struct node_t
{
    int value;
    struct node_t *lt;
    struct node_t *rt;
} Node;


void Trees_OrderedVisit(Node* node)
{
    if (node == NULL)
        return;

    
    printf("%d\n", node->value);

    if (node->lt)
    {
        Trees_OrderedVisit(node->lt);
    }
    if (node->rt)
    {
        Trees_OrderedVisit(node->rt);
    }
    
}

// The main starting point of a C program:
int main(int argc, char** argv)
{
    Node root;
    root.value = 0;

    Node lt;
    lt.value = 1;
    lt.lt = NULL;
    lt.rt = NULL;

    Node rt;
    rt.value = 2;
    rt.lt= NULL;
    rt.rt = NULL;

    root.lt = &lt;
    root.rt = &rt;

    Trees_OrderedVisit(&root);

    return 0;
}
