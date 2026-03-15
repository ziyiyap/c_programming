#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //DAY 4 BIT INSPECTOR
    long long integer;
    printf("Enter an integer: ");
    scanf("%lld",&integer);
    printf("You entered: %lld\n",integer);

    for (int i = 31; i>=0; i--) {
        int check = (integer >> i) & 1;

        if ((i+1) % 8 == 0 && i != 31) {
            printf(" ");
        }
        printf("%d",check);
    }
    printf("\n");
    //Fizzbuzz
    
    for (int i = 1; i<=100; i++) {
        if (i % 15 == 0) {
            printf("FizzBuzz\n");
        } else if (i % 5 == 0) {
            printf("Buzz\n");
        } else if (i % 3 == 0) {
            printf("Fizz\n");
        } else {
            printf("%d\n",i);
        }
    }
    //DAY 5 MINI TASK - CONTINUED
    int choice;
    do {
    printf("\n1. km to miles\n2. kg to lbs\n3. Celcius to Fahrenheit\n4. Quit\n");
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

        case 4:
            break;
        default:
        printf("Invalid choice.");
    }
    } while (choice != 4);

    //E1 PRIME CHECKER

    for (int num = 1; num <=100; num++ ) {
        int found = 0;
        if (num != 1) {
            for (int prime_check = num-1; prime_check >= 2; prime_check--) {
                if (num % prime_check == 0) {
                    found = 1;
                    break;
                }
            }
        } else {
            found = 1;
        }
        if (found == 0) {
            printf("%d is PRIME\n",num);
        } else if (found == 1) {
            printf("%d is NOT PRIME\n", num);
        }
    }
    //GUESSING GAME
    srand(time(NULL)); //srand(num), it sets the seed based on the num (starting point).
    //time() returns number of seconds since Jan 1, 1970
    //NULL means we are not setting anything to a variable. However we can pass in a variable to store it. Eg. time_t variable; time(&variable)
    //rand() generates a 'random' number based on a formula. When we run the code many times in a second using time(NULL), the number generated will always be the same because its the same second, so srand() passes in the same value.
    int secret = rand() % 100 +1; // If we obtain the remainder of any N value, the remainder will always be in the N value range. (0 to N-1)
    int user_input;
    int attempts = 0;
    int max = 100;
    int min = 1;

    do {
        printf("Guess a number from %d-%d!\n",min,max);
        scanf("%d",&user_input);

         if (user_input > max || user_input < min) {
            printf("Out of range! Is this satire?!\n");
        }

        else if (user_input > secret) {
            printf("Too high! ");
            max = user_input;
        } else if (user_input < secret) {
            printf("Too low! ");
            min = user_input;
        }
        else {
            printf("You got it! ");
        }

        attempts ++;

    } while (user_input != secret);
    printf("Total attempts: %d\n", attempts);

    int i;
    printf("Enter an integer: ");
    scanf("%d",&i);

    int sum = 0;
    while (i != 0) {
        int remainder = i % 10;
        i = i/10;
        sum = sum + abs(remainder);
        
    }

    printf("Sum: %d\n",sum);
    //12x12
    for (int row = 1; row<=12; row++){
        for (int col=1; col<=12; col++){ //inner loop finishes a loop first, then only proceed to the next outer loop.
            printf("%4d", row*col);
        } printf("\n");
        
    }
    return 0;
}