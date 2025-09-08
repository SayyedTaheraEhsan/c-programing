#include <stdio.h>

int main() {
    float celsius, fahrenheit;

    // Input from user
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);

    // Formula to convert Celsius to Fahrenheit
    fahrenheit = (celsius * 9 / 5) + 32;

    // Output result
    printf("Temperature in Fahrenheit = %.2f\n", fahrenheit);

    return 0;
}
