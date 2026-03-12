#include <stdio.h>
#include <string.h>

char op[2], arg1[5], arg2[5], result[5];

int main()
{
    FILE *fp1, *fp2;
    
    // Try to open input.txt in the current folder
    fp1 = fopen("input.txt", "r");
    if (fp1 == NULL) {
        printf("input.txt not found! Please enter expressions manually.\n");
        // If file not found, open temporary file for writing input
        fp1 = fopen("input_temp.txt", "w+");
        if (fp1 == NULL) {
            printf("Cannot create temporary input file. Exiting.\n");
            return 1;
        }
        printf("Enter expressions (operator arg1 arg2 result) one per line.\n");
        printf("Enter 'done' to finish input.\n");
        while (1) {
            char line[50];
            fgets(line, sizeof(line), stdin);
            if (strncmp(line, "done", 4) == 0) break;
            fputs(line, fp1);
        }
        rewind(fp1); // Reset file pointer to start
    }

    fp2 = fopen("output.txt", "w");
    if (fp2 == NULL) {
        printf("Cannot create output.txt. Exiting.\n");
        return 1;
    }

    while (fscanf(fp1, "%s", op) == 1) {
        fscanf(fp1, "%s %s %s", arg1, arg2, result);
        if (strcmp(op, "+") == 0) {
            fprintf(fp2, "MOV R0, %s\n", arg1);
            fprintf(fp2, "ADD R0, %s\n", arg2);
            fprintf(fp2, "MOV %s, R0\n", result);
        }
        else if (strcmp(op, "*") == 0) {
            fprintf(fp2, "MOV R0, %s\n", arg1);
            fprintf(fp2, "MUL R0, %s\n", arg2);
            fprintf(fp2, "MOV %s, R0\n", result);
        }
        else if (strcmp(op, "-") == 0) {
            fprintf(fp2, "MOV R0, %s\n", arg1);
            fprintf(fp2, "SUB R0, %s\n", arg2);
            fprintf(fp2, "MOV %s, R0\n", result);
        }
        else if (strcmp(op, "/") == 0) {
            fprintf(fp2, "MOV R0, %s\n", arg1);
            fprintf(fp2, "DIV R0, %s\n", arg2);
            fprintf(fp2, "MOV %s, R0\n", result);
        }
        else if (strcmp(op, "=") == 0) {
            fprintf(fp2, "MOV R0, %s\n", arg1);
            fprintf(fp2, "MOV %s, R0\n", result);
        }
    }

    fclose(fp1);
    fclose(fp2);

    printf("Code generation complete! Check output.txt for results.\n");
    return 0;
}

