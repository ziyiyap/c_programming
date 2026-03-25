#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define OPERATOR_ERROR NAN
#define DIV_BY_0 INFINITY

void printHanoi(int n, char from, char to, char via, int *count) {
    if (n != 0) {
        (*count) ++;
        printHanoi(n-1, from,via,to,count); //Move first two to B
        printf("%c -> %c\n", from, to); // After the first two is moved, move last disk from A to C
        printHanoi(n-1, via,to,from,count); // Then move first two from B to C
    }
}


double add(double a, double b);
double calculation(double A, char operator, double B);
bool continue_or_not();

void getInput(double *a, char *operator, double *b) {
    printf("Enter mathematical expression. <a> <operator> <b>\n");
    scanf("%lf %c %lf",a,operator,b);

}


void printResult(double result) {

    if (result == OPERATOR_ERROR) {
        printf("Operator error\n");
    } else if (result == DIV_BY_0) {
        printf("Denominator cannot be 0\n");
    } else {
        printf("Result: %.4f\n",result);
    }
}


void calculator() {
    bool active = true;

    while (active == true) {
        double A; double B; char o; double result;
        getInput(&A,&o,&B);


        result = calculation(A,o,B);
        printResult(result);
        printf("");
        active = continue_or_not();


    }
}

int main() {
    int moves = 0;
    printHanoi(3,'A','C','B',&moves);
    printf("Moves: %d\n",moves);

    calculator();
    return 0;
}

bool continue_or_not() {
    char yn;
    printf("Calculate again? (y/n)\n");
    scanf(" %c",&yn);

    if (yn == 'y') {
        return true;
    } else return false;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double calculation(double A, char operator, double B) {

    if (B == 0) {
        return DIV_BY_0;
    }

    switch(operator) {
        case '+' : return add(A,B);
        case '-' : return subtract(A,B);
        case '*' : return multiply(A,B);
        case '/' : return divide(A,B);

        default : return OPERATOR_ERROR;
    }
}