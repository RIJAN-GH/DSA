#include <stdio.h>

void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertion_sort(int arr[], int n) {
    printf("Insertion Sort Steps:\n");
    for (int i = 1; i < n; i++) {
        int current = arr[i];
        int j = i - 1;
        int moved = 0;
        while (j >= 0 && arr[j] > current) {
            arr[j + 1] = arr[j];
            j--;
            moved = 1;
            print_array(arr, n);
        }
        arr[j + 1] = current;
        if (moved) print_array(arr, n);
    }
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    print_array(arr, n);

    insertion_sort(arr, n);

    printf("Sorted array: ");
    print_array(arr, n);

    return 0;
}
