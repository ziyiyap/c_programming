#include <stdio.h>
#include <stdbool.h>
#define row_A 3 
#define col_A 3
#define row_B 3
#define col_B 3
#define define_row 3
#define define_col 2

void matmul(int rowA, int colA , int rowB, int colB, int matA[][colA], int matB[][colB], int result[][colB]) {
    // Matrix multiplication -> row * col

    if (colA != rowB) {
        printf("Dimension Error: %d x %d", colA, rowB);
    } else {

    /*
    [[1,2], * [[5,6],
     [3,4]]    [7,8]] 
     
     = [[1(5) + 2(7), 1(6) + 2(8)],
        [3(5) + 4(7), 3(6) + 4(8)]]*/

    for (int i = 0; i < rowA; i++) { //ROW A
        
        for (int j = 0; j < colB; j++) { // COL B

            for (int k = 0; k < colA; k++) { // Loop through col for MATRIX A, Loop through row for MATRIX B
                result[i][j] += matA[i][k] * matB[k][j];

                
                /* 
                1st i loop:
                    1st j loop:
                        i = 0
                        j = 0
                        First k Loop:
                        
                        result[0][0] += 1 * 5
                        
                        Second k loop:
                        
                        result[0][0] += 2 * 7
                    2nd j loop:
                        i = 0
                        j = 1

                        First k loop:

                        result[0][1] += 1 * 6

                        Second k loop:
                        
                        result[0][1] += 2 * 8
                        
                2nd i loop:

                    1st j loop:
                        i = 1
                        j = 0
                        First k Loop:
                        
                        result[1][0] += 3 * 5
                        
                        Second k loop:
                        
                        result[1][0] += 4 * 7

                    2nd j loop:
                        i = 1
                        j = 1

                        First k loop:

                        result[1][1] += 3 * 6

                        Second k loop:
                        
                        result[1][1] += 4 * 8
                */
            }
        }
    }
    }



}

void transpose(int row, int col, int matrix[][col], int result[][row]) {
    /*
    [[1,2],   [[1,3,5],
     [3,4], =   [2,4,6]]
     [5,6]]  
     */
    // Basically, row become columns and columns become rows
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[j][i] = matrix[i][j];
        }
    }

}

void printBoard(char board[][3]) {
    for (int row = 0; row < 3; row ++) {
        for (int col = 0; col < 3; col ++) {
            printf("%c ", board[row][col]);
        } printf("\n");
    }
}

void ttt(char board[][3]) {
    bool stalemate = true;

    printBoard(board);
    printf("\n");

    for (int row = 0; row < 3; row ++) { 
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2] && board[row][0] != ' ') {
            printf("%c is the winner\n",board[row][0]);
            stalemate = false;
        }
    }
    for (int col = 0; col < 3; col ++) { 
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col] && board[0][col] != ' ') {
            printf("%c is the winner\n",board[0][col]);
            stalemate = false;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        printf("%c is the winner\n",board[0][0]);
        stalemate = false;
    }

    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        printf("%c is the winner\n",board[0][2]);
        stalemate = false;
    }


    if (stalemate == true) {
        printf("Stalemate"); 
    } 
}

void spiral_traversal(int row, int col, int matrix[][col],int order[]) {
    int top = 0; int bottom = row-1; int left = 0; int right = col-1; int index = 0;

    while (top <= bottom && left <= right ) { 
        // 3x3 example
        for (int k = left; k <= right; k++) { // left = 0 
            order[index] = matrix[top][k]; // left = 1, left = 2
            index++;
        }
        top ++; // top = 1, so we dont overlap the top-right number
        
        for (int k = top; k <= bottom; k++) { // start at index 1
            order[index] = matrix[k][right]; // row 1, col 2 (last column) -> row 2, col 2
            index++;
        }
        right--; // right = 1
        for (int k = right; k >= left; k--) { // right = 1 so we dont overlap with bottom-right number
            order[index] = matrix[bottom][k]; // (2,1) -> (2,0)
            index++;
        }
        bottom--; // bottom = 1

        for (int k = bottom; k >= top; k --) { // bottom = 1 so we dont overlap with bottom-left number (2,0)
            order[index] = matrix[k][left]; // (1,0)
            index++;
        }
        left++;

}
}

int check_magic_square(int n, int matrix[][n]);

int main() {

    int matrixA[row_A][col_A] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int matrixB[row_B][col_B] = {
        {9,8,7},
        {6,5,4},
        {3,2,1}
    };

    int result[row_A][col_B] = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    matmul(row_A,col_A,row_B,col_B,matrixA,matrixB,result);
    printf("\n");
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < col_B; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    int matrix[define_row][define_col] = {
        {1,2},
        {3,4},
        {5,6}
    };

    int tranpose_matrix[define_col][define_row] = {
        {0,0,0},
        {0,0,0}
    };

    transpose(define_row,define_col,matrix,tranpose_matrix);
    printf("\n");
    for (int i = 0; i < define_col; i++) {
        for (int j = 0; j < define_row; j++) {
            printf("%d ", tranpose_matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    int magic_square[3][3] = {
        {4,9,2},
        {3,5,7},
        {8,1,6}
    };
    printf("%d",check_magic_square(3,magic_square));
    printf("\n");

    char tictactoe[3][3] = {
        {' ','X','X'},
        {' ','O',' '},
        {'X','O','X'}
    };

    ttt(tictactoe);

    int spiral[4][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };

    int spiral_order[4*4];

    spiral_traversal(4,4,spiral,spiral_order);
    printf("\n");
    for (int i = 0; i < 4*4; i ++) {
        printf("%d ", spiral_order[i]);
    }
    return 0;
}

int check_magic_square(int n, int matrix[][n]) {
    int sum = (n * (n * n + 1)) / 2;
    int check_sum = 0;

    for (int row = 0; row < n; row++) {
        for (int i = 0; i < n; i++) {
            check_sum += matrix[row][i];
        }

        if (check_sum != sum) {
            return 0;
        }

        check_sum = 0;
    }

    for (int col = 0; col < n; col++) {
        for (int j = 0; j < n; j++) {
            check_sum += matrix[j][col];
        }

        if (check_sum != sum) {
            return 0;
        }

        check_sum = 0;
    }

    // Top left  to bottom right diagonal

    for (int k = 0; k < n; k++) {
        check_sum += matrix[k][k];
    }

    if (check_sum != sum) {
        return 0;
    }

    check_sum = 0;


    // Top right to bottom left diagonal
    for (int l = 0; l < n; l++) {
        check_sum += matrix[l][n-1-l];
    }

    if (check_sum != sum) {
        return 0;
    }

    check_sum = 0;

    

    return 1;
    }