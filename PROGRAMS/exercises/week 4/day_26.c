#include <stdio.h>
#include <stdlib.h>

void printString(const char *s) { // Ex 1
    printf("%s\n", s);

    /*
    The characters are protected, not the pointer.

    - s[0] = 'T' will raise compiler error.

    Question: Why should we add 'const' into the char parameter?
    
    Explanation:
    
    So that a char var with or without 'const' can be passed onto the function.
    If the var is a const char but the func parameter is not const char it will raise error
    */
}

void copyArray(const int *src, int *dst, int n) {
    // const int *src because the source array must not be modified.
    // no const, dst because we NEED to modify dst.

    for (int i = 0; i < n; i ++) {
        dst[i] = src[i];
    }
}

const char* getDay(int n);

int main() {
    char string[] = "This is a string";
    printString(string);

    // Ex 2
    int a = 96; int b = 69;
    const int *p = &a;
    int * const q = &a;

    /* 
    *p = 30;
    
    ERROR:
            day_26.c:28:8: error: assignment of read-only location '*p'
            *p = 30;
                ^

    We are NOT able to modify the value through the pointer.
    Solution: reassign via the original variable that is pointed from the pointer.

    q = &b;

    ERROR:

            day_26.c:41:7: error: assignment of read-only variable 'q'
            q = &b;
            ^
    We are NOT able to reassign a address of another variable to the pointer.
    Solution: Redefine a new value via *q.
    */

    // Ex 3

    const char *day = getDay(4);
    printf("%s\n", day);
    printf("%s\n", getDay(1));

    // Ex 4: IN EXERCISES

    // Ex 5:

    const int src[5] = {3,2,5,1,9};
    int *dst = malloc(sizeof(int) * 5);
    copyArray(src, dst, 5);
    
    for (int i = 0; i < 5; i ++) {
        printf("%d ", dst[i]);
    }
    printf("\n");
    free(dst);

    return 0;
}

const char* getDay(int n) {
    if (n < 0 || n > 6) {
        return "'n' must be in range 0-6";
    }
    static const char *days[7] = { // initialized only once, const for matching the data-type of the variable passed.
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    return days[n];
}