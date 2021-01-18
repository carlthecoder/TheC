#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "book.h"

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


// The main starting point of a C program:
int main(int argc, char** argv)
{
    return 0;
}
