#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr; // p points to arr[0] (precisely the address of the first element of the array)
    printf("%d\n", (void*)p); // 1000
    printf("%d\n", (void*)(p+1)); // 1004
    // Recall: size of int = 4 bytes
    p = p + 1; // Points to arr[1]
    printf("%d\n", *p); //20
    p++; // Points to arr[2]
    printf("%d\n", *p); //30

    // arr[i] == *(arr + i) == *(1 + arr) == i[arr]
    // Analogy: a + b = b + a OR ab = ba
    printf("%d %d %d %d", arr[1], *(arr + 1), *(1 + arr), 1[arr]);
    // 20 20 20 20
    return 0;
}