#include <stdio.h>
//similar to python's import

//main() is the function, and int is the return type. We can see that the function returns 0 (int)
int main() {
    char name[6] ="Alice";
    int age=30;
    float cash = 3456.78;
    // old C does not have booleans, we need to #include the <stdbool.h>
    printf("Hello %s! You are %d years old. Your bank account currently holds $%.2f.\n",name,age,cash);
    return 0;
} 