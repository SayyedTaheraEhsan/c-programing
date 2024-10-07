#include <stdio.h>
#include <string.h>

// Define a structure to represent a student
struct Student {
    int id;
    char name[50];
    float grade;
};

int main() {
    // Create an instance of the Student structure
    struct Student student1;

    // Assign values to the structure's members
    student1.id = 1;
    strcpy(student1.name, "Alice");
    student1.grade = 89.5;

    // Print the structure's members
    printf("Student ID: %d\n", student1.id);
    printf("Student Name: %s\n", student1.name);
    printf("Student Grade: %.2f\n", student1.grade);

    return 0;
}
