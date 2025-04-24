#include <iostream>
using namespace std;

int main() {
    int num;
    long long factorial = 1;

    // Ask for user input
    cout << "Enter a positive integer: ";
    cin >> num;

    // Check if the input is valid (positive integer)
    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        // Calculate factorial using a for loop
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }

        // Display the result
        cout << "Factorial of " << num << " is " << factorial << endl;
    }

    return 0;
}
