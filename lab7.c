//Esrat Jahan, 03-08-24, lab 7 assignment, cop3502 sec 0005, lab sec 0038

#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j]]++;
                swaps[arr[j+1]]++;
            }
        }
    }
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_idx, temp;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
        swaps[arr[min_idx]]++;
        swaps[arr[i]]++;
    }
}

void printSwapCounts(int arr[], int n, int swaps[]) {
    printf("array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", arr[i], swaps[arr[i]]);
    }
    printf("total # of swaps: %d\n\n", swaps[arr[n-1]]);
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swaps1[98] = {0};
    int swaps2[98] = {0};

    bubbleSort(array1, n1, swaps1);
    bubbleSort(array2, n2, swaps2);

    printf("array 1 bubble sort:\n");
    printSwapCounts(array1, n1, swaps1);

    printf("array 2 bubble sort:\n");
    printSwapCounts(array2, n2, swaps2);

    selectionSort(array1, n1, swaps1);
    selectionSort(array2, n2, swaps2);

    printf("array 1 selection sort:\n");
    printSwapCounts(array1, n1, swaps1);

    printf("array 2 selection sort:\n");
    printSwapCounts(array2, n2, swaps2);

    return 0;
}
