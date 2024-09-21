#include <stdio.h>

void coinChange(int coins[], int n, int amount) {
    int count = 0;

    // Sort coins in descending order (optional, but helpful for greedy approach)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (coins[j] < coins[j + 1]) {
                int temp = coins[j];
                coins[j] = coins[j + 1];
                coins[j + 1] = temp;
            }
        }
    }

    printf("Coins used to make %d:\n", amount);
    for (int i = 0; i < n; i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
            printf("%d ", coins[i]);
        }
    }

    printf("\nTotal coins used: %d\n", count);
}

int main() {
    int coins[] = {1, 5, 10, 25}; // coin denominations
    int amount = 63;              // target amount
    int n = sizeof(coins) / sizeof(coins[0]);

    coinChange(coins, n, amount);

    return 0;
}
