#include <iostream>
using namespace std;

// Class definition
class Person {
    // Private members
    private:
        string name;
        int age;

    // Public members
    public:
        // Constructor
        Person(string n, int a) {
            name = n;
            age = a;
        }

        // Member function to display details
        void display() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }

        // Getter functions
        string getName() {
            return name;
        }

        int getAge() {
            return age;
        }

        // Setter functions
        void setName(string n) {
            name = n;
        }

        void setAge(int a) {
            age = a;
        }
};

// Main function
int main() {
    // Create an object of the class
    Person person1("John Doe", 25);
    
    // Display the details of the person
    person1.display();
    
    // Modify the details using setter functions
    person1.setName("Jane Smith");
    person1.setAge(30);

    // Display the updated details
    cout << "\nUpdated details:" << endl;
    person1.display();

    return 0;
}
