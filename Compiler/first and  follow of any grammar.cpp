//first and follow pose

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_NONTERM 26
#define MAX_RULES 128
#define MAX_LEN 128

typedef struct {
    int rule_count;
    char productions[MAX_RULES][MAX_LEN];
} NonTerminal;

NonTerminal grammar[MAX_NONTERM];
int nt_exists[MAX_NONTERM];
char nt_sequence[MAX_NONTERM];
int seq_count = 0;
int FIRST[MAX_NONTERM][128];
int FOLLOW[MAX_NONTERM][128];

int has_epsilon(int set[]) {
    return set['e'] != 0;
}

int add_symbol_to_set(int set[], int symbol) {
    if(!set[symbol]) {
        set[symbol] = 1;
        return 1;
    }
    return 0;
}

int merge_sets_excluding(int dest[], int src[], int exclude) {
    int changed = 0;
    for(int i = 0; i < 128; i++) {
        if(i == exclude) continue;
        if(src[i] && !dest[i]) {
            dest[i] = 1;
            changed = 1;
        }
    }
    return changed;
}

void remove_whitespace(char *s) {
    int w = 0;
    for(int r = 0; s[r]; r++) {
        if(s[r] != ' ' && s[r] != '\t' && s[r] != '\r') {
            s[w++] = s[r];
        }
    }
    s[w] = '\0';
}

void parse_production(const char *line) {
    char buffer[MAX_LEN];
    strncpy(buffer, line, MAX_LEN - 1);
    buffer[MAX_LEN - 1] = '\0';
    buffer[strcspn(buffer, "\n")] = '\0';
    remove_whitespace(buffer);
    if(buffer[0] == '\0') return;

    char head = buffer[0];
    if(!isupper((unsigned char)head)) return;
    int idx = head - 'A';

    if(!nt_exists[idx]) {
        nt_exists[idx] = 1;
        nt_sequence[seq_count++] = head;
    }

    const char *rhs_start = strstr(buffer, "->");
    if(!rhs_start) return;
    rhs_start += 2;

    char temp[MAX_LEN]; int t = 0;
    for(int i = 0;; i++) {
        char ch = rhs_start[i];
        if(ch == '|' || ch == '\0') {
            temp[t] = '\0';
            if(t > 0) {
                strncpy(grammar[idx].productions[grammar[idx].rule_count], temp, MAX_LEN - 1);
                grammar[idx].productions[grammar[idx].rule_count][MAX_LEN - 1] = '\0';
                grammar[idx].rule_count++;
            }
            t = 0;
            if(ch == '\0') break;
        } else if(t < MAX_LEN - 1) {
            temp[t++] = ch;
        }
    }
}

void first_of_string(const char *str, int out_set[], int *has_e) {
    for(int i = 0; i < 128; i++) out_set[i] = 0;
    int nullable = 1;

    if(str[0] == '\0') {
        *has_e = 1;
        return;
    }

    for(int i = 0; str[i]; i++) {
        char X = str[i];
        if(X == 'e') continue;
        if(isupper((unsigned char)X)) {
            int idx = X - 'A';
            merge_sets_excluding(out_set, FIRST[idx], 'e');
            if(!FIRST[idx]['e']) {
                nullable = 0;
                break;
            }
        } else {
            add_symbol_to_set(out_set, (unsigned char)X);
            nullable = 0;
            break;
        }
    }
    *has_e = nullable;
}

void compute_FIRST() {
    int changed = 1;
    while(changed) {
        changed = 0;
        for(int i = 0; i < seq_count; i++) {
            int A = nt_sequence[i] - 'A';
            for(int r = 0; r < grammar[A].rule_count; r++) {
                const char *prod = grammar[A].productions[r];
                if(strcmp(prod, "e") == 0) {
                    if(add_symbol_to_set(FIRST[A], 'e')) changed = 1;
                    continue;
                }
                int temp[128], has_e;
                first_of_string(prod, temp, &has_e);
                if(merge_sets_excluding(FIRST[A], temp, -1)) changed = 1;
                if(has_e && add_symbol_to_set(FIRST[A], 'e')) changed = 1;
            }
        }
    }
}

void compute_FOLLOW() {
    if(seq_count > 0) FOLLOW[nt_sequence[0] - 'A']['$'] = 1;

    int changed = 1;
    while(changed) {
        changed = 0;
        for(int i = 0; i < seq_count; i++) {
            int A = nt_sequence[i] - 'A';
            for(int r = 0; r < grammar[A].rule_count; r++) {
                const char *prod = grammar[A].productions[r];
                int len = strlen(prod);
                for(int j = 0; j < len; j++) {
                    char B = prod[j];
                    if(isupper((unsigned char)B)) {
                        int idxB = B - 'A';
                        char beta[MAX_LEN]; int b = 0;
                        for(int k = j + 1; k < len && b < MAX_LEN - 1; k++) beta[b++] = prod[k];
                        beta[b] = '\0';

                        int temp[128], has_e;
                        first_of_string(beta, temp, &has_e);
                        if(merge_sets_excluding(FOLLOW[idxB], temp, 'e')) changed = 1;
                        if(has_e || beta[0] == '\0') {
                            if(merge_sets_excluding(FOLLOW[idxB], FOLLOW[A], -1)) changed = 1;
                        }
                    }
                }
            }
        }
    }
}

void print_set(const char *label, char nt, int set[]) {
    printf("%s(%c) = { ", label, nt);
    int first = 1;
    for(int i = 0; i < 128; i++) {
        if(set[i]) {
            if(!first) printf(", ");
            printf("%c", i);
            first = 0;
        }
    }
    printf(" }\n");
}

int main() {
    int n;
    char line[MAX_LEN];

    memset(grammar, 0, sizeof(grammar));
    memset(nt_exists, 0, sizeof(nt_exists));
    memset(nt_sequence, 0, sizeof(nt_sequence));
    seq_count = 0;
    memset(FIRST, 0, sizeof(FIRST));
    memset(FOLLOW, 0, sizeof(FOLLOW));

    printf("Enter the number of productions: ");
    if(scanf("%d", &n) != 1) return 0;
    getchar();

    printf("Enter the productions:\n");
    for(int i = 0; i < n; i++) {
        if(!fgets(line, sizeof(line), stdin)) break;
        if(line[0] == '\n' || line[0] == '\0') { i--; continue; }
        parse_production(line);
    }

    compute_FIRST();
    compute_FOLLOW();

    printf("\nThe firstpos and followpos of the production are:\n");
    for(int i = 0; i < seq_count; i++) {
        char nt = nt_sequence[i];
        print_set("FIRST", nt, FIRST[nt - 'A']);
        print_set("FOLLOW", nt, FOLLOW[nt - 'A']);
    }
    return 0;
}
