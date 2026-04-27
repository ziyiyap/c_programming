#include <stdio.h>

void increment(int *p) {
    (*p) ++;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int DoesNotModify(int var);

int main() {
    // Ex 1
    int x = 23; double y = 32.0; char z[] = "I major in Electrical and Electronics Engineering.";
    int *p = &x; double *q = &y; char *r = z; // for strings, we dont need to use the &. Internally, it does char *r = &z[0]

    // Print value
    printf("%d %.2f %s\n", *p, *q, r); //we dont need to *r because %s already dereference the pointer for us

    /*
    %s = char *  
    
    when we pass z, it already decays to &z[0]
    
    hence, %s, z -> char * &z[0] */

    // Print pointer address
    printf("%p %p %p\n",(void*)p, (void*)q, (void*)r); // address of the variable pointed
    printf("%p %p %p\n",(void*)&p, (void*)&q, (void*)&r); // address of pointer
     // Ex 2
    increment(p);
    // Ex 3
    int x2 = 32; int *s = &x2;
    swap(p, s);
    printf("%d, %d\n", *p, *s);

    // Ex 4 : Demonstration

    int var = 50;
    printf("%d\n", DoesNotModify(var));
    printf("%d\n", var);

    /* It does not modify the variable 'var' even if we passed it onto the function. Its because the parameter received is localised 
    and the output is stored in the function, not the variable.
    
    However, we can modify the original variable just by redefining it, ex.
    
    var = DoesNotModify(var)
    */

    // Ex 5: Debug

    /*
    int *p; *p = 5; 
    
    Pointer is uninitialised; will cause undefined behavior.
    
    Solution: 
    
    Define another variable, Ex. 
    
    int var = 10;
    
    Assign address to pointer;
    
    int *p = &var; 
    
    *p = 5
    
    OUTPUT: var = 5*/
    return 0;
}

int DoesNotModify(int var) {
    var *= 2;
    return var;
}