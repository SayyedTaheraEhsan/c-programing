#include <stdio.h>

int main() {
    int marks[5];
    int total = 0;
    float percentage;

    // Input marks for 5 subjects
    printf("Enter marks for 5 subjects (out of 100):\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        total += marks[i];
    }

    // Calculate percentage
    percentage = (total / 500.0) * 100;

    // Output total marks and percentage
    printf("Total Marks = %d\n", total);
    printf("Percentage = %.2f%%\n", percentage);

    return 0;
}
