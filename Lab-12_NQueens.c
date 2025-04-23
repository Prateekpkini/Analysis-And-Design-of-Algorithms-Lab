// Design and implement C/C++ Program for N Queen's problem using Backtracking.
#include<stdio.h>
#include<stdlib.h>

int col[30], count = 0;

int place(int r) {
    int i;
    for (i = 1; i < r; i++) {
        if ((col[i] == col[r]) || (abs(i - r) == abs(col[i] - col[r])))
            return 0;
    }
    return 1;
}

void Nqueen(int n) {
    int r = 1, i, j;
    col[r] = 0;

    while (r != 0) {
        col[r] = col[r] + 1;
        while ((col[r] <= n) && !place(r))
            col[r] = col[r] + 1;

        if (col[r] <= n) {
            if (r == n) {
                count++;
                printf("\nSolution # %d\n", count);
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n; j++) {
                        if (j == col[i])
                            printf("Q ");
                        else
                            printf("* ");
                    }
                    printf("\n\n");
                }
            }
            else {
                r++;
                col[r] = 0;
            }
        }
        else {
            r--;
        }
    }
}

int main() {
    int n;
    printf("\nEnter the number of queens: ");
    scanf("%d", &n);
    Nqueen(n);
    printf("\nTotal no.of solutions are %d\n", count);
    return 0;
}
