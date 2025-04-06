#include <stdio.h>

void min_max_sort(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int min_index = i, max_index = i;
        // Find the minimum and maximum in the remaining unsorted part
        for (int j = i + 1; j < n - i; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }

        // Swap the minimum element with the first element
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

        // Adjust the maximum index if it was swapped
        if (max_index == i) {
            max_index = min_index;
        }

        // Swap the maximum element with the last element
        temp = arr[n - 1 - i];
        arr[n - 1 - i] = arr[max_index];
        arr[max_index] = temp;
    }
}

int main() {
    int arr[] = {3, 5, 1, 10, 4};  // Predefined array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Before Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    min_max_sort(arr, n);  // Perform the sorting
    
    printf("After Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

