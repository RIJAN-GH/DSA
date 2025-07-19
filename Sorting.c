#include <stdio.h>

void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubble_sort(int arr[], int n) {
    printf("Bubble Sort Steps:\n");
    int i, j, tmp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                print_array(arr, n);
            }
        }
    }
}

void insertion_sort(int arr[], int n) {
    printf("Insertion Sort Steps:\n");
    int i, j, current, moved;
    for (i = 1; i < n; i++) {
        current = arr[i];
        j = i - 1;
        moved = 0;
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

void selection_sort(int arr[], int n) {
    printf("Selection Sort Steps:\n");
    int i, j, smallest, tmp;
    for (i = 0; i < n - 1; i++) {
        smallest = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[smallest])
                smallest = j;
        }
        if (smallest != i) {
            tmp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = tmp;
            print_array(arr, n);
        }
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[100], R[100];
    int i, j, k;

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
        print_array(arr + left, right - left + 1);
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void copy_array(int src[], int dest[], int n) {
    int i;
    for (i = 0; i < n; i++)
        dest[i] = src[i];
}

int main() {
    int original[100], temp[100];
    int n, choice, repeat;
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &original[i]);

    do {
        copy_array(original, temp, n);

        printf("\nChoose sorting algorithm:\n");
        printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bubble_sort(temp, n);
                break;
            case 2:
                insertion_sort(temp, n);
                break;
            case 3:
                selection_sort(temp, n);
                break;
            case 4:
                printf("Merge Sort Steps:\n");
                merge_sort(temp, 0, n - 1);
                print_array(temp, n);
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }

        printf("Sorted array: ");
        print_array(temp, n);

        printf("\nDo you want to sort again?\n1. Yes\n2. No (Exit)\nEnter your choice: ");
        scanf("%d", &repeat);

    } while (repeat == 1);

    printf("\nProgram exited. Thank you!\n");
    return 0;
}