#include <stdio.h>
#include <string.h>

// string.h basically does the functions we built ourselves on DAY 16
//Eg. strlen, strcpy, strcmp, strcat
int main() {
    // We introduce new functions with the string.h library.

    /* 
    strtok - splits a string into tokens based on a delimiter character
    
    Eg. "Hello World", 1st token = "Hello" , 2nd token = "World", 3rd token = "" -> NULL

    Basically what it does is put a null terminator '\0' onto the delimiter
    */
    char str[] = "Alice, 30, Engineer"; // strings read from the first character first
    char *token = strtok(str,","); // In memory: [A][l][i][c][e][\0][3][0][,][E][n][g][i][n][e][e][r][\0] <- reads the first , 
    token = strtok(NULL,",");// Basically saying, start with the letter after the previous '\0'
    //In memory: [A][l][i][c][e][\0][3][0][\0][E][n][g][i][n][e][e][r][\0]
    token = strtok(NULL, ","); // Scans for next ',' but theres None, so it goes to the '\0'
    // Engineer
    token = strtok(NULL, ","); // (null)
    

    char string[] = "Hello World";
    char *tkn = strtok(string," "); // When we call strtok, the string is also modified. Therefore, string is now = "Hello\0World\0" (memory block)

    while (tkn != NULL) {
        printf("%s\n",tkn);
        tkn = strtok(NULL, " ");
    }

    /*
    strstr - Finds the occurrence of a substring inside a string. Points to the substring if found, or NULL if not found
    */

    char haystack[] = "hello world"; char needle[] = "world";

    char *pos = strstr(haystack,needle); // needle exists inside the haystack, Points to "world" (needle)
    //However, if the needle was "hello" instead, it will point to "hello".
    printf("%s\n",pos);


    // sscanf - Similarly to scanf (stdin), but it reads from a string.

    int y, m, d;
    sscanf("2026-03-26", "%d-%d-%d",&y,&m,&d);
    printf("%d, %d, %d\n",y,m,d);
    return 0;
}