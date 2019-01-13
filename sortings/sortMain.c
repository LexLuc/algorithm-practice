#include <stdbool.h>
#include <string.h>
#include "sortLab.h"

int main(int argc, char *argv[]) {
    // Arguments checking:
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <sorting types>\n\t%s --help for more help info.\n", argv[0], argv[0]);
        return -1;
    } else if (strcmp(argv[1], "--help") == 0) {
        // print out help message:
        printf("Available <sorting types> are: \n");
        printf("\t --bubble\n");
        printf("\t --quick\n");
        return 0;
    }

    int arrLen = 13;
    int arr[] = {3, 2, 4, 6, 3, 9, 6, 2, 7, 8, 1, 0, 5};
    
    if (strcmp(argv[1], "--bubble") == 0) {
        // bubble sort:
        printf("Bubble sort start!\n");
        displayArr(arr, arrLen);
        bubbleSort(arr, arrLen);
        displayArr(arr, arrLen);
        printf("Bubble sort finished!\n");

    } else if (strcmp(argv[1], "--quick") == 0) {
        // quick sort:
        printf("Quick sort start!\n");
        displayArr(arr, arrLen);
        quickSort(arr, arrLen);
        displayArr(arr, arrLen);
        printf("Quick sort finished!\n");

    } else if (strcmp(argv[1], "--merge") == 0) {
        // merge sort:
        printf("Merge sort start!\n");
        displayArr(arr, arrLen);
        mergeSort(arr, arrLen);
        displayArr(arr, arrLen);
        printf("Merge sort finished!\n");
    } else {
        // unkown sorting type:
        fprintf(stderr, "Unknow sorting type or unrecogized pattern \"%s\"!\n", argv[1]);
    }

    return 0;
}