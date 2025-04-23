/* Design and implement C/C++ Program to sort a given set of n integer elements using Quick Sort method and compute its time complexity. Run the program for varied values of n> 5000 and record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read from a
file or can be generated using the random number generator.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using low as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choosing the first element as the pivot
    int i = low + 1;
    int j = high;

    while (1) {
        while (i <= high && arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        } else {
            break;
        }
    }

    swap(&arr[low], &arr[j]);
    return j;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to generate a random array
void generateRandomArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Random number between 0 and 99
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int size;
    int arr[10000];

    printf("Enter the number of elements:\n");
    scanf("%d", &size);

    // Seed the random number generator
    srand(time(0));

    generateRandomArray(arr, size);

    printf("Original array:\n");
    printArray(arr, size);

    clock_t start = clock();
    quickSort(arr, 0, size - 1);
    clock_t end = clock();

    printf("Sorted array:\n");
    printArray(arr, size);

    double duration = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000000;
    printf("Time taken to sort %d elements: %.2f nanoseconds\n", size, duration);

    return 0;
}
