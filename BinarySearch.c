#include <stdio.h>

// Function to print array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Binary Search function
int binary_search(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    printf("Binary Search Steps:\n");

    while (left <= right) {
        int mid = left + (right - left) / 2;
        printf("Checking middle index %d: %d\n", mid, arr[mid]);

        if (arr[mid] == key)
            return mid; // Found
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1; // Not found
}

int main() {
    int arr[] = {1, 2, 5, 5, 6, 9};  // Sorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;  // Value to search

    printf("Sorted Array: ");
    print_array(arr, n);

    int result = binary_search(arr, n, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found.\n", key);

    return 0;
}
