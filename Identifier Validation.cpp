#include <stdio.h>
#include <ctype.h>

int main() {
    char identifier[100];
    int i;
    int isValid = 1;

    printf("Enter identifier: ");
    scanf("%s", identifier);

    // First character must be a letter or underscore
    if (!(isalpha(identifier[0]) || identifier[0] == '_')) {
        isValid = 0;
    } else {
        // Remaining characters must be alphanumeric or underscore
        for (i = 1; identifier[i] != '\0'; i++) {
            if (!(isalnum(identifier[i]) || identifier[i] == '_')) {
                isValid = 0;
                break;
            }
        }
    }

    if (isValid)
        printf("Valid identifier\n");
    else
        printf("Invalid identifier\n");

    return 0;
}

