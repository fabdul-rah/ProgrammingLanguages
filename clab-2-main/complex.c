#include <stdio.h>


/* Defines a structure named Complex to represent complex numbers.*/

typedef struct {
    double real;
    double imaginary;
} Complex;


/* Multiplies two complex numbers and returns the result as another complex number.*/

Complex multiplyComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return result;
}

/* Main Function to execute the calculation. */

int main() {
    Complex c1, c2, c3;

    printf("Enter real part of c1: ");
    scanf("%lf", &c1.real);
    printf("Enter imaginary part of c1: ");
    scanf("%lf", &c1.imaginary);

    printf("Enter real part of c2: ");
    scanf("%lf", &c2.real);
    printf("Enter imaginary part of c2: ");
    scanf("%lf", &c2.imaginary);

    c3 = multiplyComplex(c1, c2);

    printf("Answer = %10.2f + %10.2f i\n", c3.real, c3.imaginary);

    return 0;
}
