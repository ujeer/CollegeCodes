#include <stdio.h>

int main() {
    int Xn = 13;
    int a = 15;
    int c = 7;
    int m = 1000;
    int X_next;
		printf("\n By Reeju Pandit\n");
    printf("Generated random numbers using Multiplicative Congruential Method:\n");

    for(int i = 0; i < 100; i++) {
        X_next = (a * Xn + c) % m;
        printf("%d ", X_next);
        Xn = X_next;
    }

    return 0;
}

