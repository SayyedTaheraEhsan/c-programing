#include <stdio.h>
#include <unistd.h> // For sleep() function

int main() {
    int seconds;

    printf("Enter countdown time in seconds: ");
    scanf("%d", &seconds);

    for (int i = seconds; i >= 0; i--) {
        printf("%d\n", i);
        sleep(1); // Sleep for 1 second
    }

    printf("Time's up!\n");
    return 0;
}
