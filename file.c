#include <iostream>
#include <fstream>   // for file handling
using namespace std;

int main() {
    // Create an output file stream (to write into a file)
    ofstream outFile("example.txt");

    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    // Write some data into the file
    outFile << "Hello, this is a file handling example in C++.\n";
    outFile << "We are writing this text into example.txt file.\n";

    outFile.close();  // close after writing
    cout << "Data written to file successfully.\n";

    // Now, create an input file stream (to read from a file)
    ifstream inFile("example.txt");

    if (!inFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    cout << "\nReading data from file:\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close();  // close after reading

    return 0;
}
