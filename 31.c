//13.​Write a program that reads three positive numbers a, b and c which represent the lengths of
//the sides of a triangle. Check if they form a valid triangle and categorize it (equilateral,
//sosceles, scalene).
#include <stdio.h>

int main() {
    float a, b, c;

    // Input
    printf("Enter three side lengths of a triangle:\n");
    scanf("%f %f %f", &a, &b, &c);

    // Check for positive values
    if (a <= 0 || b <= 0 || c <= 0) {
        printf("Sides must be positive numbers.\n");
        return 1;
    }

    // Triangle validity check
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        printf("Valid triangle.\n");

        // Type check
        if (a == b && b == c) {
            printf("Type: Equilateral triangle\n");
        } else if (a == b || b == c || a == c) {
            printf("Type: Isosceles triangle\n");
        } else {
            printf("Type: Scalene triangle\n");
        }

    } else {
        printf("Not a valid triangle.\n");
    }

    return 0;
}
