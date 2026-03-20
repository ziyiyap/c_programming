#include <stdio.h>

void addAndSub(int a, int b, int *sum, int *diff) { //int *sum = &s. sum stores the memory address of s. (same goes to int *diff)
    // The * here, 'inverses' the memory address of sum into its original value, and a+b is stored into (s), and a-b is stored into (d).

    *sum = a+b; // Go to the memory address stored in sum (&s), and stores a+b

    /*
    sum = &s, sum holds the address of s
    *sum = a+b, go to the address stored in sum and writes a+b
    s contains a+b
    */


    *diff = a-b; // Go to the memory address stored in diff (&d), and stores a+b
}

int main() {
    int x = 10;
    int *p = &x; // This means, 'p' is a variable of type "pointer to an integer."

    // The asterisk of a variable means 'dereferencing'. Dereferencing a pointer (p) is accessing/modifying the actual value stored at the memory address that the pointer (p) is holding.
    // The 'and' sign, & when placed on a variable means 'referencing'. Referencing a pointer means 'take the memory address of that variable'.

    /*
    ptr itself stores the address of x, so
    
    ptr = &x. (referencing, or 'Take the address of a variable')
    
    So if we print ptr using %p, we will get the actual address of x (&x). 
    
    To get the actual value stored on x, we simply just add a dereferencing sign (*). 
    
    So, *ptr = x.
    
    Think of it as 'inversing' the address into its original value. (f^-1 [f(x)] = x analogy)
    
    To print the original value of x through the dereferenced pointer,

    printf("%d",*ptr).

    Think of *ptr as an agent of x. 
    
    X -> *ptr (without *, it stores the memory address) -> OUTPUT

    */

    printf("%p\n",p);// This is the memory address of x stored in the pointer (p)
    //To get the actual value of x,
    printf("%d\n",*p);
    //OR,
    printf("%d\n",*(&x));
    int s; int d; //Right now, sum and diff variables have garbage values.

    addAndSub(3,5,&s,&d);
    printf("Sum: %d, Difference: %d",s,d);
    return 0;
}