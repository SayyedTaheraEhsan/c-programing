#include <iostream>
#include <string>
using namespace std;

int main() {
    string correctUsername = "user123";
    string correctPassword = "pass123";
    
    string enteredUsername, enteredPassword;

    // Asking for username and password
    cout << "Enter username: ";
    cin >> enteredUsername;
    
    cout << "Enter password: ";
    cin >> enteredPassword;
    
    // Checking if the entered username and password match the correct ones
    if (enteredUsername == correctUsername && enteredPassword == correctPassword) {
        cout << "Login successful!" << endl;
    } else {
        cout << "Login failed. Incorrect username or password." << endl;
    }
    
    return 0;
}
