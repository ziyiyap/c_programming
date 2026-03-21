#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

void read_character(char ch) {
    printf("%c\n%c\n",toupper(ch),tolower(ch));

    if (isalpha(ch)) {
        printf("letter\n");
    } else if (isdigit(ch)) {
        printf("digit\n");
    } else if (isspace(ch)) {
        printf("blank space\n");
    } else {
        printf("Special character");
    }
}

double hypotenuse(double a, double b);



int main() {
    char character;
    printf("Enter a single character: ");
    scanf("%c",&character);
    read_character(character);

    double a; double b;
    printf("Enter values of a and b: <a> <b>\n");
    scanf("%lf %lf",&a,&b);
    printf("c = %.3f\n",hypotenuse(a,b));

    double num;
    printf("Enter a positive real number: ");
    scanf("%lf",&num);

    if (num <= 0) {
        printf("Logarithms cannot have negative or zero numbers.");
    } else {
    printf("log2(%.3f) = %.3f\n",num,log2(num));
    }

    double n;
    printf("Enter a real number: ");
    scanf("%lf",&n);
    printf("Ceil : %f, Floor : %f",ceil(n),floor(n));
    return 0;
}

double hypotenuse(double a, double b) {
    if (a < 0 || b < 0) {
        printf("a or b must be positive real numbers.\n");
        return -1;
    } 
    return sqrt(a*a + b*b);
}