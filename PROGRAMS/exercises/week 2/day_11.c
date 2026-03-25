#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a ^ *b; // XOR (^), Different bits = 1, Same bits = 0
    *b = temp ^ *b;
    *a = temp ^ *b;

    /*Example, a = 5, b = 3
    
    temp = 101 XOR 011 = 110 

    b = 110 XOR 011 = 101 = 5
    a = 110 XOR 101 = 011 = 3
    */
}

void divmod(int a, int b, int *q, int *r) {
    // q = Quotient = division,  r = remainder
    if (b == 0) {
        printf("Denominator cannot be 0. Please retake your kindergarden classes.\n");
        *q = 0; *r = 0;
    } else {

    *q = a / b;
    *r = a % b;
    }
}

//DEBUG
void getVal(int *x) { 
    x = 42; // <- This is writing the memory address of x as 42. Its like changing the house address. To fix, add an asterisk in front of x.
    //Solution : *x = 42
}

int main() {
    int x =2; int y=3;
    swap(&x, &y);
    printf("x = %d, y = %d\n", x,y);
    int div; int remainder;
    divmod(10,3,&div,&remainder);
    printf("Quotient: %d, Remainder = %d\n",div,remainder);
    return 0;
}