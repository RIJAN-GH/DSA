// find maximum number in an array of numbers using recursion
#include <stdio.h>
int findMax(int arr[], int n) {
    if (n == 1) {
        return arr[0]; 
    }
    int Restmax = findMax(arr + 1, n - 1); 
    return (arr[0] > Restmax) ? arr[0] : Restmax; 
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
    int result = findMax(arr, n);
    printf("Maximum number in the array is %d\n",result);
    return 0;
}