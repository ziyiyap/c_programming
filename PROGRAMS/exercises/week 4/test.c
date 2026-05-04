#include <stdio.h>
#include <stdlib.h>

void fillPrintMatrix(int **matrix, int rows, int col) {
    if (rows == 0 || col == 0) {
        printf("Rows or columns can't equal 0\n");
    } else {
    *matrix = malloc(sizeof(int*) * rows); // allocate via address

    for (int i = 0; i < rows; i ++) {
        matrix[i] = malloc(sizeof(int) * col);
        for (int j = 0; j < col; j ++) {
            matrix[i][j] = (rows * i) + j;

            printf("%d ", matrix[i][j]);
        }
        free(matrix[i]);
        printf("\n");
    }
    free(matrix);



}
}

int main() {

    int **matrix;
    fillPrintMatrix(matrix, 4, 4);
    return 0;
}