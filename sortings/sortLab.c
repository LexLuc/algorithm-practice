#include <stdbool.h>
#include "sortLab.h"

/**
 * ADT for statistics of sorting algorithms
 */
typedef struct _SortStatistics {
    int swapTimes;
    int comparisonTimes;
    int recursionTimes;
    int recursionDepth;
} SortStatistics;

SortStatistics *initStatistics() {
    SortStatistics *stat = malloc(sizeof(struct _SortStatistics));
    stat->comparisonTimes = 0;
    stat->recursionTimes = 0;
    stat->recursionDepth = 0;
    stat->swapTimes = 0;

    return stat;
}

void showStatistics(SortStatistics *stat) {
    printf("***\t********************\t***\n");
    printf("***\tSwapping times:  %d\t***\n", stat->swapTimes);
    printf("***\tComparison times: %d\t***\n", stat->comparisonTimes);
    printf("***\tRecursion times: %d\t***\n", stat->recursionTimes);    
    printf("***\tRecursion depth: %d\t***\n", stat->recursionDepth);    
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


void quickSortRec(int arr[], int low, int high, SortStatistics *stat, int recDepth) {
    if (low >= high) {
        stat->recursionDepth = recDepth;
        return;
    }
        
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
    quickSortRec(arr, low, i-1, stat, recDepth+1);
    quickSortRec(arr, i+1, high, stat, recDepth+1);
    stat->recursionTimes ++;
}

void quickSort(int arr[], int arrLen) {
    SortStatistics *stat = initStatistics();

    quickSortRec(arr, 0, arrLen-1, stat, 0);

    showStatistics(stat);
    free(stat);
}

void merge(int arr[], int low, int mid, int high, SortStatistics *stat) {
    int mergedSubArrLen = high - low + 1;
    int *mergedSubArr = malloc(sizeof(int) * mergedSubArrLen);

    for (int i = low, j = mid + 1, k = 0; k < mergedSubArrLen; k++) {
        if (i > mid) {
            mergedSubArr[k] = arr[j++];
        } else if (j > high) {
            mergedSubArr[k] = arr[i++];
        } else if (arr[i] < arr[j]) {
            mergedSubArr[k] = arr[i++];
        } else {
            mergedSubArr[k] = arr[j++];
        }
        stat->comparisonTimes ++;
    }

    for (int i = low, k = 0; k < mergedSubArrLen; k++, i++) {
        arr[i] = mergedSubArr[k];
    }
    free(mergedSubArr);
}

void mergeSortRec(int arr[], int low, int high, SortStatistics *stat, int recDepth) {
    if (low >= high) {
        stat->recursionDepth = recDepth;
        return;
    }

    int mid = (low + high) /2;
    mergeSortRec(arr, low, mid, stat, recDepth+1);
    mergeSortRec(arr, mid+1, high, stat, recDepth+1);
    merge(arr, low, mid, high, stat);

    stat->recursionTimes ++;
}

void mergeSort(int arr[], int arrLen) {
    SortStatistics *stat = initStatistics();

    mergeSortRec(arr, 0, arrLen-1, stat, 0);

    showStatistics(stat);
    free(stat);
}


/**
 * Help functions below
 */
void displayArr(int arr[], int arrLen) {
    printf("[");
    for (int i = 0; i < arrLen-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[arrLen-1]);
}

void swap(int *a, int *b) {
    int temp = *a;
     *a = *b;
     *b = temp;
}
