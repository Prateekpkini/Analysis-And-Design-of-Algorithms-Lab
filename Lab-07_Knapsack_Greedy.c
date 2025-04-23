/*Design and implement C/C++ Program to solve discrete Knapsack and
continuous Knapsack problems using greedy approximation method.*/
#include <stdio.h>

int main() {
    int n, max_qty, mode;
    float sum = 0.0;

    int weight[20], value[20];
    float ratio[20];

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter the weights of each item: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weight[i]);
    }

    printf("Enter the values of each item: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value[i]);
    }

    printf("Enter maximum capacity of the knapsack: ");
    scanf("%d", &max_qty);

    printf("Choose mode:\n1. Discrete (0 or full weight)\n2. Continuous (fractional allowed)\nEnter choice: ");
    scanf("%d", &mode);

    // Calculate value/weight ratio
    for (int i = 0; i < n; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    int remaining = max_qty;

    while (remaining > 0) {
        int maxIndex = -1;
        float maxRatio = 0.0;

        // Find the item with the highest value/weight ratio
        for (int i = 0; i < n; i++) {
            if (value[i] > 0 && ratio[i] > maxRatio) {
                maxRatio = ratio[i];
                maxIndex = i;
            }
        }

        // If no valid item is left
        if (maxIndex == -1)
            break;

        if (mode == 1) { // Discrete mode
            if (weight[maxIndex] <= remaining) {
                printf("Item %d added completely: %d units\n", maxIndex + 1, weight[maxIndex]);
                remaining -= weight[maxIndex];
                sum += value[maxIndex];
            }
            // Mark item as used
            value[maxIndex] = 0;
        } else { // Continuous mode
            if (weight[maxIndex] <= remaining) {
                printf("Item %d added completely: %d units\n", maxIndex + 1, weight[maxIndex]);
                remaining -= weight[maxIndex];
                sum += value[maxIndex];
            } else {
                printf("Item %d added partially: %d units\n", maxIndex + 1, remaining);
                sum += ratio[maxIndex] * remaining;
                remaining = 0;
            }
            value[maxIndex] = 0;
        }
    }

    printf("The total profit is: %.2f\n", sum);
    return 0;
}
