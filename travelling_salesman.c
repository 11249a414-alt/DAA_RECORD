#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int graph[MAX][MAX];
int visited[MAX];
int minCost = INT_MAX;

void tsp(int city, int count, int cost) {
    if (count == n && graph[city][0]) {
        cost += graph[city][0];
        if (cost < minCost)
            minCost = cost;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[city][i]) {
            visited[i] = 1;
            tsp(i, count + 1, cost + graph[city][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    visited[0] = 1;  // Start from city 0
    tsp(0, 1, 0);

    printf("Minimum travelling cost: %d\n", minCost);
    return 0;
}
