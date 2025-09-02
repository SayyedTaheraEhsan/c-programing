#include <stdio.h>
#include <math.h>

int main() {
    double trueValue, approxValue;
    double absError, relError, perError;

    // Input values
    printf("Enter True Value: ");
    scanf("%lf", &trueValue);

    printf("Enter Approximate Value: ");
    scanf("%lf", &approxValue);

    // Calculate errors
    absError = fabs(trueValue - approxValue);
    relError = absError / fabs(trueValue);
    perError = relError * 100;

    // Output results
    printf("\nAbsolute Error   = %lf", absError);
    printf("\nRelative Error   = %lf", relError);
    printf("\nPercentage Error = %lf%%\n", perError);

    return 0;
}
