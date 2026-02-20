#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAXV 100

int V;  // number of vertices

// BFS to find augmenting path
int bfs(int residual[MAXV][MAXV], int s, int t, int parent[]) {
    int visited[MAXV];
    memset(visited, 0, sizeof(visited));

    int queue[MAXV];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < V; v++) {
            if (!visited[v] && residual[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;

                if (v == t)
                    return 1; // path found
            }
        }
    }
    return 0; // no path found
}

// Edmonds-Karp algorithm
int maxFlow(int graph[MAXV][MAXV], int s, int t) {
    int u, v;
    int residual[MAXV][MAXV];
    int parent[MAXV];

    // Initialize residual graph
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
            residual[u][v] = graph[u][v];

    int max_flow = 0;

    // While there exists an augmenting path
    while (bfs(residual, s, t, parent)) {

        int path_flow = INT_MAX;

        // Find minimum residual capacity in path
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if (residual[u][v] < path_flow)
                path_flow = residual[u][v];
        }

        // Update residual capacities
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            residual[u][v] -= path_flow;
            residual[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int graph[MAXV][MAXV];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter capacity matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    int source, sink;
    printf("Enter source vertex: ");
    scanf("%d", &source);

    printf("Enter sink vertex: ");
    scanf("%d", &sink);

    int result = maxFlow(graph, source, sink);
    printf("Maximum Flow = %d\n", result);

    return 0;
}