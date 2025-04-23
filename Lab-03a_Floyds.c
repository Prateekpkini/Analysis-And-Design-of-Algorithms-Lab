/* Design and implement C/C++ Program to solve All-Pairs Shortest Paths problem using Floyd's algorithm. */
#include <stdio.h>
#include <stdlib.h>

#define MAX 10
#define min(c, d) ((c < d) ? c : d)

int dist[MAX][MAX], n;

void floyd() {
    int i, j, k;

    // Record the lengths of the shortest path
    for (k = 1; k <= n; k++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void main() {
    int i, j;

    printf("Enter the number of vertices:\n");
    scanf("%d", &n);

    printf("Enter the distance matrix:\n");
    // Read distance matrix
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &dist[i][j]);

    floyd();

    printf("\nAll pairs shortest path matrix is:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d\t", dist[i][j]);
        printf("\n");
    }
}
