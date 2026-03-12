#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
    char srcLabel, destLabel;
};

// Compare function for qsort
int compare(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i];
}

void unionSets(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);

    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int getIndex(char label) {
    return label - 'a';
}

int main() {
    int V = 7; // Number of vertices a-g
    int E = 12; // Number of edges (including eb)

    struct Edge edges[] = {
        {'a','b',5}, {'a','c',3}, {'e','f',3}, {'b','c',4},
        {'f','g',4}, {'c','d',5}, {'e','g',5}, {'b','d',6},
        {'d','e',6}, {'d','f',6}, {'c','f',6}, {'e','b',2} // NEW EDGE
    };

    printf("Original Graph (edges with weights):\n");
    for (int i = 0; i < E; i++) {
        printf("%c-%c = %d\n", edges[i].src, edges[i].dest, edges[i].weight);
    }

    qsort(edges, E, sizeof(edges[0]), compare);

    int parent[MAX];
    int rank[MAX];

    for (int v = 0; v < V; ++v) {
        parent[v] = v;
        rank[v] = 0;
    }

    struct Edge result[MAX];
    int e = 0;
    int i = 0;
    int totalWeight = 0;

    printf("\nStep-by-step process:\n");

    while (e < V - 1 && i < E) {
        struct Edge next_edge = edges[i++];
        int x = find(parent, getIndex(next_edge.src));
        int y = find(parent, getIndex(next_edge.dest));

        if (x != y) {
            result[e++] = next_edge;
            totalWeight += next_edge.weight;
            unionSets(parent, rank, x, y);
            printf("Accepted: %c-%c = %d\n", next_edge.src, next_edge.dest, next_edge.weight);
        } else {
            printf("Rejected (cycle): %c-%c = %d\n", next_edge.src, next_edge.dest, next_edge.weight);
        }
    }

    printf("\nMinimum Spanning Tree (MST):\n");
    for (i = 0; i < e; ++i)
        printf("%c-%c = %d\n", result[i].src, result[i].dest, result[i].weight);
    printf("Total Weight of MST = %d\n", totalWeight);

    return 0;
}

