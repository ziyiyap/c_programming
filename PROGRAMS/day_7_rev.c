#include <stdio.h>


int main() {
    //Palindrome checker
    int i;
    int palindrome = 0;
    printf("Enter an integer: ");
    scanf("%d",&i);
    int i_copy = i ;
    while(i_copy!=0) {
        palindrome = palindrome * 10 + (i_copy %10);
        i_copy = i_copy / 10;
    }
    if (i == palindrome) {
        printf("%d is a palindrome number!\n",i);
    } else {
        printf("%d is NOT a palindrome number!\n",i);
    }
    //Collatz Conjecture
    int n;
    int steps = 0;
    printf("Enter an integer: ");
    scanf("%d",&n);
    do {
        printf("%d -> ", n);
        if (n % 2 == 0) {
            n = n /2;
        } else {
            n = (3 *n) +1;
        }
        steps ++;
    } while (n != 1);
    printf("%d\n",n);
    printf("\nSteps: %d\n",steps);
    
    //DIAMONDS
    int width;
    printf("Enter max odd width: ");
    scanf("%d",&width);
    //space = (width-stars)/2
    for (int rows = 1; rows <= width/2 +1; rows++) {
        for (int spaces = 0; spaces < width/2 +1 - rows; spaces ++) {
            printf("%c",' ');
        } 
        for (int stars = 0; stars <2 * rows -1; stars ++) {
            printf("%c",'*');
        } printf("\n");
    }  
    for (int rows = 1; rows <= width/2; rows++) {
        for (int spaces = 0; spaces < rows; spaces ++) {
            printf("%c",' ');
        } 
        for (int stars = 0; stars <width - 2*rows; stars ++) {
            printf("%c",'*');
        } printf("\n");
    }  
    return 0;
}