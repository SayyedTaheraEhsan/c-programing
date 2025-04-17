#include <iostream>
#include <cmath>

// Function to integrate
double f(double x) {
    return std::sin(x);  // You can change this to any function
}

// Trapezoidal Rule
double trapezoidal(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        sum += 2 * f(a + i * h);
    }

    return (h / 2) * sum;
}

int main() {
    double a, b;
    int n;

    std::cout << "Enter lower limit a: ";
    std::cin >> a;
    std::cout << "Enter upper limit b: ";
    std::cin >> b;
    std::cout << "Enter number of intervals n: ";
    std::cin >> n;

    double result = trapezoidal(a, b, n);

    std::cout << "Approximate integral: " << result << std::endl;

    return 0;
}
