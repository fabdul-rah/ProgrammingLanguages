#include <stdio.h>


int main(){
    /* x is a double. myPtr is a pointer-to-double. */
    // double x = 3.14;
    // double *myPtr;
    // /* The printf code for pointers is '%p'. It prints the pointer as an 
    // integer in hexadecimal. Because we have not initialized myPtr, its current 
    // value is garbage. It will look like garbage, unless it happens to be 0, in 
    // which case it might look like '(nil)'. */
    // printf("myPtr = %p.\n", myPtr);
    // /* Use & to get the address of x, and store that address in myPtr. */
    // myPtr = &x;
    // /* Now myPtr contains a meaningful value. */
    // printf("myPtr = %p.\n", myPtr);
    // /* Use * to get the contents pointed to by myPtr. */
    // printf("The value, to which myPtr points, is %f.\n", *myPtr);
    // printf("Because myPtr points to x, it's the same value as %f.\n", x);
    // /* Alter the contents via myPtr. Notice that x changes. */
    // *myPtr += 3.0;
    // printf("Now *myPtr = %f, and x = %f.\n", *myPtr, x);
    // /* Alter the contents via x. Notice that *myPtr changes. */
    // x += 3.0;
    // printf("Now *myPtr = %f, and x = %f.\n", *myPtr, x);
    // /* But this arithmetic has not changed myPtr itself. It points to the same 
    // memory location as it always has. It's just the contents stored at that 
    // location that have changed. */
    // printf("myPtr = %p.\n", myPtr);
    // /* Change myPtr to NULL, which is another way of saying 0. The memory 
    // location with address 0 is reserved. It is never an actual memory location 
    // for a variable in your program. */
    // myPtr = NULL;
    // printf("myPtr = %p.\n", myPtr);
    // /* If you uncomment the next line, the compiler will not complain, but the 
    // program will generate an fatal error at runtime. */
    // /*printf("*myPtr = %f.\n", *myPtr);*/
    // /* x is still there. It doesn't care that myPtr has been nullified. */
    // printf("x = %f.\n", x);

    /* Remember that a double * is not a double, but rather an address. And an 
    int * is not an int, but rather an address. So you should not be surprised 
    to learn that double * and int * have the same size. */
    // printf("sizeof(double) = %d, sizeof(double *) = %d.\n", 
    //     (int)sizeof(double), (int)sizeof(double *));
    // printf("sizeof(int) = %d, sizeof(int *) = %d.\n", 
    //     (int)sizeof(int), (int)sizeof(int *));
    // /* On a '64-bit computer', all memory addresses are 8 bytes. On a 
    // '32-bit computer', they are 4 bytes. Which one are you using? */
    // printf("sizeof(char) = %d, sizeof(char *) = %d.\n", 
    //     (int)sizeof(char), (int)sizeof(char *));
    /* Can you have pointers to pointers? Yep. */
    int y = 18, *yPtr, **yPtrPtr;
    yPtr = &y;
    yPtrPtr = &yPtr;
    printf("%d = %d = %d.\n", y, *yPtr, **yPtrPtr);
    printf("%p = %p = %p.\n", &y, yPtr, *yPtrPtr);
    printf("%p = %p.\n", &yPtr, yPtrPtr);
    /* If you uncomment the next line, it will not work, because && is the 
    logical AND operator, which requires two operands. (The && operator has 
    nothing to do with the & operator or pointers.) */
    /*printf("&&y = %p.\n", &&y);*/
    /* If you uncomment the next line, it will not work. The value of the 
    subexpression &y does not have a well-defined memory location. (Depending 
    on how the code is compiled, it might not even reside in RAM. It might just 
    reside in a CPU register.) So you're not allowed to ask what that location 
    is. Try the next line, and see how the compiler complains. */
    /*printf("&(&y) = %p.\n", &(&y));*/

*c = *c / 10;
}