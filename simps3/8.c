#include <stdio.h>
#include <math.h>

/* Define the integrand here. Change this function for other problems. */
double f(double x) {
    return x*x*x; /* example: f(x) = x^3 */
}

int main() {
    double a, b, h, integral;
    int n, i;
    double sum3 = 0.0, sum2 = 0.0;

    printf("Enter lower limit a: ");
    if (scanf("%lf", &a) != 1) return 0;
    printf("Enter upper limit b: ");
    if (scanf("%lf", &b) != 1) return 0;
    printf("Enter number of subintervals n (must be multiple of 3): ");
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 0 || n % 3 != 0) {
        printf("Error: n must be positive and a multiple of 3.\n");
        return 1;
    }

    h = (b - a) / n;

    /* endpoints */
    double f0 = f(a);
    double fn = f(b);

    /* composite sums */
    for (i = 1; i < n; ++i) {
        double xi = a + i * h;
        if (i % 3 == 0) {
            sum2 += f(xi);    /* coefficients 2 for indices divisible by 3 (but not endpoints) */
        } else {
            sum3 += f(xi);    /* coefficients 3 for other interior points */
        }
    }

    integral = (3.0 * h / 8.0) * (f0 + fn + 3.0 * sum3 + 2.0 * sum2);

    printf("\nComposite Simpson's 3/8 Rule result = %.10f\n", integral);
    return 0;
}
