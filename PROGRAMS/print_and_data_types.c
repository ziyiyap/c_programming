#include <stdio.h>
//similar to python's import

//main() is the function, and int is the return type. We can see that the function returns 0 (int)
int main() {
    char name[] ="Alice"; //Each character is 1 byte, compiler autosizes to 'char name[6]', since the string includes a null terminator which indicates the end of a string. Ex. 'Alice\0'
    int age=30;
    float cash = 3456.78;
    // old C does not have booleans, we need to #include the <stdbool.h>
    printf("Hello %s! You are %d years old. Your bank account currently holds $%.2f.\n",name,age,cash); //% and the variable must be in order. %.2f means 2 decimal point float
    return 0;
} 