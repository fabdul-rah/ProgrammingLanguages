#include <stdio.h> 

int main() {
    char c = 'a';
    int i = 5;
    long l = (1 << 16) + 1;
    float f = 42.67;
    double d = 109.2;
    char *s = "hello";
    int *p = &i; 
    int x = 15;
    int y = 87;

    int yminx = y - x;

    printf("Here is an int %i and a char %c and a long %li\n", i, c, l);
    printf("and a float %f and a double %f\n", f, d);
    printf("and a string %s and a pointer %p\n", s, (void*)p);
    printf("%i + %i = %i.\n", y, x, yminx);
    
    return 0;
}