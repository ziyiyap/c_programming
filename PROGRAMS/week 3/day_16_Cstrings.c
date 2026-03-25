#include <stdio.h>

void printVertical(char *str) {

    for (int i = 0; *(str + i) != '\0'; i++) {
        printf("%c\n",*(str + i));
    }

}


int main() {
    // There are two types to declare a string.

    // Type 1
    char str[] = "Hello World"; // This type of string is modifiable.

    //Type 2
    char *string = "Hello World"; // This type of string is not modifiable, it can cause undefined behavior.

    // Technically, when we do printf("%s",string); , internally it does

    for (int i = 0; string[i] != '\0'; i++) { // Recall: Strings end with a null terminator, '\0'.
        printf("%c",string[i]);
    }
    printf("\n");

    // Since strings are "array of characters" , it will turn to '&str[0]' (address of the first element) when we pass it onto a function.
    printVertical(string);
}