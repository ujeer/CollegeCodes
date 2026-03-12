#include <stdio.h>
#include <ctype.h>

int main() {
    char input[100];
    int i = 0;

    printf("Enter an expression: ");
    fgets(input, sizeof(input), stdin);

    printf("\nTokens:\n");

    while (input[i] != '\0') {
        if (isalpha(input[i])) {
            printf("Identifier: %c\n", input[i]);
        }
        else if (isdigit(input[i])) {
            printf("Number: %c\n", input[i]);
        }
        else if (input[i] == ' ' || input[i] == '\n') {
            // Skip whitespace and newline
        }
        else {
            printf("Special Symbol: %c\n", input[i]);
        }
        i++;
    }

    return 0;
}

