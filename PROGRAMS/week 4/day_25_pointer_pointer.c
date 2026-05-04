#include <stdio.h>

int main() {
    int x = 42;
    int *p = &x;
    int **q = &p;
    printf("%p\n", (void*)p);
    printf("%p\n", (void*)*q);
    printf("%p\n", (void*)&x);

    // In general, *q == p == &x.
    /*

    p points to x
    q points to p (not directly to x)

    Hence, 

    - p stores the address of x
    - q stores the address of p

    **q --> *p --> x
    */
    return 0;
}