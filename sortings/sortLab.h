#include <stdio.h>
#include <stdlib.h>

typedef struct _SortStatistics SortStatistics;

// Sort zoo:
void bubbleSort(int arr[], int arrLen);
void quickSort(int arr[], int arrLen);

// some help functions:
void displayArr(int arr[], int arrLen);
void swap(int *a, int *b);
