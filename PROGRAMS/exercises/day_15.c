#include <stdio.h>
#include <stdbool.h>
void BubbleSort(int *arr, int n, int *pass) {
    //swap pairs = n-1
    bool validity = false;
    while (validity != true) {
        validity = true;
        *pass = *pass + 1;
        for (int i = 0; i < n-1; i++) {
            //compare first element and second elements 
            int temp = arr[i];
            if (arr[i] > arr[i+1]) {
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                validity = false;
            
            }
        }
    } 
}

void SelectionSort(int *arr, int n, int *pass) {
    int min_index;
    for (int i = 0; i < n; i++) {
        min_index = i; //Set min to first index

        for (int j = i+1; j < n; j++) { // Start from second index

            if (arr[min_index] > arr[j]) {
                min_index = j;
            }

        }
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;

        *pass = *pass + 1;


    }
}

void reverseArray(int *arr, int n) {
    int left = 0; int right = n-1;

    while (left < right) {
        int temp = arr[left];

        arr[left] = arr[right];
        arr[right] = temp;

        left++; right--;

    }
}

void specificReverseArray(int *arr, int n, int k) {
    reverseArray(arr,k); reverseArray(arr+k,n-k); reverseArray(arr,n);
}

int linearSearch(int *arr, int n, int target);
int sort_binarySearch(int *arr, int n, int target);
int secondLargest(int *arr, int n);

int main() {
    int arr[] = {1,3,2,5,4};
    int arr_copy[] = {1,3,2,5,4};
    int size_array = sizeof(arr) /sizeof(arr[0]); //1 element = 4 bytes. total: 4 * (num of elements)
    int size_array_copy = sizeof(arr_copy) /sizeof(arr_copy[0]);
    int passes = 0;
    int passes_copy = 0;
    BubbleSort(arr,size_array, &passes);

    for (int i = 0; i < size_array; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nPass: %d\n",passes);

    SelectionSort(arr_copy,size_array_copy,&passes_copy);

    for (int i = 0; i < size_array_copy; i++) {
        printf("%d ", arr_copy[i]);
    }

    printf("\nPass: %d\n",passes_copy);

    int a[] = {2,3,4,5,6,7,8,9,10};
    int size_a = sizeof(a) / sizeof(a[0]);
    int target = 12;

    printf("%d\n",linearSearch(arr,size_array,target));
    printf("Found! %d\n",sort_binarySearch(a,size_a,target));

    reverseArray(arr,size_array);

    for (int i = 0; i < size_array; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int array_large[] = {3,1,5,2};
    int size_array_large = sizeof(array_large) / sizeof(array_large[0]);
    printf("%d\n",secondLargest(array_large, size_array_large));


    specificReverseArray(arr_copy,size_array_copy,2);

    for (int i = 0; i < size_array_copy; i++) {
        printf("%d ", arr_copy[i]);
    }
    return 0;
}

int linearSearch(int *arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {

            /*
            arr[i] is equal to *(arr + i).
            
            Recall: *arr = value at index 0
            
            In memory address terms:
            
            arr     -> 1000
            arr + 1 -> 1004
            arr + 2 -> 1008
            ...
            
            Since an integer value is 4 bytes, Ex. We wanna access value at index 2.
            
            Address: (arr + 2) = 1000 + 2(4) = 1008      Note: In C Integer bytes is set at 4, its different for other languages.
            
            Value = *(1008) = value
            
            Formula:
            
            *(arr + i) = value at (1000 + 4i)
            
            "international formula" : 
            
            *(arr + i) = value at (1000 + (integer byte size) * i )

            Extra: arr[i] == i[arr].

            *(arr + i) = *(i + arr)   using simple mathematics
            */
            return i;
        }
    }
    return -1;
}

int sort_binarySearch(int *arr, int n, int target) {
    int pass = 0; //ignorant variable
    BubbleSort(arr,n,&pass); //sorts the array first

    int low = 0; int high = n-1;

    while (low <= high) {
        int mid = (low+high)/2;
        if (target > arr[mid]) { 

            low = mid + 1;
        } else if (target < arr[mid]) {
            high = mid-1;
        } else {
            return mid;
        }
    }

    return -1;
}

int secondLargest(int *arr, int n) {
    int largest = *arr;
    int second_largest = *arr;

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) { //Checks if the current element is larger than the current largest
            second_largest = largest;   //Sets 'old' largest into second largest
            largest = arr[i]; //Sets current element into largest
        } else if (arr[i] > second_largest && arr[i] != largest) { // Checks if current element is larger than second largest and is not largest
            second_largest = arr[i];
        }
    }
    return second_largest;
}