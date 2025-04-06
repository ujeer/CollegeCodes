#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// Randomized Quick Sort function
void randomized_quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // Randomly select a pivot
        int random = low + rand() % (high - low);
        int temp = arr[random];
        arr[random] = arr[high];
        arr[high] = temp;

        int pi = partition(arr, low, high);  // Partitioning index
        
        randomized_quick_sort(arr, low, pi - 1);  // Sort elements before partition
        randomized_quick_sort(arr, pi + 1, high);  // Sort elements after partition
    }
}

// Function to print the array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    int arr[] = {10, 7, 8, 9, 1, 5};  // Predefined array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Before Sorting: ");
    print_array(arr, n);  // Print the array before sorting
    
    randomized_quick_sort(arr, 0, n - 1);  // Perform the sorting
    
    printf("After Sorting: ");
    print_array(arr, n);  // Print the array after sorting
    
    return 0;
}

