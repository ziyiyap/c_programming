#include <stdio.h>
#include <stdbool.h>

int main() {
    bool quit = false;
    int a;
    char operator;
    int b;
    do {
        printf("Enter mathematical expression. <a> <operator> <b>\n");
        scanf("%d %c %d",&a, &operator, &b);
        
        switch(operator) { 
            case '+': {
                printf("%d\n", a+b);
                break;
            }
            case '-': {
                printf("%d\n", a-b);
                break;
            }
            case '*': {
                printf("%d\n", a*b);
                break;
            }
            case '/': {
                if (b == 0) {
                    printf("Denominator cannot be zero.\n");
                    break;
                } else {
                printf("%.2f\n", (float)a/b);
                break; 
                }
            }
            case '%': {
                if (b == 0) {
                    printf("Denominator cannot be zero.\n");
                    break;
                } else {
                printf("%d\n", a%b);
                break;
                }
            }
            default: 
                printf("Invalid expression.\n");
        }
        char yn;
        
        printf("Calculate again? (y/n)\n");
        scanf("\n%c",&yn);

        if (yn == 'y') {
            quit = false;
        } else if (yn == 'n') {
            quit = true;
        } else {
            printf("Invalid option.\n");
        }

    } while (quit != true);
    return 0;
}