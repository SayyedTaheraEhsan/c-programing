#include <stdio.h>

int main() {
    int var = 10;
    int *ptr; // Declaration of pointer

    ptr = &var; // Pointer ptr stores the address of var

    printf("Value of var: %d\n", var);
    printf("Address of var: %p\n", &var);
    printf("Value stored in ptr (address of var): %p\n", ptr);
    printf("Value pointed to by ptr (value of var): %d\n", *ptr);

    return 0;
}
