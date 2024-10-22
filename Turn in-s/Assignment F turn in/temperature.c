#include <stdio.h> 



int main() {
    float fahrenheit, celsius;
    const float ABSOLUTE_ZERO = -459.67;

    printf("What is the temperature in degrees Fahrenheit? ");
    scanf("%f", &fahrenheit);

    // Check for invalid temperature
    if (fahrenheit < ABSOLUTE_ZERO) {
        printf("Invalid temperature.\n");
    } else {
        // Convert Fahrenheit to Celsius
        celsius = (fahrenheit - 32) * (5.0 / 9.0);

        // Print the result
        printf("%.6f degrees Fahrenheit is %.6f degrees Celsius.\n", fahrenheit, celsius);
    }

    return 0;
}
