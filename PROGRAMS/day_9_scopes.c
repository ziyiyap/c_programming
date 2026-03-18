#include <stdio.h>

/*
There are 3 types of variables.
- LOCAL
- GLOBAL
- STATIC LOCAL
*/

//LOCAL
void local() {
    int x = 5; // <- called inside a function, always sets to the same value every function call
}

//GLOBAL

int y = 5; // <- called outside a function, accessible to all functions.

void global() {
    printf("%d",y); 
}

//STATIC LOCAL

void static_local() {
    static int count = 0; // <- initialised only ONCE.
    count++;
    printf("Count: %d\n",count);
    /*
    Example, 
    1st call -> Count: 1
    2nd call -> Count: 2
    3rd call -> Count: 3
    ...
    */
}