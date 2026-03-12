#include <stdio.h>

void print_array(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {5, 3, 8, 6, 2};  // Predefined dataset
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 6;  // Element to be searched

    print_array(arr, n);

    int result = linear_search(arr, n, target);
    if (result != -1)
        printf("Element %d found at index: %d\n", target, result);
    else
        printf("Element %d not found\n", target);

    return 0;
}

