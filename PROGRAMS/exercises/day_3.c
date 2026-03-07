#include <stdio.h>

int main() {





    //E3
    // syntax: fgets(name, sizeof(name), stdin) <- stdin means standard input = keyboard
    char name[50];
    printf("\nEnter name: ");
    fgets(name, sizeof(name), stdin); 
    printf("Your name is %s",name); //fgets automatically sets a newline, so \n isnt needed
    printf("Hello!\n");

    //E1
    double celcius;
    printf("Enter celcius: ");
    scanf("%lf",&celcius);
    double fahrenheit = celcius * ((double)9/5) +32;
    printf("Temperature in Fahrenheit: %.2f F\n",fahrenheit);

    //E2
    int a; int b;
    printf("Enter integers: <a> <b>\n");
    scanf("%d %d", &a, &b);
    int sum = a + b;
    int diff = a - b;
    int prod = a * b ;
    double div =  (double)a /b ; //we dont (float) a double variable, to keep it full precision
    printf("Sum: %d Difference: %d Product: %d Quotient: %.2lf\n",sum,diff, prod,div);

    //E4
    int index;
    printf("Enter an integer: ");
    scanf("%d",&index);
    printf("Decimal: %d Octal: %o Hex: %x \n", index, index, index);

    //E5
    printf("%-10s %-10s %5s", "Num","Square","Cube");
    printf("\n---------------------------");
    printf("\n%-10d %-10d %5d",1,1,1);
    printf("\n%-10d %-10d %5d",2,2*2,2*2*2);
    printf("\n%-10d %-10d %5d",3,3*3,3*3*3);
    printf("\n%-10d %-10d %5d",4,4*4,4*4*4);
    printf("\n%-10d %-10d %5d",5,5*5,5*5*5);
    printf("\n%-10d %-10d %5d",6,6*6,6*6*6);
    printf("\n%-10d %-10d %5d",7,7*7,7*7*7);
    printf("\n%-10d %-10d %5d",8,8*8,8*8*8);
    printf("\n%-10d %-10d %5d",9,9*9,9*9*9);
    printf("\n%-10d %-10d %5d",10,10*10,10*10*10);
    return 0;
}