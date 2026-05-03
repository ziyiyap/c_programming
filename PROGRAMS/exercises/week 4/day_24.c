#include <stdio.h>

int strLen(char *s); //Ex1
char *myStrchr(char string[], char target); // Ex2
char *strReverse(char *start); //Ex3

void removeSpace(char *str) { // Ex 4
    char *read = str; char *write = str;
    while ( *read != '\0') {

        if (*read != ' ') {
            *write = *read;
            write++;
        }
        read++;
    }

    *write = '\0';
}

int main() {
    char string[] = "Hello";
    char *p = string;
    printf("%d\n", strLen(p)); //5 

    char *result = myStrchr(string, '\0');

    printf("%s\n", result);
    printf("%s\n", strReverse(p));

    char sentence[] = "H                                                                                     a                                                       l                       l       o";

    removeSpace(sentence);
    printf("%s", sentence);
    return 0;
}

int strLen(char *s) {
    int i = 0;
    for (; *(i + s) != '\0'; i ++){}
    return i;
}

char *myStrchr(char string[], char target) {
    if (target == '\0') {
        return string + strLen(string);

    } else {
        for (int i = 0; i[string] != '\0'; i ++) {
            if (*(i + string) == target) {
                return string + i;
            }
        }
        return NULL;
    }
}

char *strReverse(char *start) {
    // *s - starting pointer
    char *p = start;
    char *end = start + strLen(p) -1 ;

    while (p < end) { // checks if the end address is after the start address
        char temp = *p;
        *p = *end;
        *end = temp;

        p ++ ; end --;
    }
    return start;
}