/* shift_cipher.c
   Simple Shift (Caesar) cipher in C.
   - Handles uppercase and lowercase letters
   - Leaves non-letter characters unchanged
   - Accepts positive key (0..25). Decryption uses inverse shift.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encryptShift(const char *plain, char *cipher, int key) {
    int i;
    for (i = 0; plain[i] != '\0'; ++i) {
        char ch = plain[i];
        if (isupper((unsigned char)ch)) {
            cipher[i] = (char)(((ch - 'A' + key) % 26) + 'A');
        } else if (islower((unsigned char)ch)) {
            cipher[i] = (char)(((ch - 'a' + key) % 26) + 'a');
        } else {
            cipher[i] = ch; // non-alphabetic characters unchanged
        }
    }
    cipher[i] = '\0';
}

void decryptShift(const char *cipher, char *plain, int key) {
    int i;
    for (i = 0; cipher[i] != '\0'; ++i) {
        char ch = cipher[i];
        if (isupper((unsigned char)ch)) {
            plain[i] = (char)(((ch - 'A' - key + 26) % 26) + 'A');
        } else if (islower((unsigned char)ch)) {
            plain[i] = (char)(((ch - 'a' - key + 26) % 26) + 'a');
        } else {
            plain[i] = ch;
        }
    }
    plain[i] = '\0';
}

int main(void) {
    char input[1024];
    char output[1024];
    int key;
    int choice;

    printf("Shift (Caesar) Cipher\n");
    printf("---------------------\n");
    printf("Enter text (max 1023 chars):\n");
    if (!fgets(input, sizeof(input), stdin)) return 0;
    // remove trailing newline if any
    input[strcspn(input, "\n")] = '\0';

    printf("Enter key (0-25): ");
    if (scanf("%d", &key) != 1) return 0;
    key %= 26;
    if (key < 0) key += 26;

    printf("Choose: 1) Encrypt   2) Decrypt\n");
    if (scanf("%d", &choice) != 1) return 0;

    if (choice == 1) {
        encryptShift(input, output, key);
        printf("\nEncrypted text:\n%s\n", output);
    } else if (choice == 2) {
        decryptShift(input, output, key);
        printf("\nDecrypted text:\n%s\n", output);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
