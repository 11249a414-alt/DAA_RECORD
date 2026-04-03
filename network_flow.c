#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#define V 100  
int queue[V], front, rear;
bool bfs(int rGraph[V][V], int parent[], int s, int t, int n) {
    bool visited[V];
    memset(visited, 0, sizeof(visited));

    front = rear = 0;
    queue[rear++] = s;
    visited[s] = true;
    parent[s] = -1;

    while (front < rear) {
        int u = queue[front++];

        for (int v = 0; v < n; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}
int maxFlow(int graph[V][V], int s, int t, int n) {
    int u, v;
    int rGraph[V][V]; 
    for (u = 0; u < n; u++)
        for (v = 0; v < n; v++)
            rGraph[u][v] = graph[u][v];

    int parent[V];
    int max_flow = 0;
    while (bfs(rGraph, parent, s, t, n)) {
        int path_flow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            if (rGraph[u][v] < path_flow)
                path_flow = rGraph[u][v];
        }
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int n, s, t;
    int graph[V][V];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (capacity graph):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source and sink: ");
    scanf("%d %d", &s, &t);

    int result = maxFlow(graph, s, t, n);
    printf("Maximum Flow = %d\n", result);

    return 0;
}