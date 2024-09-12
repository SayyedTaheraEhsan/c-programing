#include <stdio.h>

int main() {
    int value = 10;
    int *ptr = &value;

    // Print initial values
    printf("Initial value of the integer: %d\n", *ptr);
    printf("Initial pointer address: %p\n", (void*)ptr);

    // Pre-increment the pointer using brackets
    printf("\nUsing pre-increment with brackets:\n");
    printf("Before increment: Pointer address = %p, Value = %d\n", (void*)ptr, *ptr);
    (*ptr)++;
    printf("After increment: Pointer address = %p, Value = %d\n", (void*)ptr, *ptr);

    // Reset the value
    value = 10;
    ptr = &value;

    // Post-increment the pointer using brackets
    printf("\nUsing post-increment with brackets:\n");
    printf("Before increment: Pointer address = %p, Value = %d\n", (void*)ptr, *ptr);
    int temp = (*ptr)++;
    printf("After increment: Pointer address = %p, Value = %d\n", (void*)ptr, *ptr);
    printf("Value of temp (post-incremented value): %d\n", temp);

    // Reset the value
    value = 10;
    ptr = &value;

    // Pre-increment the pointer without using brackets
    printf("\nUsing pre-increment without brackets:\n");
    printf("Before increment: Pointer address = %p, Value = %d\n", (void*)ptr, *ptr);
    ++(*ptr);
    printf("After increment: Pointer address = %p, Value = %d\n", (void*)ptr, *ptr);

    // Reset the value
    value = 10;
    ptr = &value;

    // Post-increment the pointer without using brackets
    printf("\nUsing post-increment without brackets:\n");
    printf("Before increment: Pointer address = %p, Value = %d\n", (void*)ptr, *ptr);
    temp = (*ptr)++;
    printf("After increment: Pointer address = %p, Value = %d\n", (void*)ptr, *ptr);
    printf("Value of temp (post-incremented value): %d\n", temp);

    return 0;
}