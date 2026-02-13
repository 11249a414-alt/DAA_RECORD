#include <stdio.h>
#include <limits.h>

#define MAX 10

int main() {
    int n, graph[MAX][MAX];
    int visited[MAX] = {0};
    int edges = 0, minCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    visited[0] = 1;  // Start from vertex 0

    printf("Edges in MST:\n");

    while (edges < n - 1) {
        int min = INT_MAX, x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, graph[x][y]);

        minCost += graph[x][y];
        visited[y] = 1;
        edges++;
    }

    printf("Total Minimum Cost = %d\n", minCost);

    return 0;
}
