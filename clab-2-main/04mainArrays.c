/* Compile with...
    clang 04mainArrays.c
...and then execute with...
	./a.out
This tutorial teaches the basics of arrays. */

#include <stdio.h>

/* The following function inputs a list of numbers and outputs their sum. The 
parameter a is not just a double, but an array of doubles. Arrays are much like 
lists in other languages, but in C they have two crucial limitations. First, 
every element of the array must be of the same type --- in this, case, double. 
Second, an array does not know its length. That's why we pass the length as a 
separate parameter. The array elements are indexed from 0, not from 1. */
double sum(int length, double a[]) {
    double total = 0.0;
    /* By the way, 'i += 1' is a nice shorthand for 'i = i + 1'. */
    for (int i = 0; i < length; i += 1)
        total += a[i];
    return total;
}

/* Recall from an earlier tutorial that C is call-by-value. That is, when a 
parameter is passed to a function, a copy of that parameter is passed. So you 
can alter the parameter inside the function, without altering its value outside 
the function. Right? The tricky part is that a C array is actually a memory 
location. So when you alter the contents of a C array in a function, you are 
altering the array outside the function too. Here's an example. */
void cumulativeSum(int length, double a[]) {
    for (int i = 1; i < length; i += 1)
        a[i] += a[i - 1];
}

/* We frequently want to use arrays in a read-only manner. To avoid accidentally 
altering the contents of an array that is meant to be read-only, we can prepend 
the const qualifier to the array declaration. To practice this concept, edit the 
cumulativeSum function above, replacing 'double a[]' with 'const double a[]'. 
Then recompile. What happens? */

/* If you have two arrays of equal length, you cannot simply copy one into the 
other using syntax like 'b = a'. Instead, you have to do some kind of loop. */
void copyDoubleArray(int length, const double a[], double b[]) {
    for (int i = 0; i < length; i += 1)
        b[i] = a[i];
}

/* This function should be pretty self-explanatory. */
void printDoubleArray(int length, const double a[]) {
	for (int i = 0; i < length; i += 1)
		printf("    %f\n", a[i]);
}

/* Have an array of a different type? Then you need a different function. */
void printIntArray(int length, const int a[]) {
	for (int i = 0; i < length; i += 1)
		printf("    %d\n", a[i]);
}

/* This function determines which elements of the array a are integer multiples 
of by the parameter divisor. This function doesn't alter the array a, but it 
does alter the array indices. It is important that indices has already been 
allocated to hold enough ints --- as many as length of them. */
int integerMultipleIndices(
        int length, const int a[], int divisor, int indices[]) {
    int count = 0;
    for (int i = 0; i < length; i += 1)
        if (a[i] % divisor == 0) {
            indices[count] = i;
            count += 1;
        }
    return count;
}

int main(void) {
    /* If you like, you may initialize an array as follows. */
    double myArray[4] = {1.5, 2.3, 3.7, 4.1};
    printf("Here are the elements of myArray:\n");
    printDoubleArray(4, myArray);
    printf("The sum of myArray is %f.\n", sum(4, myArray));
    /* Observe how cumulativeSum alters its array argument. */
    printf("Now let's compute the cumulative sum of myArray:\n");
    cumulativeSum(4, myArray);
    printDoubleArray(4, myArray);
    /* Here's a demo of copyDoubleArray. */
    double myOtherArray[4];
    copyDoubleArray(4, myArray, myOtherArray);
    printf("After copying, here are the elements of myOtherArray:\n");
    printDoubleArray(4, myOtherArray);
    /* Here are some arrays of ints. The first one is allocated and 
    initialized. The second one is allocated but not initialized. */
    int myInts[7] = {9, 13, 14, 21, -3, 0, -1}, indices[7];
    printf("Here is myInts, exactly as we initialized it.\n");
    printIntArray(7, myInts);
    printf("Here is indices, holding whatever it happens to hold.\n");
    printIntArray(7, indices);
    int divisor = 3;
    int count = integerMultipleIndices(7, myInts, divisor, indices);
    printf("Here are the myInts that are divisible by %d.\n", divisor);
    for (int i = 0; i < count; i += 1)
        /* Yes, you can index an array to get an index into another array. By 
        the way, the printIntArray function is not up to this task. */
        printf("myInts[%d] = %d.\n", indices[i], myInts[indices[i]]);
    return 0;
}

