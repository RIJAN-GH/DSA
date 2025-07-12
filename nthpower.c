// code in c to find nth power of a number using recursion (2,3) should display 8
#include <stdio.h>
int power(int num, int pow) {
    if (pow == 0) {
        return 1;
    } else {
        return num * power(num, pow - 1);
    }
}
int main() {
    int num, pow;
    printf("Enter number:");
    scanf("%d", &num);
    printf("Enter power of number: ");
    scanf("%d", &pow);
    if (pow < 0) {
        printf("Power should be a non-negative integer.\n");
    } else {
        int result = power(num, pow);
        printf("%d to the power of %d is %d\n", num, pow, result);
    }
    return 0;
}