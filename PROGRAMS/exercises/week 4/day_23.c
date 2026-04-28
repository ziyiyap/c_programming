#include <stdio.h>

void printArray(int *p, int n) {
    for (int i = 0; i < n; i ++) {
        printf("%d\n", *(i + p));
    }
}

void printFromMid(int *mid, int steps_back, int steps_forward) {

    //Backward

    for (int i = steps_back; i > 0; i --) {
        printf("%d ", *(mid - i));
    }
    // Print Mid

    printf("%d ", *mid);

    //Print Forward

    for (int j = 1; j <= steps_forward; j ++) {
        printf("%d ", *(mid + j));
    }
    printf("\n");
}

int* findMax(int *arr, int n);

int main() {
    // Ex1
    int arr[5] = {5, 30, 15, 20, 25};
    int *p = arr;

    for (int i = 0; i < 5; i ++) {
        printf("%d\n", *(p + i));
    }
    printf("\n");
    // Ex2
    printArray(p, 5);
    printf("\n");
    // Ex3 

    printf("%d\n", *(findMax(arr, 5)));

    // Ex 4
    for (int i = 0; i < 5; i ++) {
        printf("%d %d %d %d\n", arr[i], *(arr + i), *(i + arr), i[arr]);
    } // Explanation in PROGRAMS -> week 4 
    printf("\n");
    // Ex 5

    int arr_[5] = {10,20,30,40,50}; int *q = arr_ + 5/2;
    int arrtest[10] = {10,20,30,40,50,60,70,80, 90, 100}; int *r = arrtest + 10/2;
    int n = sizeof(arr_) / sizeof(arr_[0]);
    printFromMid(q, 2, 2); 
    printFromMid(r, 5, 4);
    return 0;
}

int* findMax(int *arr, int n) {
    int *max = &arr[0];

    for (int i = 0; i < n; i ++) {
        if (i[arr] > *max) {
            max = &i[arr];
        }
    }
    return max;
}