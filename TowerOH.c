// write code to perform tower of Hanoi of nth disks (shift from source to destination using auxiliary)
#include <stdio.h>
void TOH(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    TOH(n - 1, source, auxiliary, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    TOH(n - 1, auxiliary, destination, source);
}
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    TOH(n, 'A', 'C', 'B');  // A, B and C are names of rods
    return 0;
}
