#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


int isPrime(int n);
int gcd(int a,int b);
int lcm(int a, int b);
int fibonacci(int n);
int factorial(int n);
double power(double base, int exp);
int isPalindrome(int n);

//
int main() {
    int num = 1;

    if (isPrime(num) == 1) {
        printf("%d is a prime number\n",num);
    } else printf("%d is NOT a prime number\n",num);

    printf("GCD: %d\n",gcd(5,10));
    printf("LCM: %d\n",lcm(12,18));
    int term = 7;
    printf("%dth term of Fibonacci: %d\n",term,fibonacci(term));

    int f = 6;
    printf("%d! = %d\n",f,factorial(f));

    double base = 0.5;
    printf("%f\n",power(base,2));

    int palindrome = 1221;

    if (isPalindrome(palindrome) == 1) {
        printf("%d is a palindrome number",palindrome);
    } else printf("%d is NOT a palindrome number",palindrome);

    return 0;
}

int isPrime(int n) {
    if (n == 1 || n == 0) {
        return 0;
    }
    for (int i = n-1; i >= 2; i--) {
        if ( n % i == 0) {
            return 0;
        }
    }

    return 1;
}

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;

        b = a % b;

        a = temp;
    }

    return a;
}

int lcm(int a, int b) {
    return abs(a*b)/gcd(a,b);
}

int fibonacci(int n) {
    if (n == 0 || n == 1) return n; else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int factorial(int n) {
    int result = n;

    for (int i = n-1; i >=1; i--) {
        result = result * i;
    }

    return result;
}

double power(double base, int exp) {
    double result = 1;
    int exp_checker = abs(exp);
    if (exp_checker != 0) {
    do {
        result = result * base;
        exp_checker -- ;
    } while (exp_checker != 0);

    if (exp < 0 ) {
        result = 1/result;
    }


    return result;
    } else return 1;


}

int isPalindrome(int n) {
    int n_copy = n;
    int palindrome = 0;
    while (n_copy != 0) {
        palindrome = palindrome * 10 + (n_copy % 10);
        n_copy /= 10;
    }

    if (n == palindrome) {return 1;} else return 0;
}