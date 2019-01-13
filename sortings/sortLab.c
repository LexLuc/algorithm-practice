#include <stdbool.h>
#include "sortLab.h"

/**
 * ADT for statistics of sorting algorithms
 */

typedef struct _SortStatistics {
    int swapTimes;
    int comparisonTimes;
    int recursionTimes;
} SortStatistics;

SortStatistics *initStatistics() {
    SortStatistics *stat = malloc(sizeof(struct _SortStatistics));
    stat->comparisonTimes = 0;
    stat->recursionTimes = 0;
    stat->swapTimes = 0;

    return stat;
}

void showStatistics(SortStatistics *stat) {
    printf("***\t********************\t***\n");
    printf("***\tSwapping times:  %d\t***\n", stat->swapTimes);
    printf("***\tComparison times: %d\t***\n", stat->comparisonTimes);
    printf("***\tRecursion times: %d\t***\n", stat->recursionTimes);    
    printf("***\t********************\t***\n");
}


/**
 * Sorting Zoo below
 */

void bubbleSort(int arr[], int arrLen) {
    SortStatistics *stat = initStatistics();

    for (int i = 0; i < arrLen; i++) {
        bool isSwapped = false;

        for (int j = arrLen -1; j >= 0; j--) {
            if (arr[j-1] > arr[j]) {
                swap(&arr[j-1], &arr[j]);
                stat->swapTimes ++;
                isSwapped = true;
            }
            stat->comparisonTimes ++;
        }
        if (!isSwapped) // This condition will reduce the times of comparison
            break;
    }
    showStatistics(stat);
    free(stat);
}


void quickSortRec(int arr[], int low, int high, SortStatistics *stat) {
    if (low >= high)
        return;

    // partition:
    int pivot = arr[high];
    int i = low-1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(&arr[++i], &arr[j]);
            stat->swapTimes ++;
        }
        stat->comparisonTimes ++;
    }
    swap(&arr[++i], &arr[high]);

    // continue quicksort recursively:
    quickSortRec(arr, low, i-1, stat);
    quickSortRec(arr, i+1, high, stat);
    stat->recursionTimes ++;

}

void quickSort(int arr[], int arrLen) {
    SortStatistics *stat = initStatistics();

    quickSortRec(arr, 0, arrLen-1, stat);

    showStatistics(stat);
    free(stat);
}


/**
 * Help functions below
 */
void displayArr(int arr[], int arrLen) {
    for (int i = 0; i < arrLen; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
     *a = *b;
     *b = temp;
}
