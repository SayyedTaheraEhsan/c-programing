#include <stdio.h>
#include <string.h>

// Dummy credentials for illustration
const char *USERNAME = "admin";
const char *PASSWORD = "password123";

// Function to authenticate the user
int authenticate(const char *username, const char *password) {
    if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
        return 1; // Authentication successful
    }
    return 0; // Authentication failed
}

int main() {
    char username[50];
    char password[50];

    printf("Enter Username: ");
    scanf("%s", username);

    printf("Enter Password: ");
    scanf("%s", password);

    // Authenticate user
    if (authenticate(username, password)) {
        printf("Login successful!\n");
    } else {
        printf("Invalid username or password.\n");
    }

    return 0;
}
