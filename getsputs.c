#include <stdio.h>

int main() {
    char str[100];  // Buffer to store the input string

    // Read string using gets
    printf("Enter a string: ");
    gets(str);  // Note: gets is unsafe, avoid using it in production code

    // Print string using puts
    puts("You entered:");
    puts(str);

    return 0;
}
