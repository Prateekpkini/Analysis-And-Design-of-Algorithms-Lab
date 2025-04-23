/*Design and implement C/C++ Program to find Minimum Cost Spanning
Tree of a given connected undirected graph using Prim's algorithm.*/

#include <stdio.h>
#define INFI 99

int edges[10][3], n, wt[10][10];

void prims();

void main() {
    int i, j;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &wt[i][j]);
        }
    }

    prims();
}

void prims() {
    int u[10], lowcost[10], visited[10];
    int min, mincost = 0, i, j, v;

    visited[1] = 1; // mark the first node as visited

    // initialize lowcost and u arrays
    for (i = 2; i <= n; i++) {
        visited[i] = 0;
        u[i] = 1;
        lowcost[i] = wt[1][i];
    }

    for (i = 1; i <= n - 1; i++) {
        min = INFI;
        v = -1;

        // find the vertex with minimum cost
        for (j = 2; j <= n; j++) {
            if (!visited[j] && lowcost[j] < min) {
                min = lowcost[j];
                v = j;
            }
        }

        // save the edge
        edges[i][1] = u[v];
        edges[i][2] = v;
        mincost += lowcost[v];
        visited[v] = 1;
        lowcost[v] = INFI;

        // update lowcost[] for remaining vertices
        for (j = 2; j <= n; j++) {
            if (!visited[j] && wt[v][j] < lowcost[j]) {
                lowcost[j] = wt[v][j];
                u[j] = v;
            }
        }
    }

    printf("\n\nThe edges of this minimum cost spanning tree are:\n");
    for (i = 1; i <= n - 1; i++) {
        printf(" (%d, %d)\n", edges[i][1], edges[i][2]);
    }

    printf("\nMinimum cost Spanning Tree is: %d\n", mincost);
}
