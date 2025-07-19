#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void selection_sort(int arr[], int n) {
    printf("Selection Sort Steps:\n");
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        if (min != i) {
            int t = arr[i]; arr[i] = arr[min]; arr[min] = t;
            print_array(arr, n);
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6}, 
    n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: "); 
    print_array(arr, n);
    selection_sort(arr, n);
    printf("Sorted array: "); 
    print_array(arr, n);
    return 0;
}
