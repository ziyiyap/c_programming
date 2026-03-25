#include <stdio.h>

int main() {
    //E1
    int grade;
    printf("Enter grade marks: ");
    scanf("%d", &grade);

    if (grade >= 90 && grade <= 100) {
        printf("A");
    } else if (grade >= 80) {
        printf("B");
    } else if (grade >= 70) {
        printf("C");
    } else if (grade >= 60) {
        printf("D");
    } else if (grade < 60 && grade >=0) {
        printf("F");
    } else {
        printf("Invalid grade");
    }

    //E2
    double a; double b; char operator;
    printf("\nSimple Calculator\nUsage: <a> <operator> <b>\n");
    scanf("%lf %c %lf", &a, &operator, &b);
    switch(operator) {
        case '+':
            printf("%.2f + %.2f = %.2f",a,b, a+b);
            break;
        case '-':
            printf("%.2f - %.2f = %.2f",a,b, a-b);
            break;
        case '*':
            printf("%.2f * %.2f = %.2f",a,b, a*b);
            break;
        case '/':
            if (b != 0) {
                printf("%.2f / %.2f = %.2f",a,b, a/b);
                break;
            } else {
                printf("Denominator cannot be 0");
                break;
            }
        default: //If all cases doesnt match, then its invalid. breaking is necessary otherwise it will default too.
            printf("Invalid");
    } 

    //E3 Leap year checker
    long long year;
    printf("\nEnter year: ");
    scanf("%lld", &year);

    if (year % 400 == 0) {
        printf("Leap (century year)");
    } else if (year % 100 == 0) {
        printf("Not leap") ;
    } else if (year % 4 == 0) {
        printf("Leap");
    } else {
        printf("Not leap");
    }
    //MINI TASK
    int choice;
    printf("\n1. km to miles\n2. kg to lbs\n3. Celcius to Fahrenheit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1: {
            double km;
            printf("Enter km: ");
            scanf("%lf",&km);
            printf("%.2f km = %.2f mi", km, km /1.609);
            break;
        }
        case 2: {
            double kg;
            printf("Enter kg: ");
            scanf("%lf",&kg);
            printf("%.2f kg = %.2f lbs", kg, kg * 2.205);
            break;
        }
        case 3: {
            double celcius;
            printf("Enter celcius: ");
            scanf("%lf",&celcius);
            double fahrenheit = celcius * ((double)9/5) +32;
            printf("Temperature in Fahrenheit: %.2f F\n",fahrenheit);
            break;
        }
        default:
        printf("Invalid choice.");
    }
    return 0;
}