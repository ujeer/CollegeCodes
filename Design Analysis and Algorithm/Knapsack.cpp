#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct Item {
    int value;
    int weight;
};

// Comparison function to sort items based on value/weight ratio
int compare(const void* a, const void* b) {
    double r1 = ((struct Item*)a)->value / (double)((struct Item*)a)->weight;
    double r2 = ((struct Item*)b)->value / (double)((struct Item*)b)->weight;
    if (r1 < r2)
        return 1;
    else
        return -1;
}

// Function to solve the fractional knapsack problem
double fractional_knapsack(int W, struct Item arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), compare); // Sort items based on value/weight ratio

    int currentWeight = 0;
    double finalValue = 0.0;

    // Print the sorted items
    printf("Sorted items by value/weight ratio:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: Value = %d, Weight = %d, Value/Weight = %.2f\n", i+1, arr[i].value, arr[i].weight, (double)arr[i].value / arr[i].weight);
    }

    // Iterating through items to select them for the knapsack
    printf("\nItems selected:\n");
    for (int i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= W) {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
            printf("Full item taken: Value = %d, Weight = %d\n", arr[i].value, arr[i].weight);
        } else {
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((double)remainingWeight / arr[i].weight);
            printf("Partial item taken: Value = %.2f, Weight = %d (Fraction: %.2f)\n", arr[i].value * ((double)remainingWeight / arr[i].weight), remainingWeight, (double)remainingWeight / arr[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    struct Item arr[] = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50; // Capacity of knapsack
    int n = sizeof(arr) / sizeof(arr[0]);

    // Displaying input
    printf("Input items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: Value = %d, Weight = %d\n", i + 1, arr[i].value, arr[i].weight);
    }

    // Call the function and display result
    printf("\nMaximum value in Knapsack = %.2f\n", fractional_knapsack(W, arr, n));
    return 0;
}

