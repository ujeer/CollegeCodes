#include <stdio.h>
#include <string.h>
#include <ctype.h>

int tempNo = 1;

void generateCode(char expr[]) {
    int len = strlen(expr);
    char left[10], right[10];
    char temp[2] = "T";

    // Process * and / first
    for(int i=0; i<len; i++) {
        if(expr[i] == '*' || expr[i] == '/') {
            left[0] = expr[i-1];
            left[1] = '\0';
            right[0] = expr[i+1];
            right[1] = '\0';

            printf("T%d := %s %c %s\n", tempNo, left, expr[i], right);

            expr[i-1] = 'T';
            expr[i] = '\0';
            expr[i+1] = '\0';
            tempNo++;
        }
    }

    // Then process + and -
    for(int i=0; i<len; i++) {
        if(expr[i] == '+' || expr[i] == '-') {
            left[0] = expr[i-1];
            left[1] = '\0';
            right[0] = expr[i+1];
            right[1] = '\0';

            printf("T%d := %s %c %s\n", tempNo, left, expr[i], right);

            expr[i-1] = 'T';
            expr[i] = '\0';
            expr[i+1] = '\0';
            tempNo++;
        }
    }
}

int main() {
    char expr[50];
    printf("Enter the expression: ");
    scanf("%s", expr);

    printf("Intermediate code:\n");
    generateCode(expr);

    return 0;
}


