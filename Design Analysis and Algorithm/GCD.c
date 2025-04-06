#include <stdio.h>

// Iterative GCD
int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Recursive GCD
int gcd_recursive(int a, int b) {
    if (b == 0)
        return a;
    return gcd_recursive(b, a % b);
}

int main() {
    int a = 56, b = 98;
    printf("Iterative GCD of %d and %d is: %d\n", a, b, gcd_iterative(a, b));
    printf("Recursive GCD of %d and %d is: %d\n", a, b, gcd_recursive(a, b));
    return 0;
}

