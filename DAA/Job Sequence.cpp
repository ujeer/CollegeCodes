#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparison function to sort jobs in decreasing order of profit
int compare(const void* a, const void* b) {
    return ((struct Job*)b)->profit - ((struct Job*)a)->profit;
}

// Function to find the job sequence with maximum profit
void job_sequencing(struct Job arr[], int n) {
    qsort(arr, n, sizeof(arr[0]), compare);  // Sort jobs by profit in descending order

    int result[n];  // Array to store the sequence of jobs
    bool slot[n];   // Array to check if a slot is already filled
    for (int i = 0; i < n; i++)
        slot[i] = false;

    // Sequence jobs in slots to maximize profit
    for (int i = 0; i < n; i++) {
        // Find a free slot for this job
        for (int j = arr[i].deadline - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    // Print the job sequence with maximum profit
    printf("Job sequence with maximum profit:\n");
    for (int i = 0; i < n; i++) {
        if (slot[i]) {
            printf("Job %d (Profit: %d) -> ", arr[result[i]].id, arr[result[i]].profit);
        }
    }
    printf("\n");
}

int main() {
    struct Job arr[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Display input jobs
    printf("Input Jobs (ID, Deadline, Profit):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: Deadline = %d, Profit = %d\n", arr[i].id, arr[i].deadline, arr[i].profit);
    }

    // Call the job sequencing function
    job_sequencing(arr, n);
    return 0;
}

