#include <stdio.h>

int main() {
    // Step a: Declare a pointer of type void and assign NULL to it
    void *voidPtr = NULL;
    
    // Step b: Print the value of the pointer variable
    printf("The value of the void pointer (should be NULL): %p\n", (void*)voidPtr);
    
    // Declare an integer variable and assign its address to the void pointer
    int intValue = 42;
    voidPtr = &intValue;
    
    // Step c: Print the value and address of the void pointer
    printf("The address stored in the void pointer: %p\n", (void*)voidPtr);
    printf("The value stored at the address (without typecast): %d\n", *(int*)voidPtr);
    
    // Step e: Print the value of the int variable using the void pointer (without typecast)
    // Already done in Step c with typecast to int pointer
    
    // Step f: Typecast the void pointer to int pointer and print the value of the integer variable
    int *intPtr = (int*)voidPtr;
    printf("The value of the integer variable using int pointer: %d\n", *intPtr);
    
    // Declare a double variable and assign its address to the void pointer
    double doubleValue = 3.14159;
    voidPtr = &doubleValue;
    
    // Step g: Print the value of the double variable using the void pointer (with typecast)
    double *doublePtr = (double*)voidPtr;
    printf("The value of the double variable: %f\n", *doublePtr);
    
    // Declare a float variable and assign its address to the void pointer
    float floatValue = 2.718f;
    voidPtr = &floatValue;
    
    // Step h: Print the value of the float variable using the void pointer (with typecast)
    float *floatPtr = (float*)voidPtr;
    printf("The value of the float variable: %f\n", *floatPtr);
    
    // Declare a long int variable and assign its address to the void pointer
    long int longIntValue = 1234567890L;
    voidPtr = &longIntValue;
    
    // Step i: Print the value of the long int variable using the void pointer (with typecast)
    long int *longIntPtr = (long int*)voidPtr;
    printf("The value of the long int variable: %ld\n", *longIntPtr);
    
    return 0;
}