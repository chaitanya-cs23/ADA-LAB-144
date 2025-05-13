#include <stdio.h>
#include <limits.h>

#define MAX 10

int graph[MAX][MAX], path[MAX], bestPath[MAX], n;
int minCost = INT_MAX;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void calculateCost(int perm[]) {
    int cost = 0;
    for (int i = 0; i < n - 1; i++)
        cost += graph[perm[i]][perm[i + 1]];
    cost += graph[perm[n - 1]][perm[0]];

    if (cost < minCost) {
        minCost = cost;
        for (int i = 0; i < n; i++)
            bestPath[i] = perm[i];
    }
}

void permute(int perm[], int l, int r) {
    if (l == r) {
        calculateCost(perm);
        return;
    }
    for (int i = l; i <= r; i++) {
        swap(&perm[l], &perm[i]);
        permute(perm, l + 1, r);
        swap(&perm[l], &perm[i]);
    }
}

int main() {
    printf("Enter order of graph: ");
    scanf("%d", &n);
    printf("Enter graph:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        path[i] = i;

    permute(path + 1, 1, n - 1);

    printf("Minimum cost of TSP: %d\n", minCost);
    printf("Path: ");
    for (int i = 0; i < n; i++)
        printf("%d -> ", bestPath[i]);
    printf("%d\n", bestPath[0]);

    return 0;
}
