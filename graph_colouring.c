#include <stdio.h>
#define MAX 20

int graph[MAX][MAX];
int color[MAX];
int V, m;
int isSafe(int v, int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}
int graphColoring(int v) {
    if (v == V)
        return 1; 

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c)) {
            color[v] = c;

            if (graphColoring(v + 1))
                return 1;

            color[v] = 0; 
        }
    }
    return 0;
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoring(0)) {
        printf("Solution Exists:\n");
        for (int i = 0; i < V; i++)
            printf("Vertex %d -> Color %d\n", i, color[i]);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}