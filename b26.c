#include <iostream>
#include <string>
using namespace std;

int main() {
    string correctUsername = "admin";
    string correctPassword = "password123";
    string username, password;

    // Prompt user for username
    cout << "Enter username: ";
    cin >> username;

    // Prompt user for password
    cout << "Enter password: ";
    cin >> password;

    // Check if the entered username and password are correct
    if (username == correctUsername && password == correctPassword) {
