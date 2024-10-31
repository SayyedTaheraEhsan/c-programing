#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "student_database.dat"
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int age;
    float gpa;
} Student;

void addStudent();
void displayStudents();
void searchStudent();

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Student Database ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    Student s;
    FILE *file = fopen(FILENAME, "ab");
    
    if (!file) {
        perror("Error opening file");
        return;
    }
    
    printf("Enter name: ");
    getchar(); // Clear newline from previous input
    fgets(s.name, NAME_LENGTH, stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove trailing newline
    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Enter GPA: ");
    scanf("%f", &s.gpa);
    
    fwrite(&s, sizeof(Student), 1, file);
    fclose(file);
    
    printf("Student added successfully!\n");
}

void displayStudents() {
    Student s;
    FILE *file = fopen(FILENAME, "rb");
    
    if (!file) {
        perror("Error opening file");
        return;
    }
    
    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(Student), 1, file)) {
        printf("Name: %s, Age: %d, GPA: %.2f\n", s.name, s.age, s.gpa);
    }
    
    fclose(file);
}

void searchStudent() {
    char searchName[NAME_LENGTH];
    Student s;
    int found = 0;
    FILE *file = fopen(FILENAME, "rb");
    
    if (!file) {
        perror("Error opening file");
        return;
    }
    
    printf("Enter name to search: ");
    getchar(); // Clear newline from previous input
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0; // Remove trailing newline
    
    while (fread(&s, sizeof(Student), 1, file)) {
        if (strcmp(s.name, searchName) == 0) {
            printf("Record found:\n");
            printf("Name: %s, Age: %d, GPA: %.2f\n", s.name, s.age, s.gpa);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("No record found with the name '%s'.\n", searchName);
    }
    
    fclose(file);
}
