#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int u, v, weight;
} Edge;

typedef struct {
    Edge edges[MAX];
    int edgeCount;
} Graph;

int parent[MAX];

// Function to find the root of a set
int find(int i) {
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}

// Function to perform union of two sets
void unionSets(int x, int y) {
    parent[x] = y;
}

// Comparison function for qsort
int compareEdges(const void *a, const void *b) {
    Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return edgeA->weight - edgeB->weight;
}

// Function to implement Kruskal's algorithm
void kruskal(Graph *graph) {
    qsort(graph->edges, graph->edgeCount, sizeof(Edge), compareEdges);

    for (int i = 0; i < MAX; i++)
        parent[i] = -1;

    printf("Edges in the Minimum Spanning Tree:\n");
    int mstWeight = 0;

    for (int i = 0; i < graph->edgeCount; i++) {
        int uRoot = find(graph->edges[i].u);
        int vRoot = find(graph->edges[i].v);

        if (uRoot != vRoot) {
            unionSets(uRoot, vRoot);
            printf("%d -- %d == %d\n", graph->edges[i].u, graph->edges[i].v, graph->edges[i].weight);
            mstWeight += graph->edges[i].weight;
        }
    }

    printf("Total weight of MST: %d\n", mstWeight);
}

int main() {
    Graph graph;
    graph.edgeCount = 0;

    // Example: adding edges (u, v, weight)
    graph.edges[graph.edgeCount++] = (Edge){0, 1, 10};
    graph.edges[graph.edgeCount++] = (Edge){0, 2, 6};
    graph.edges[graph.edgeCount++] = (Edge){0, 3, 5};
    graph.edges[graph.edgeCount++] = (Edge){1, 3, 15};
    graph.edges[graph.edgeCount++] = (Edge){2, 3, 4};

    graph.edgeCount = 5; // Update the count of edges

    kruskal(&graph);

    return 0;
}
