#include <stdio.h>
#include <math.h>

// Example function: f(x) = x^2
double f(double x) {
    return x * x;
}

int main() {
    int n, i;
    double a, b, h, sum = 0.0;

    // Input values
    printf("Enter lower limit a: ");
    scanf("%lf", &a);

    printf("Enter upper limit b: ");
    scanf("%lf", &b);

    printf("Enter number of intervals (even n): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Number of intervals must be even!\n");
        return 1;
    }

    h = (b - a) / n;

    // Simpson's 1/3 Rule formula
    sum = f(a) + f(b);

    for (i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }

    sum = (h / 3) * sum;

    printf("Approximate integral = %lf\n", sum);

    return 0;
}
