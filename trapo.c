#include <stdio.h>
#include <math.h>

// Define the function f(x) here
double f(double x) {
    return 1 / (1 + x*x);   // Example: f(x) = 1 / (1 + x^2)
}

int main() {
    double a, b;   // Limits of integration
    int n;         // Number of intervals
    double h, sum = 0.0;
    int i;

    // Input values
    printf("Enter lower limit a: ");
    scanf("%lf", &a);

    printf("Enter upper limit b: ");
    scanf("%lf", &b);

    printf("Enter number of intervals n: ");
    scanf("%d", &n);

    // Step size
    h = (b - a) / n;

    // Apply Trapezoidal Rule
    sum = f(a) + f(b);

    for (i = 1; i < n; i++) {
        sum += 2 * f(a + i * h);
    }

    sum = (h / 2) * sum;

    // Output result
    printf("Approximate integral = %lf\n", sum);

    return 0;
}
