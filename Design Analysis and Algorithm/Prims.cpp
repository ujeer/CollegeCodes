#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int graph[V][V], char labels[]) {
    int totalWeight = 0;
    printf("\nEdges in MST:\n");
    for (int i = 1; i < V; i++) {
        printf("%c - %c = %d\n", labels[parent[i]], labels[i], graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Total Weight of MST = %d\n", totalWeight);
}

void printGraph(int graph[V][V], char labels[]) {
    printf("\nGraph Representation (Adjacency Matrix):\n    ");
    for (int i = 0; i < V; i++)
        printf("%c  ", labels[i]);
    printf("\n");

    for (int i = 0; i < V; i++) {
        printf("%c |", labels[i]);
        for (int j = 0; j < V; j++) {
            if (graph[i][j] != 0)
                printf("%2d ", graph[i][j]);
            else
                printf(" . ");
        }
        printf("\n");
    }
}

void primMST(int graph[V][V], char labels[]) {
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    printf("\nStep-by-step process:\n");

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        printf("\nSelected Vertex: %c\n", labels[u]);

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v]) {
                if (graph[u][v] < key[v]) {
                    printf(" ? Accepting edge %c-%c (%d)\n", labels[u], labels[v], graph[u][v]);
                    parent[v] = u;
                    key[v] = graph[u][v];
                } else {
                    printf(" ? Rejecting edge %c-%c (%d), better edge exists\n", labels[u], labels[v], graph[u][v]);
                }
            }
        }
    }

    printMST(parent, graph, labels);
}

int main() {
    char labels[] = {'a', 'b', 'c', 'd', 'e'};

    int graph[V][V] = {
        // a  b  c  d  e
        { 0, 5,15,20, 0}, // a
        { 5, 0,25, 0, 0}, // b
        {15,25, 0,30,37}, // c
        {20, 0,30, 0,35}, // d
        { 0, 0,37,35, 0}  // e
    };

    printGraph(graph, labels);
    primMST(graph, labels);

    return 0;
}

