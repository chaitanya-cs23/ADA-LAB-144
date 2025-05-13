#include <stdio.h>
#include <limits.h>

#define N 3

int cost[N][N];
int minCost = INT_MAX;
int bestAssignment[N];

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calculateCost(int perm[]) {
    int total = 0;
    for (int i = 0; i < N; i++) {
        total += cost[i][perm[i]];
    }

    if (total < minCost) {
        minCost = total;
        for (int i = 0; i < N; i++) {
            bestAssignment[i] = perm[i];
        }
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
    printf("Enter cost of 3x3 matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    int tasks[N] = {0, 1, 2};
    permute(tasks, 0, N - 1);

    for (int i = 0; i < N; i++) {
        printf("%d assigned to job %d with cost %d\n", i, bestAssignment[i] + 1, cost[i][bestAssignment[i]]);
    }

    printf("Total cost: %d\n", minCost);

    return 0;
}
