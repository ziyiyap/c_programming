#include <stdio.h>

int main() {
    //E1
    int integer_division = 7 /2 ;
    // Same concept as flooring, 7/2 mathematically is 3.5, remove the decimal = 3
    printf("%d\n", integer_division);

    int remainder = 7 % 2 ;
    // Remainder = 1
    printf("%d\n", remainder);

    float decimal_division = 7.0 / 2;
    //3.5
    printf("%f\n", decimal_division);

    double double_division = (double)7 / 2;
    // Same thing, 3.5 
    printf("%f\n", double_division);

    //PRECISION TEST

    float float_test = 7.0 / 3;
    double double_test = (double)7/3;

    // Float will be less precise compared to the double.
    printf("Float: %.10f\nDouble: %.10f\n", float_test,double_test);
    //Float: 2.3333332539 <- less precise
    //Double: 2.3333333333 <- more precise

    //E2
    long long digit;
    printf("Enter digit: ");
    scanf("%lld", &digit);
    int odd_or_even = digit & 1;
    printf("%d\n", odd_or_even);
    //IF 1, ODD 
    //IF 0, EVEN

    //E3
    int a; int b;
    printf("Enter digits: <a> <b>\n");
    scanf("%d %d", &a, &b);
    //Say a = 5, b = 3
    printf("Before: a = %d, b = %d\n", a, b);

    //CREATE an (a) variable, (process variable)
    a = a ^ b;
    // 5 XOR 3 = 101 XOR 011 = 110 = 6
    b = a ^ b; //We can redeclare a variable without using the data type.
    // 6 XOR 3 = 110 XOR 011 = 101 = 5
    a = a ^ b;
    // 5 XOR 6 = 101 XOR 110 = 011 = 3

    printf("Final result: a = %d, b = %d\n", a, b);
    //PROVE:
    // a = a ^ b
    // b = a ^ b
    /*
    Substitute a into b:
    b = (a^b)^b
    We can move the b into a
    b = (b^b) ^ a
    b = 0 ^ a 
    b = a
    
    Same thing with a,
    
    a = a ^ (a^b)
    We can move a into b,
    a = b ^ (a^a)
    a = b ^ 0
    a = b
    */

    //E4
    int n; int k;
    printf("Enter k, n value for k(2^n): ");
    scanf("%d %d", &k, &n);
    int value = k << n; 
    printf("%d(2^%d) = %d\n", k,n,value);
    return 0;
}