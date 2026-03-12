#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int state = 0;
     printf("Enter a string for implementing DFD: ");
    scanf("%s", str);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c != 'a' && c != 'b') {
            printf("Please enter the valid input {a,b}.\n");
            return 1;
        }
        switch(state) {
            case 0:
                if (c == 'a') state = 1;
                break;
            case 1:
                if (c == 'b') state = 2;
                else if (c == 'a') state = 1;
                break;
            case 2:
                if (c == 'a') state = 1;
                else if (c == 'b') state = 0;
                break;
        }
    }
    if (state == 2)
        printf("String accepted (ends with 'ab')\n");
    else
        printf("String not accepted\n");
    return 0;
}

