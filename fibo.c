#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num;
    printf("Enter the position of the Fibonacci number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Invalid input! Please enter a non-negative number.\n");
    } else {
        int result = fibonacci(num);
        printf("Fibonacci number at position %d is: %d\n", num, result);
    }

    return 0;
}

