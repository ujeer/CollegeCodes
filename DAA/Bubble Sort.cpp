#include <stdio.h>

void printArray(int arr[], int n) 
{
    int k;
    for (k = 0; k < n; k++) 
    {
        printf("%4d", arr[k]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n) 
{
    int i, j, temp, swapped;
    
    printf("Pass | Swap | Array State\n");
    printf("----------------------------\n");

    for (i = 0; i < n - 1; i++) 
   {
        swapped = 0; 

        for (j = 0; j < n - 1 - i; j++) 
       {
            if (arr[j] > arr[j + 1]) 
           {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;

                printf("%4d | %4d-%d | ", i + 1, arr[j], arr[j + 1]);
                printArray(arr, n);
            }
        }

        if (!swapped) break;
    }
}






int main() 
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    printf("\nBubble Sort Steps:\n");
    bubbleSort(arr, n);

    printf("\nSorted Array:\n");
    printArray(arr, n);
    return 0;
}

