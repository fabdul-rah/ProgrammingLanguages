
/* Compile with...
    clang 06mainMalloc.c
...and then execute with...
	./a.out
This tutorial describes how to dynamically allocate memory. This topic is 
notorious for difficulty, but it's actually quite simple: Any memory, that you 
allocate using malloc, you must later free using free. */

#include <stdio.h>
/* The stdlib library gives us dynamic memory management: malloc and free. */
#include <stdlib.h>
/* The assert library gives us a simple way of managing some errors. */
#include <assert.h>

/* This function is copied from an earlier tutorial. */
void printDoubleArray(int length, const double a[]) {
	for (int i = 0; i < length; i += 1)
		printf("    %f\n", a[i]);
}

int main() {
    double myArray[3] = {0.3, 0.1, 0.8};
    printf("Here's myArray:\n");
    printDoubleArray(3, myArray);
    /* To make a copy of myArray in heap memory, we first do this. */
    double *myPtr = malloc(3 * sizeof(double));
    /* If an error happened, then the returned pointer is NULL. If the pointer 
    is NULL, then this assert statement stops the entire program and provides 
    helpful debugging information. */
    assert(myPtr != NULL);
    /* At this point, myPtr can be treated as an array of three doubles. 
    However, the values of those doubles are garbage --- whatever happened to be 
    sitting in that memory when it was claimed. */
    printf("Here's myPtr:\n");
    printDoubleArray(3, myPtr);
    /* Here is the simplest way to copy the array. */
    for (int i = 0; i < 3; i += 1)
    	myPtr[i] = myArray[i];
    /* Now myPtr is a copy of myArray. */
    printf("Here's myPtr:\n");
    printDoubleArray(3, myPtr);
    /* Here's the part that imperfect programmers sometimes forget. */
    free(myPtr);
    /* Once the malloc has been freed, we can do whatever we want with myPtr. */
    myPtr = myArray;
    myPtr[2] = 0.7;
    printf("Here's myArray:\n");
    printDoubleArray(3, myArray);
    return 0;
}

/* Let's go one step further. With a.out containing the compiled program, run...
    valgrind ./a.out
Valgrind is a memory debugger, capable of detecting some of the most common 
errors in managing memory. With the program written as it is, Valgrind should 
praise us for freeing memory at the end, but it should also chastise us for 
printing out the uninitialized myPtr midway through.

Try moving the free() to somewhere before the array copy, recompiling, and 
re-running Valgrind, to see how Valgrind's complaints change.

Try commenting out the free(), to see how the complaints change. */

