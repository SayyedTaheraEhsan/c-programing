#include <stdio.h>

int main() {
    int *ptr = NULL;  // Step a: Declare a pointer and assign NULL to it
    
    // Step b: Print the value of the pointer variable
    printf("The value of the pointer (should be NULL): %p\n", (void*)ptr);
    
    int value = 42;   // An integer variable
    ptr = &value;     // Step c: Assign the address of the integer variable to the pointer
    
    // Step d: Print the value of the pointer variable
    printf("The value of the pointer (address of 'value'): %p\n", (void*)ptr);
    printf("The value pointed to by the pointer: %d\n", *ptr);
    
    return 0;
}