#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int **create2DArray(int rows, int columns) {
    int **mat = malloc(sizeof(int *) * rows);
    assert(mat != NULL);

    for (int i = 0; i < rows; i++) {
        mat[i] = malloc(sizeof(int) * columns);
        assert(mat[i]!= NULL);
    }
    return mat;
}

void display2DArray(int **mat, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) 
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void drop2DArray(int **mat, int rows) {
    for (int i = 0; i < rows; i++) 
        free(mat[i]);
    free(mat);
}
