#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void doublePointer(int **q) { // Ex1
    *q = malloc(sizeof(int)); // NULL -> stores address of 4 heap bytes
    **q = 42; // write 42 into the value of the address
}

void printArrayString(char *words[], int n) { //Ex2
    char **ptr = words; // &words[0]
    for (int i = 0; i < n; i ++) {
        printf("%s\n", *(ptr + i));
    }
}

void merge(char **strs, int left, int mid, int right, char *temp[]) {
    int i = left; int j = mid + 1; int k = 0;
    while (i <= mid && j <= right) {
        if (strcmp(strs[i], strs[j]) > 0) { //
            temp[k]= strs[j];
            k ++; j ++;

        } else {
            temp[k]= strs[i];
            k ++; i ++;
        }
    }

    while (i <= mid) {
        temp[k]= strs[i];
        k ++; i ++;
    }
    while (j <= right) {
        temp[k]= strs[j];
        k ++; j ++;
    }

    for (int w = 0; w <= (right - left); w ++) {
        strs[left + w]= temp[w];
    }
}

void mergeSort(char **strs, int left, int right, char *temp[]) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(strs, left, mid, temp);
        mergeSort(strs, mid+1, right, temp);

        merge(strs, left, mid, right, temp);
    }
}

void sortStrings(char **strs, int n) { // Ex 3
    // n = number of elements. len()

    // strcmp("a", "b") - > -1
    // strcmp("b", "a") -> 1
    // Recall: strcmp checks the first different letter only.

    int left = 0; int right = n - 1;
    char **temp = malloc(sizeof(char *) * n);

    mergeSort(strs, left, right, temp);
    free(temp);
}

void fillPrintMatrix(int **matrix, int rows, int col) { // Ex 4
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
        printf("\n");
    }

    for (int i = 0; i < rows; i ++) {
        free(matrix[i]);
    }
    free(*matrix);
}
}

void replacePointer(int **p, int *b) { // Ex 5

    *p = b;
}

int main() {

    int *p = NULL; // p = NULL, *p will cause undefined behavior.
    int **q = &p;

    doublePointer(q);

    printf("%d\n", *p);
    char *words[] = {"hello", "world", "c"};
    int n = sizeof(words) / sizeof(words[0]);
    printArrayString(words, n); 
    free(p);

    char *fruits[] = {"apple", "banana", "orange", "mango", "strawberry", "pineapple", "kiwi", "grape"};
    n = sizeof(fruits) / sizeof(fruits[0]);
    sortStrings(fruits, n);

    for (int i = 0; i < n; i ++) {
        printf("%s\n", fruits[i]);
    }
    int *mat = NULL;
    int **matrix = &mat;
    fillPrintMatrix(matrix, 4, 4);

    int a = 1; int b = 4;
    int *ptr = &a; int **pp = &ptr;
    int *bptr = &b;
    printf("pointer a: %d, pointer b: %d\n", **pp, *bptr);
    replacePointer(pp, bptr);

    printf("pointer a: %d, pointer b: %d\n", **pp, *bptr);
    return 0;
}