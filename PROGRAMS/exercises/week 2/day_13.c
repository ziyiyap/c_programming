#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define DEBUG_PRINT(x) printf("%s = %d\n",#x, x) // # gets the name of the variable
//single line if condition:
// condition ? expression if true : expression if false

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MIN3(a,b,c) MIN(MIN(a,b),c)

/* Find the min between a,b, then find the min between the MIN(a,b) and c*/


void hypotenuse(double a, double b) {
    #ifdef DEBUG
        printf("[DEBUG] a = %f\n",a);
        printf("[DEBUG] b = %f\n",b);
        printf("[DEBUG] (%f)^2 + (%f)^2 = %f\n",a*a, b*b, a*a + b*b);
    #endif
    printf("Result: %.2f\n",sqrt(a*a + b*b));
}

int int_sum(int count, ...); //prototype


int main() {
    printf("%d\n",int_sum(3,10,20,30));

    int i = 2, j = 1;
    printf("%d\n",MAX(i++,j)); //best to not have i++, because when the if condition runs, it might return i++ again which is +2
    int myVar = 42;
    DEBUG_PRINT(myVar);

    hypotenuse(3,4);
    printf("%d\n",MIN3(4,2,3));
    return 0;
}

int int_sum(int count, ...) {
    va_list args;

    va_start(args,count); // sets arg0 = count, then starts at arg1

    int i,total =0;

    for (i=0; i < count; i++) {
        int num_iteration = va_arg(args,int);
        total += num_iteration;
    }
    va_end(args);
    return total;
}