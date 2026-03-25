#include <stdio.h>

//An array is a block of memory that stores data of the same type.
// {} <- a block of memory
// 1, 2, 3, 4, 5 (in the block) <-data stored into the block of memory

//When an array is modified no matter where it is (a function, or anywhere), the whole array modifies accordingly.

// *arr is the same as arr[]. (When its passed as a function parameter)

void double_arr(int *arr, int n) { // arr[50], arr[], arr[100] is the same as *arr. Its because the compiler doesnt enforce the size of array.

    //When passing arrays, what actually is passed is the address of the first element of the array. = &arr[0]

    // *arr = first element of the array
    // arr = pointer to the first element of the array

    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * 2;
    }

    for (int i = 0; i <n; i++) {
        printf("%d\n",arr[i]); //2,4,6,8,10
    }
    printf("\n");
}

void arr_(int arr[5]) {
    printf("%d\n",*arr); // <- Since &arr[0] is passed, *(&arr[0]) = arr[0]
    //So to access the next elements of the array,
    // *(&arr[0+1])
    
    printf("%d\n",*(&arr[0+2])); //Third element of the array = 6 (modified)

    //Alternatively, *(arr+2) does the same trick too.
    printf("%d\n",*(arr+2)); //6
}

int main() {

    int arr[5] = {1,2,3,4,5}; //Declare an array

    printf("%d\n",arr[0]); //Accessing the first index of the array = 1
    //Basically almost the same thing with python

    for (int i = 0; i < 5; i++) {
        printf("%d\n",arr[i]); //Loop through an array
    }
    printf("\n");
    double_arr(arr,5);
    printf("\n");
    arr_(arr);
    return 0;
}