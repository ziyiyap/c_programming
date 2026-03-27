#include <stdio.h>

void printMatrix(int matrix[][3], int rows) { // Passes &matrix[0][0], pointer to the first row which is an array of 3 integers (type: int[3])
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ",(*(matrix+i))[j]); // or, *(*(matrix+i) + j)
        }
        printf("\n");
    }

    /*
    Memory address terms:
    
    The 2D array decays to a pointer that points to the first row.
    
    1000 - 1     1020 - 6
    1004 - 2     1024 - 7
    1008 - 3     1028 - 8
    1012 - 4     1032 - 9
    1016 - 5

    Lets say we wanna find the value of matrix[2][1], convert into asterisk form

    *(*(matrix+2) + 1)
    
    We want the address of the row 2 (0+2 = 2) 

    Initial memory address (row 0) = 1000, since 1 row = 3 elements, we move 6 elements forward 

    *(1000 + 2( 4(bytes) * 3 elements)) = *(1024) <- THIS IS THE ADDRESS OF matrix[2][0]

    *(1024 + 1(4)) = *(1028) = 8

    ALTERNATIVELY,


    int *mat = &matrix[2][0]

    mat[1] = 8 // *(mat+1) = 8

    */
}

int main() {
    // 2D arrays, basically matrices
    int matrix[3][3] = { // [row][col], index starts at 0
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    // Accessing elements, say we wanna access row 0, col 1

    printf("%d\n",matrix[0][1]); // 2


    // Or we wanna loop print

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            printf("%d ",matrix[row][col]); // Loop through elements for each column for a specific row, then loop again for the next row.
        }
        printf("\n"); // So that it separates after the elements for each column finished looping for a specific row
    }
    printf("\n");
    /*
    Output:
    1 2 3 
    4 5 6 
    7 8 9 
    */

    /* Since 2D arrays are still arrays, when we pass it onto a function, it passes the memory address of the first row 
    which for the example, address of {1,2,3}. In C, we only need to pass in the num of columns, because it is a contiguous memory.
    
    Contiguous: the 3x3 matrix is converted into [1][2][3][4][5][6][7][8][9] in memory (row-major)
    */

    printMatrix(matrix,3);

    return 0;

}