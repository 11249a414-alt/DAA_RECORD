#include <stdio.h>
#include <limits.h>
struct Edge {
    int src, dest, weight;
};
struct Graph {
    int V, E;
    struct Edge edges[100];
};
void printArr(int dist[], int V) {
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
void BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int weight = graph->edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int j = 0; j < E; j++) {
        int u = graph->edges[j].src;
        int v = graph->edges[j].dest;
        int weight = graph->edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    printArr(dist, V);
}
int main() {
    struct Graph graph;
    graph.V = 5; 
    graph.E = 8;
    graph.edges[0] = (struct Edge){0, 1, -1};
    graph.edges[1] = (struct Edge){0, 2, 4};
    graph.edges[2] = (struct Edge){1, 2, 3};
    graph.edges[3] = (struct Edge){1, 3, 2};
    graph.edges[4] = (struct Edge){1, 4, 2};
    graph.edges[5] = (struct Edge){3, 2, 5};
    graph.edges[6] = (struct Edge){3, 1, 1};
    graph.edges[7] = (struct Edge){4, 3, -3};

    BellmanFord(&graph, 0);

    return 0;
}