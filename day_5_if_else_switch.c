#include <stdio.h>

int main() {
    int integer; 
    printf("Enter an integer: ");
    scanf("%d", &integer);
    //LOGICAL OPERATORS:
    // AND - &&
    // OR - ||
    // NOT - !
    if (integer >=2) {
        printf("%d is greater or equal to 2", integer);
    } else if (integer < 2 && integer != 0){
        printf("%d is less than 2 and greater than 0", integer);
    } else {
        printf("%d is equal to 0", integer);
    }
    return 0;
}