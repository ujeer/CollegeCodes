#include <stdio.h>

// Function to perform the partitioning
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Last element as pivot
    int i = (low - 1);  // Index of smaller element
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;  // Increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return (i + 1);
}

// Quick Sort function
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partitioning index
        
        quick_sort(arr, low, pi - 1);  // Sort elements before partition
        quick_sort(arr, pi + 1, high);  // Sort elements after partition
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};  // Predefined array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Before Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    quick_sort(arr, 0, n - 1);  // Perform the sorting
    
    printf("After Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

