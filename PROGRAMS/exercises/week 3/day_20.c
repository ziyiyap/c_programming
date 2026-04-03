#include <stdio.h>
#include <stdbool.h>

void InsertionSort(int n, int *arr) {
    for (int i = 1; i <= n-1; i ++) {
        int key = arr[i];

        int j = i-1;
        for (j; j >=0 && arr[j] > key; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }

    /* 
    First iteration:
    
    key = arr[1] = 4, j = 0
    
    j >= 0 and 5 > 4 ? True,
    
    arr[1] = 5

    j = -1, Loop: false
    
    arr[-1+1] = 4*/
}

void merge(int *arr, int left, int mid, int right, int *temp) {
    int i = left; int j = mid + 1; int k = 0; 
    // i - LEFT ARRAY, start at index left
    // j - RIGHT ARRAY, start at index mid + 1
    // k - TEMP ARRAY, start at index 0 
    // Total elements from LEFT to RIGHT: (right - left)

    while (i <= mid && j <= right) {
        if (arr[j] > arr[i]) {
            temp[k] = arr[i];
            i++; k++;
        } else {
            temp[k] = arr[j];
            j++; k++;
        }
    }

    while (i <= mid) {
        temp[k] = arr[i];
        i++; k++;
    }

    while (j <= right) {
        temp[k] = arr[j];
        j++; k++;
    }

    for (int w = 0; w <= (right-left); w ++) {
        arr[left+w] = temp[w];
    }
}

void MergeSort(int *arr, int left, int right, int *temp) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid,temp);
        MergeSort(arr,mid+1,right,temp);

        merge(arr, left, mid, right, temp);
    }
}

void binarySearch(int *arr, int low, int high, int target) {
    if (low > high) {
        printf("Not found");
        return;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        printf("Found %d",target);
    } else if (target > arr[mid]) {
        binarySearch(arr, mid+1, high,target);
    } else if (target < arr[mid]) {
        binarySearch(arr, low,mid-1,target);
    } 
}

void countSort(int *arr, int *count) {
    
}

int partition(int left, int right,int *arr);
int quickselect(int k, int left, int right, int *arr);

int main() {
    int arr[5] = {5,4,3,2,1}; 

    int size_arr = sizeof(arr) / sizeof(arr[0]);

    InsertionSort(size_arr,arr);

    for (int i = 0; i < size_arr; i ++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int mergearr[5] = {5,2,1,3,6};

    int size_merge = sizeof(mergearr) / sizeof(mergearr[0]);

    int temp_arr[size_merge];
    MergeSort(mergearr, 0, size_merge-1, temp_arr);

    for (int i = 0; i < size_merge; i ++) {
        printf("%d ", mergearr[i]);
    }
    printf("\n");

    binarySearch(mergearr, 0, size_merge-1,6);

    int arrr[5] = {4,2,5,1,3};
    int sizearr = sizeof(arr) / sizeof(arr[0]);
    printf("\n");
    printf("%d\n",quickselect(0, 0, size_arr - 1, arrr));

    int count[256] = {0};
    int count_arr[5] = {3,1,2,1,3};


    return 0;
}

int partition(int left, int right,int *arr) {
    int i = left-1; int j = left;
    // pivot = right-1


    for (j; j <= right-1; j++) {
        if (arr[j] <= arr[right]) {
            
            int temp = arr[j];
            arr[j] = arr[i+1];
            arr[i+1] = temp;
            i++; 
        }
    }

    int temp = arr[right];
    arr[right] = arr[i+1];
    arr[i+1] = temp;

    /*For first smallest:
    
    First recursion
    left = 0, right = 5
    
    i = -1, j = 0 
    First iteration: i = -1, j = 0
        4 > 3, skip
    Second iteration: i = -1, j = 1
        2 < 3, swap 2 and 4 (index 0)
        result = {2,4,5,1,3} i = 0
    Third iteration: i = 0, j = 2
        5 > 3, skip
    Last iteration: i = 0, j = 3
        1 < 3, swap 1 and 4 (index 1)
        result = {2,1,5,4,3} i = 1

    Swap pivot and 5 (index 2)

    result = {2,1,3,4,5}


    */

    return i+1; // 2 (pivot's index)

    /*
    
    Second recursion
    left = 0, right = 1
    i = -1, j = 0
    
    Array = {2,1,3,4,5}, pivot = 1
    First iteration: i = -1, j = 0
        2 > 1, skip

    Swap pivot and i+1 (index 0)
    result = {1,2,3,4,5}
     
    return -1+1 = 0 (index 0)*/


}

int quickselect(int k, int left, int right, int *arr) {
    if (left == right) {
        return arr[left];
    }
    int p = partition(left,right,arr); // First: 2, Second = 0

    if (p == k) { // First: 2 != 0 Second: 0 = 0 
        return arr[p]; // return arr[0] = 1
    } else if (p > k) { // First: True
        return quickselect(k, left, p-1, arr);
    } else if (p < k) {
        return quickselect(k,p+1,right,arr);
    }
}