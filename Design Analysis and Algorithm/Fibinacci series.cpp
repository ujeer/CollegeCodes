#include <stdio.h>

void fibonacci_iterative(int n) {
    int a = 0, b = 1, next;
    printf("Fibonacci Series up to %d terms: ", n);
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d ", a);
            continue;
        }
        if (i == 2) {
            printf("%d ", b);
            continue;
        }
        next = a + b;
        a = b;
        b = next;
        printf("%d ", next);
    }
    printf("\n");
}

int main() {
    int n = 10;
    fibonacci_iterative(n);
    return 0;
}

