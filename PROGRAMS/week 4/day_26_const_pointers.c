#include <stdio.h>

int main() {

    // const: a way to permanently fix the address OR the value of the pointer, depending on how you put it.
    // const int * = constant pointer - NO changing address
    // int * const = constant value = NO changing value


    // Pointer to const value
    int a = 10; int b = 30; int c = 90;

    const int *p = &a; // You may think of it like 'constant value of the pointer'.
    // *p will cause error -- compiler error, but we can modify the value of the variable THROUGH the variable, not the pointer.
    printf("%d\n", *p); // 10

    // However, we can redefine the pointer to another variable.

    p = &b;

    printf("%d\n", *p); // 30

    // const Pointer to Value
    // This is the 'reverse' of pointer to const. The const here permanently fixes the address assigned to the pointer, hence you cant redefine the pointer to another var.

    int * const q = &b; // You may think of it like 'constant pointer'.
    // q = &var  will cause error -- compiler error, however we can redefine a value to the value of the 'constant pointer'.

    *q = 40;

    printf("%d\n", *q); //40

    // const pointer to const value
    // For this you cant modify anything it all. The whole thing is permanent: the pointer, and the value.

    const int * const r = &a;

    // Either *p = val OR p = &var will raise compiler error.

    printf("%d\n", *r); // 10

    // Plain pointer (NO const)
    // Your usual pointer. You can modify the address AND value.

    int *s = &a; 

    s = &c;

    *s = 100;

    printf("%d\n", *s); // 100
    

    return 0;
}