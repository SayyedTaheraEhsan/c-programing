#include <stdio.h>
#include <stdlib.h>

int main() {
    int hour, minute;
    float hour_angle, minute_angle, angle;

    printf("Enter time (HH MM): ");
    scanf("%d %d", &hour, &minute);

    // Adjust hour if greater than 12
    if (hour >= 12) 
        hour -= 12;

    // Calculate angles
    hour_angle = (hour * 30) + (minute * 0.5);   // Each hour = 30°, each min = 0.5°
    minute_angle = minute * 6;                   // Each minute = 6°

    // Find difference
    angle = abs(hour_angle - minute_angle);

    // Take the smaller angle (because clock has 2 sides)
    if (angle > 180)
        angle = 360 - angle;

    printf("Angle between hour and minute hand = %.2f degrees\n", angle);

    return 0;
}
