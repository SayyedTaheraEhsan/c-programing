#include <stdio.h>
#include <string.h>

// Function to encrypt text using Caesar Cipher
void encrypt(char text[], int key) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + key) % 26) + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + key) % 26) + 'a';
        }
    }
}

// Function to decrypt text using Caesar Cipher
void decrypt(char text[], int key) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' - key + 26) % 26) + 'A';
        }
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' - key + 26) % 26) + 'a';
        }
    }
}

int main() {
    char text[100];
    int key;

    printf("Enter a message: ");
    gets(text);  // (For simplicity; safer is fgets)

    printf("Enter key (shift value): ");
    scanf("%d", &key);

    encrypt(text, key);
    printf("Encrypted message: %s\n", text);

    decrypt(text, key);
    printf("Decrypted message: %s\n", text);

    return 0;
}
