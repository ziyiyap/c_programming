#include <stdio.h>
#include <stdlib.h>


//Prototypes
int isPrime(int integer);
int GCD(int a, int b);
double power(double base, int exp);

//BIT INSPECTOR
void printBinary(long long n) {

    for (int i = 31; i>=0; i--) {
        int check = (n >> i) & 1;

        if ((i+1) % 8 == 0 && i != 31) {
            printf(" ");
        }
        printf("%d",check);
    }
    printf("\n");
}

void tryDouble(int x) {
    x = x * 2;
}

int main() {
    int i;
    printf("Enter an integer: ");
    scanf("%d",&i);

    if (isPrime(i) == 0) {
        printf("%d is a prime number.\n",i);
    } else {
        printf("%d is NOT a prime number.\n",i);
    }
    int a; int b;
    printf("Enter <a> <b>\n");
    scanf("%d %d", &a,&b);

    printf("%d\n",GCD(a,b));

    double base; int exp;
    printf("Enter <base> <exp>\n");
    scanf("%lf %d", &base, &exp);

    printf("%.6f\n",power(base,exp));

    long long integer;
    printf("Enter an integer: ");
    scanf("%d", &integer);

    printBinary(integer);

    int x;
    printf("Enter an integer: ");
    scanf("%d", &x);   
    printf("Before: %d\n",x);
    tryDouble(x);
    printf("After: %d\n",x); //PRINTS 6
    return 0;
    
}

//PRIME CHECKER
int isPrime(int integer) {
    if (integer != 1 && integer >0) {
        for (int checker = integer-1; checker >=2; checker--) {
            if (integer % checker == 0) {
                return 1;
            }
        }
        return 0;
        } else {
            return 1;
        }
}

int GCD(int a, int b) {
    int temp;
    while (b !=0) {
        temp = b; 
        b = a % b;
        a = temp; 
    }
/*
First loop:

Ex (12,8)
temp = 8
 b = 12 % 8 = 4
a = 8

Second loop:

temp = 4
b = 8 % 4 = 0
a = 4

*/
    return a;
}

double power(double base, int exp) {
    double result = 1;
    int exp_checker = abs(exp);
    if (exp_checker != 0) {
    do {
        result = result * base;
        exp_checker --;
    } while (exp_checker!=0);

    if (exp <0) {
        result = 1/result;
    }


    } else return 1;
    return result;
}