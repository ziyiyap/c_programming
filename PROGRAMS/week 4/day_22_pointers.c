#include <stdio.h>

int main() {
    int x = 42;
    int *p = &x; 
    void *s = &x; // pointer that holds the address of x, but does not care what data type stored

    printf("%d\n", *(int*)s); // convert the data type of the pointer s to (int), and dereference it.
    /*
    p = points to the ADDRESS of the variable assigned
    *p = value of the variable assigned

    if we modify *p, we also modify x

    Analogy:
    modification -> *p (agent) -> x
    */


    printf("%d\n", *p); // 42
    printf("%p\n", (void*)p); //prints the address of pointer p

    *p = 100; // modify x via pointer
    printf("%d\n", *p); // 100
    printf("%d\n", x); //100
    return 0;
}