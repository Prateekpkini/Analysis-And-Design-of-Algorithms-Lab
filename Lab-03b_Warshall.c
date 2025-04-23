/* Design and implement C/C++ Program to find the transitive closure using Warshal's algorithm */
#include <stdio.h>

#define MAX 10

int D[MAX][MAX], n;

void warshall() {
    int i, j, k;
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                D[i][j] = D[i][j] || (D[i][k] && D[k][j]);
}

void main() {
    int i, j;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &D[i][j]);

    warshall();

    printf("Transitive closure of digraph is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d\t", D[i][j]);
        printf("\n");
    }
}
