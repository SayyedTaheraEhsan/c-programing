#include <iostream>
using namespace std;

// Define a class
class Car {
public:
    string brand;
    string model;
    int year;

    // Member function
    void displayInfo() {
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Create an object of Car
    Car car1;

    // Assign values to the object
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2020;

    // Call the member function
    car1.displayInfo();

    return 0;
}
