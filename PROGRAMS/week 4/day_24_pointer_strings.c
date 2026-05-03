#include <stdio.h>
#include <string.h>

int main() {

    char string[] = "This is a mutable string.\n"; 
    char *str = "This is an immutable string.\n";

    string[0] = 'D';
    printf("%s", string); // Dhis is a mutable string

    /*
    str[0] = 'D';

    This will cause undefined behavior.
    */

    //String pointers

    char *p = str; //Points to the first character address of the string (&str[0])

    for (int i = 0; *(p + i) != '\0'; i ++) {
        printf("%c", *(i + p)); // This is an immutable string
    }
}