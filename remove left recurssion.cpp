#include <stdio.h>
#include <string.h>

#define MAX 10
#define SIZE 50

int main() {
    char nonTerminal; // The grammar's non-terminal (A, B, etc.)
    int n;            // Number of productions
    char prod[MAX][SIZE];   // Original productions
    char alpha[MAX][SIZE];  // Left-recursive parts
    char beta[MAX][SIZE];   // Non-left-recursive parts
    int alphaCount = 0, betaCount = 0;

    // Input the non-terminal
    printf("Enter the non-terminal: ");
    scanf(" %c", &nonTerminal);

    // Input the number of productions
    printf("Enter the number of productions for %c: ", nonTerminal);
    scanf("%d", &n);

    // Input all productions
    printf("Enter the right-hand side of each production:\n");
    for(int i = 0; i < n; i++){
        scanf("%s", prod[i]);
    }

    // Separate left-recursive and non-left-recursive productions
    for(int i = 0; i < n; i++){
        if(prod[i][0] == nonTerminal){   // Left recursion detected
            strcpy(alpha[alphaCount++], prod[i] + 1); // Remove the first character (A)
        } else {
            strcpy(beta[betaCount++], prod[i]);      // Non-left-recursive
        }
    }

    // If no left recursion, inform user
    if(alphaCount == 0){
        printf("No left recursion detected for %c.\n", nonTerminal);
        return 0;
    }

    // Print the new grammar after removing left recursion
    printf("\nGrammar after removing left recursion:\n");

    // New production for original non-terminal: A -> ßA'
    printf("%c -> ", nonTerminal);
    for(int i = 0; i < betaCount; i++){
        printf("%s%c'", beta[i], nonTerminal);
        if(i != betaCount - 1) printf(" | ");
    }
    printf("\n");

    // New production for the helper non-terminal: A' -> aA' | e
    printf("%c' -> ", nonTerminal);
    for(int i = 0; i < alphaCount; i++){
        printf("%s%c'", alpha[i], nonTerminal);
        if(i != alphaCount - 1) printf(" | ");
    }
    printf(" | e\n");

    return 0;
}

