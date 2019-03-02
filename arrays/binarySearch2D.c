#include <stdio.h>
#include <time.h>
#include "dynamic2DArray.h"

void echoInput(int **mat, int rows, int columns, int target);
int binarySearch2D_divide_and_conquer(int **mat, int top, int left, int bottom, int right, int target);
int binarySearch2D_optimal(int **mat, int rows, int columns, int target);

int main(int argc, char *argv[]) {
    
    // parse data from stdin:
    int m, n;
    scanf("%d %d", &m, &n);
    getchar();
    
    int **mat = create2DArray(m, n);
    for (int i = 0; i < m; i++) {
        int j = 0;
        do {
            int num = 0;
            int ch = getchar();
            while (ch >= '0' && ch <= '9') {
                num = (ch - '0') + num * 10;
                ch = getchar();
            }
            mat[i][j++] = num;
            
        } while (j < n);
    }
    int target;
    scanf("%d", &target);
    //echoInput(mat, m, n, target);
    
    // get answer by different solutions:
    printf("Is %d in matrix?\n", target);
    int result; 
    clock_t start;
    
    // linear solution:
    start = clock();
    result = binarySearch2D_optimal(mat, m, n, target);
    printf("\nResult from linear solution %s\n", result ? "true" : "false");
    printf("CPU time consumed: %lf\n", (double)(clock()-start) / CLOCKS_PER_SEC);
    
    // divide-and-conquer solution:
    start = clock();
    result = binarySearch2D_divide_and_conquer(mat, 0, 0, m-1, n-1, target);
    printf("\nResult from divide and conquer solution %s\n", result ? "true" : "false");
    printf("CPU time consumed: %lf\n", (double)(clock()-start) / CLOCKS_PER_SEC);

    drop2DArray(mat, m);

    return 0;
}

void echoInput(int **mat, int rows, int columns, int target) {
    printf("%d × %d matrix:\n", rows, columns);
    display2DArray(mat, rows, columns);
    printf("target: %d\n", target);
}

int binarySearch2D_optimal(int **mat, int rows, int columns, int target) {
    int i = 0;
    int j = columns - 1;
    while (i < rows && j >= 0) {
        if (target == mat[i][j]) 
            return 1;
        if (target < mat[i][j]) 
            j--;
        else 
            i++;
    }
    return 0;
}

int binarySearch2D_divide_and_conquer(int **mat, int top, int left, int bottom, int right, int target) {
    if (top > bottom || left > right)
        return 0;

    int i = (top + bottom) / 2;
    int j = (left + right) / 2;
    if (target < mat[i][j]) 
        return binarySearch2D_divide_and_conquer(mat, top, left, bottom, j-1, target) 
            || binarySearch2D_divide_and_conquer(mat, top, j, i-1, right, target);
    if (target > mat[i][j]) 
        return binarySearch2D_divide_and_conquer(mat, top, j+1, bottom, right, target)
            || binarySearch2D_divide_and_conquer(mat, i+1, left, bottom, j, target);
    else
        return 1;
}