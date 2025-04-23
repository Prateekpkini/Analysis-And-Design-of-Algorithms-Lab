/*Design and implement C/C++ Program to sort a given set of n integer elements using Selection Sort method and compute its time complexity. Run the program for varied values of n> 5000 and record the time taken to
sort. Plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator. */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int n;
int *array;

void input() {
    printf("Enter the total numbers: ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 1000; // Generates random numbers 0-999
    }

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void selectionSort() {
    for (int step = 0; step < n - 1; step++) {
        int min_idx = step;
        for (int i = step + 1; i < n; i++) {
            if (array[i] < array[min_idx]) {
                min_idx = i;
            }
        }
        int temp = array[step];
        array[step] = array[min_idx];
        array[min_idx] = temp;
    }
}

int main() {
    input();

    clock_t start = clock();
    selectionSort();
    clock_t end = clock();

    double duration = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000000;

    printf("\nTime for sorting is %.2f nanoseconds\n", duration);

    printf("Sorted Array in Ascending Order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
