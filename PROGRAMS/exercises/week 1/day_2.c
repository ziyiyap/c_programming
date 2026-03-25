#include <stdio.h>

int main() {
    double celcius = 32;
    //If we plainly did 9/5, we're doing integer division, which is basically flooring in python. So 9/5 -> 1, therefore we have to use decimal division.
    double fahrenheit = celcius * (double)9 /5 +32; //Here, we are converting 9 -> 9.0, then only apply the formula.
    printf("Celcius: %.2f\n",celcius);
    printf("Fahrenheit: %.2f\n",fahrenheit);
    char letter = 'A';
    int integer = 25;
    float pi = 3.14;
    double pi_d = 3.141592654;
    long long num = 9876543210;
    printf("%-12s %-12s %-12s", "Type","Value","Size (bytes)"); // - is left alignment, without it is right alignment.
    printf("\n--------------------------------------\n");
    printf("%-12s %-12c %-12d\n", "char", letter,(int)sizeof(letter));
    printf("%-12s %-12d %-12d\n", "int", integer,(int)sizeof(integer));
    printf("%-12s %-12.2f %-12d\n", "float", pi,(int)sizeof(pi));
    printf("%-12s %-12.9f %-12d\n", "double", pi_d,(int)sizeof(pi_d));
    printf("%-12s %-12lld %-12d\n", "long long", num,(int)sizeof(num));
    return 0;
}