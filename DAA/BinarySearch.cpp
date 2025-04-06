#include <stdio.h>

// Function to print the array
void print_array(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Iterative Binary Search
int binary_search_iterative(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Recursive Binary Search
int binary_search_recursive(int arr[], int left, int right, int target) {
    if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
            return binary_search_recursive(arr, left, mid - 1, target);
        return binary_search_recursive(arr, mid + 1, right, target);
    }
    return -1;
}

int main() {
    int arr[] = {2, 5, 7, 10, 15, 20, 25};  // Predefined sorted dataset
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;  // Element to search

    // Print the array before searching
    print_array(arr, n);

    // Perform iterative and recursive binary searches
    int iterative_result = binary_search_iterative(arr, n, target);
    int recursive_result = binary_search_recursive(arr, 0, n - 1, target);

    // Display results
    if (iterative_result != -1)
        printf("Iterative Binary Search: Element %d found at index: %d\n", target, iterative_result);
    else
        printf("Iterative Binary Search: Element %d not found\n", target);

    if (recursive_result != -1)
        printf("Recursive Binary Search: Element %d found at index: %d\n", target, recursive_result);
    else
        printf("Recursive Binary Search: Element %d not found\n", target);

    return 0;
}

