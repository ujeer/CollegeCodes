#include <stdio.h>

// Function to print the array
void print_array(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Selection Sort Algorithm
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};  // Predefined dataset
    int n = sizeof(arr) / sizeof(arr[0]);

    // Print the original array
    printf("Before Sorting:\n");
    print_array(arr, n);

    // Perform Selection Sort
    selection_sort(arr, n);

    // Print the sorted array
    printf("After Sorting:\n");
    print_array(arr, n);

    return 0;
}

