#include <stdio.h>
#include <string.h>

int main() {
    char a[100];
    int len;

    printf("Enter a string:\n");
    fgets(a, sizeof(a), stdin); 

    // Check for single-line comment
    if (a[0] == '/' && a[1] == '/') {
        printf("It is a single-line comment.\n");
    }
    // Check for multi-line comment
    else if (a[0] == '/' && a[1] == '*') {
        len = strlen(a);
        if (len >= 4 && a[len - 2] == '*' && a[len - 1] == '/') {
            printf("It is a multi-line comment.\n");
        } else {
            printf("It is not a valid multi-line comment.\n");
        }
    }
    else {
        printf("It is not a comment.\n");
    }
    return 0;
}

