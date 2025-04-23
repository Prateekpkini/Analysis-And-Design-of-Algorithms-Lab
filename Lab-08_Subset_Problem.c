/* Design and implement C/C++ Program to find a subset of a given set S =
{sl , s2,.....,sn} of n positive integers whose sum is equal to a given positive integer d.*/
#include<stdio.h>

int set[10], x[10], d, n;

void sumofsub(int s, int k) {
    int i;
    x[k] = 1;

    if (s + set[k] == d) {
        printf("{");
        for (i = 1; i <= n; i++) {
            if (x[i] == 1)
                printf("%d,", set[i]);
        }
        printf("\b}\n");
    }
    else {
        if (s + set[k] < d && k + 1 <= n) {
            sumofsub(s + set[k], k + 1);
            x[k + 1] = 0;
        }
        if (k + 1 <= n && s + set[k + 1] <= d) {
            x[k] = 0;
            sumofsub(s, k + 1);
            x[k + 1] = 0;
        }
    }
}

int main() {
    int sum = 0, i;

    printf("\nEnter set size of the set: ");
    scanf("%d", &n);

    printf("\nEnter set elements in increasing order\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &set[i]);

    printf("\nEnter maximum limit: ");
    scanf("%d", &d);

    printf("\nThe subsets with sum=%d are:\n", d);
    for (i = 1; i <= n; i++)
        sum = sum + set[i];

    if (sum < d || set[1] > d)
        printf("\nNo subset possible\n");
    else
        sumofsub(0, 1);

    return 0;
}
