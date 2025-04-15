#include <iostream>
#include <cmath>
using namespace std;

// Function to differentiate/integrate
double f(double x) {
    return x * x; // Example: f(x) = x^2
}

// Numerical derivative using central difference
double derivative(double x, double h = 0.0001) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

// Numerical integration using trapezoidal rule
double integrate(double a, double b, int n = 1000) {
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
        sum += f(a + i * h);
    }
    return sum * h;
}

int main() {
    double x, a, b;

    cout << "Enter the point to differentiate at (x): ";
    cin >> x;
    cout << "f'(x) = " << derivative(x) << endl;

    cout << "\nEnter limits a and b to integrate from a to b:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "Integral of f(x) from " << a << " to " << b << " = " << integrate(a, b
