#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 128

typedef struct Node {
    char sym;
    struct Node *left, *right;
    int pos;
    bool nullable;
    int firstpos[MAX], lastpos[MAX];
    int firstCount, lastCount;
} Node;

typedef struct { Node* data[MAX]; int top; } Stack;

void init(Stack* s){ s->top=-1; }
void push(Stack* s, Node* n){ s->data[++s->top]=n; }
Node* pop(Stack* s){ return s->data[s->top--]; }

int globalPos = 1;
int followpos[MAX][MAX] = {0};
int fCount[MAX] = {0};

bool isOperand(char c){ return isalnum(c); }

Node* createNode(char sym, Node* l, Node* r){
    Node* n = (Node*)malloc(sizeof(Node));
    n->sym = sym; n->left = l; n->right = r;
    n->nullable = false; n->firstCount = n->lastCount = 0; n->pos = -1;
    return n;
}

void addSet(int* set, int* count, int val){
    for(int i=0;i<*count;i++) if(set[i]==val) return;
    set[(*count)++] = val;
}

void unionSet(int* dst, int* dcount, int* src, int scount){
    for(int i=0;i<scount;i++) addSet(dst,dcount,src[i]);
}

Node* buildTree(char* postfix){
    Stack s; init(&s);
    for(int i=0; postfix[i]; i++){
        char c = postfix[i];
        if(isOperand(c)){
            Node* n = createNode(c,NULL,NULL);
            n->pos = globalPos++;
            n->firstpos[n->firstCount++] = n->pos;
            n->lastpos[n->lastCount++] = n->pos;
            push(&s,n);
        } else if(c=='*'){
            Node* a = pop(&s);
            Node* n = createNode(c,a,NULL);
            n->nullable = true;
            unionSet(n->firstpos,&n->firstCount,a->firstpos,a->firstCount);
            unionSet(n->lastpos,&n->lastCount,a->lastpos,a->lastCount);
            push(&s,n);
        } else if(c=='.'){
            Node* b = pop(&s); Node* a = pop(&s);
            Node* n = createNode(c,a,b);
            n->nullable = a->nullable && b->nullable;
            unionSet(n->firstpos,&n->firstCount,a->firstpos,a->firstCount);
            if(a->nullable) unionSet(n->firstpos,&n->firstCount,b->firstpos,b->firstCount);
            unionSet(n->lastpos,&n->lastCount,b->lastpos,b->lastCount);
            if(b->nullable) unionSet(n->lastpos,&n->lastCount,a->lastpos,a->lastCount);
            push(&s,n);
        } else if(c=='|'){
            Node* b = pop(&s); Node* a = pop(&s);
            Node* n = createNode(c,a,b);
            n->nullable = a->nullable || b->nullable;
            unionSet(n->firstpos,&n->firstCount,a->firstpos,a->firstCount);
            unionSet(n->firstpos,&n->firstCount,b->firstpos,b->firstCount);
            unionSet(n->lastpos,&n->lastCount,a->lastpos,a->lastCount);
            unionSet(n->lastpos,&n->lastCount,b->lastpos,b->lastCount);
            push(&s,n);
        }
    }
    return pop(&s);
}

void computeFollowpos(Node* n){
    if(!n) return;
    computeFollowpos(n->left);
    computeFollowpos(n->right);
    if(n->sym=='.'){
        for(int i=0;i<n->left->lastCount;i++){
            int p = n->left->lastpos[i];
            unionSet(followpos[p],&fCount[p],n->right->firstpos,n->right->firstCount);
        }
    } else if(n->sym=='*'){
        for(int i=0;i<n->lastCount;i++){
            int p = n->lastpos[i];
            unionSet(followpos[p],&fCount[p],n->firstpos,n->firstCount);
        }
    }
}

void printSet(int* set, int count){
    printf("{");
    for(int i=0;i<count;i++){ if(i>0) printf(","); printf("%d",set[i]); }
    printf("}\n");
}

void printNodeInfo(Node* n, int type){
    if(!n) return;
    printNodeInfo(n->left,type);
    printNodeInfo(n->right,type);
    if(type==1){ // firstpos
        printf("Node '%c' firstpos=",n->sym);
        printSet(n->firstpos,n->firstCount);
    } else if(type==2){ // lastpos
        printf("Node '%c' lastpos=",n->sym);
        printSet(n->lastpos,n->lastCount);
    } else if(type==3){ // followpos
        if(n->pos!=-1){
            printf("Node '%c' followpos=",n->sym);
            printSet(followpos[n->pos],fCount[n->pos]);
        }
    }
}

int main(){
    char postfix[100];

    printf("Enter postfix regex: ");
    scanf("%s",postfix);

    Node* root = buildTree(postfix);
    computeFollowpos(root);

    int choice;
    do{
        printf("\nMenu:\n1. Firstpos\n2. Lastpos\n3. Followpos\n4. Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printNodeInfo(root,1); break;
            case 2: printNodeInfo(root,2); break;
            case 3: printNodeInfo(root,3); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    }while(choice!=4);

    return 0;
}

