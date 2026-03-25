#include <stdio.h>
#include <stdbool.h>

void myStrcpy(char *dst, char *src) {
    int i = 0;
    for (i; src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    dst[i] = '\0';
}

void myStrcat(char *dst, char *src) {
    int null_index = 0;
    for (null_index; dst[null_index] != '\0'; null_index++) {
    }

    int i = 0;
    for (i; src[i] != '\0'; i++) {
        dst[null_index + i] = src[i]; //starts at null_index
    }

    dst[i + null_index] = '\0';
}

void upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((int)str[i] >= 'a' && (int)str[i] <= 'z') {
            int conversion = str[i] - 32;
            str[i] = conversion;
        }
    }
}

void lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((int)str[i] >= 'A' && (int)str[i] <= 'Z') {
            int conversion = str[i] + 32;
            str[i] = conversion;
        }
    }
}

int myStrlen(char *str);
int myStrcmp(char *strA, char *strB);
int countWords(char *str);


void reverseString(char *str) {
    int start = 0; int end = myStrlen(str) - 1; 

    while (start < end) { // so when start >= end, the loop breaks
        char temp = str[start];

        str[start] = str[end];
        str[end] = temp;

        start++; end --;
    }
}

void isAnagram(char *strA, char *strB) {
    bool anagram = true;
    int count[26] = {0}; // Set an array with 26 slots

    // For an anagram, the sum of increments and decrements must all be 0.

    for (int i = 0; strA[i] != '\0'; i++) {
        count[ strA[i] - 'a'] ++; // ASCII value of 'a' = 97, so index starts at 0, 1, 2, ...
    }

    for (int j = 0; strB[j] != '\0'; j++) {
        count[ strB[j] - 'a'] --;
    }

    for (int i = 0; i < 26; i++) {
        if (count[i] != 0) {
            anagram = false;
        }
    }

    if (anagram == true) {
        printf("Anagram");
    } else printf("Not anagram");

}


int main() {
    //E1
    char str[] = "Hello";
    printf("%d\n",myStrlen(str));
    
    char dst[20];
    char src[] = "World";
    myStrcpy(dst,src);
    printf("%s\n",dst); //Copies src into dst

    char src_[] = "world";
    char dst_[] = "hello";

    myStrcat(dst_, src_);
    printf("%s\n",dst_);

    printf("%d\n",myStrcmp("abc","ab"));

    //E2

    printf("%d\n",countWords(""));

    //E3
    char str_[] = "Hello World";
    reverseString(str_);

    printf("%s\n",str_);

    //E4

    char l[] = "Hello WOrld";
    upper(l);
    printf("%s\n",l);
    lower(l);
    printf("%s\n",l);

    //E5

    char a[] = "silent"; char b[] = "listen";
    isAnagram(a,b);
    return 0;
}

int myStrlen(char *str) {
    int length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        length ++;
    }

    return length;
}

int myStrcmp(char *strA, char *strB) {
    int lenA = myStrlen(strA); int lenB = myStrlen(strB); char *str;

    if (lenA > lenB) {
        str = strA;
    } else {
        str = strB;
    }

    for (int i = 0; str[i] != '\0'; i++) { // Alternatively, while strA[i] != '\0' && strB[i] != '\0'
        if (strA[i] - strB[i] != 0) {
            return strA[i] - strB[i];
        }
    }

    return 0;
}

int countWords(char *str) {
    int count = 0;
    if (str[0] != ' ' && str[0] != '\0') {count++;}
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i-1] == ' ') {
            count++;
        }
    }

    return count;
}
