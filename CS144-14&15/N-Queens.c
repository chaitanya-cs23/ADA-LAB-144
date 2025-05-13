#include<stdio.h>
#include<stdlib.h>

int x[20], count = 1;

void queens(int, int);
int place(int, int);

int main() {
    int n, k = 0;
    printf("\nEnter the number of queens to be placed: ");
    scanf("%d", &n);
    queens(k, n);
    return 0;
}

void queens(int k, int n) {
    int i, j;
    for (j = 0; j < n; j++) {
        if (place(k, j)) {
            x[k] = j;
            if (k == n - 1) {
                printf("\nSolution %d:\n", count);
                count++;
                for (i = 0; i < n; i++) {
                    printf("\n\tRow %d <---> Column %d", i + 1, x[i] + 1);
                }
                printf("\n\n");
            } else {
                queens(k + 1, n);
            }
        }
    }
}

int place(int k, int j) {
    int i;
    for (i = 0; i < k; i++) {
        if (x[i] == j || abs(x[i] - j) == abs(i - k)) {
            return 0;
        }
    }
    return 1;
}
