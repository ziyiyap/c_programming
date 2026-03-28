#include <stdio.h>
#include <string.h>

void printStrArr(int n, char strarr[][30]) { // The array passed decays into a pointer that points to the first element. strarr[0]
// Alternatively,  char strarr[][30] can be also written as char **strarr (a pointer to a pointer)

    for (int i = 0; i < n; i ++) {
        printf("%s\n",strarr[i]);
    }
}

int main() {

    // In C, strings are arrays of characters. There are two methods to store multiple strings.
    // Method 1: 2D char array
    char strarr[3][30] = {
        "Alice",
        "Bob",
        "Charlie"
    };
    /* Technically, internally it is
    
        char strarr[3][30] = {
        {'A','l','i','c','e','\0'},
        {'B','o','b','\0'},
        {'C','h','a','r','l','i','e','\0'}
        };
    */

    // To access a specific character of the array of strings, Eg. 'o' in Bob

    printf("%c\n",strarr[1][1]); // Remember, %c because we access the CHARACTER of the string

    // Method 2: Array of pointers

    char *names[30] = {
        "David",
        "John",
        "Daniel"
    }; // Each pointer points to the first character of the string.

    printf("%c\n",names[0][0]); // Pointing to 'D' in David

    // To loop the array of strings,

    for (int i = 0; i < 3; i ++) {
        printf("%s\n",names[i]);
    }

    // Alternatively, (if ur bored as hell)
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < strlen(names[i]); j ++) {
            printf("%c",names[i][j]);
        }
        printf("\n");
    }

    // Recall: A string decays into a pointer that points to its first character when it is passed onto a function.
    printStrArr(3, strarr);
    return 0;
}