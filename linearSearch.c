#include <stdio.h>

// Function to print array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Linear Search function
int linear_search(int arr[], int size, int key) {
    printf("Linear Search Steps:\n");
    for (int i = 0; i < size; i++) {
        printf("Checking index %d: %d\n", i, arr[i]);
        if (arr[i] == key)
            return i; // Found
    }
    return -1; // Not found
}

int main() {
    int arr[] = {5, 2, 9, 1, 5, 6};  // Unsorted array
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;  // Value to search

    printf("Array: ");
    print_array(arr, n);

    int result = linear_search(arr, n, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found.\n", key);

    return 0;
}
