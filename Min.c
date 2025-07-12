// find mining number in an array of numbers using recursion
#include <stdio.h>
int findMin(int arr[], int n) {
    if (n == 1) {
        return arr[0]; 
    }
    int Restmin = findMin(arr + 1, n - 1); 
    return (arr[0] < Restmin) ? arr[0] : Restmin; 
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = findMin(arr, n);
    printf("Minimum number in the array is %d\n",result);
    return 0;
}