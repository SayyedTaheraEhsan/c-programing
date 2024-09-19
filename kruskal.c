#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 9999

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAX];
int parent[MAX];
int numEdges = 0, numVertices;

// Function to compare edges for qsort
int compare(const void *a, const void *b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Find function for Union-Find
int find(int i) {
    while (parent[i] != -1) {
        i = parent[i];
    }
    return i;
}

// Union function for Union-Find
void unionSets(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    if (rootU != rootV) {
        parent[rootU] = rootV;
    }
}

// Function to implement Kruskal's Algorithm
void kruskal() {
    qsort(edges, numEdges, sizeof(edges[0]), compare);
    for (int i = 0; i < numVertices; i++) {
        parent[i] = -1;
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            unionSets(u, v);
            printf("%d -- %d == %d\n", u, v, edges[i].weight);
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal();

    return 0;
}
