#include <stdio.h>
#include <string.h>

void trim(char *s) {
    // Recall: we obtain the memory address of the first index of the string when it is passed onto a function.

    int end = strlen(s) -1;
    while (s[end] == ' ') {
        end--;
    }
    s[end+1] = '\0';
    
    int i = 0;
    while (s[i] == ' ') {
        i++;
    }
    strcpy(s,s+i); // copies from string -> string +1(index)


    
}

int startsWith(char *haystack, char *needle);
int endsWith(char *haystack, char *needle);


int main() {
    //E1
    char csvstr[] = "Alice, 30, Engineer";

    char *token = strtok(csvstr,",");

    while (token != NULL) {
        printf("%s ",token);
        token = strtok(NULL, ",");
    }
    printf("\n");
    //E2
    char haystack[] = "this is a test"; char needle[] = "is";
    /* haystack has memory address of 1000 (assuming) 
    
    Recall: char has size of 1 byte 
    
    *pos gives us the memory address of the first occurrence of 'is', which is 1002.
    
    To obtain the index number, (1002-1000)/1 = 2*/
    char *pos = strstr(haystack,needle);
    pos = strstr(pos+1,needle); // <- Assuming pos = 1002, 1002 + 1 = 1003. This means that the second strstr points at the 3rd index and searches for the next 'is'.
    printf("%d\n",pos-haystack); // <- we get the index of the next 'is'.
    //ACTUAL
    char *pos1 = strstr(haystack,needle);

    while (pos1 != NULL) {
        int index = pos1 - haystack;
        printf("%d ",index);
        pos1 = strstr(pos1+1,needle);
    }
    printf("\n");
    //E3
    char string[] = " hello world ";
    trim(string); 
    printf("%s\n",string);

    //E4

    int y,m,d;
    char date[] = "2024-03-15";
    sscanf(date,"%d-%d-%d",&y,&m,&d);

    printf("%d, %d, %d\n",y,m,d);

    //E5
    char h[] = "Clash Royale"; char s[] = "Clash"; char e[] = "Royale";
    printf("%d\n",startsWith(h,s));
    printf("%d\n",endsWith(h,e));
    


    return 0;
}

int startsWith(char *haystack, char *needle) {
    int n = strlen(needle);

    if (strncmp(haystack,needle,n) == 0) {
        return 1;
    } else return 0;
}
int endsWith(char *haystack, char *needle) {
    int n = strlen(haystack) - strlen(needle); // Eg. haystack = "hello world" (10 indices), needle = "world" (4 indices), 10-4= 6, therefore we start at index 6 to find "world".

    if (strncmp(haystack+n,needle,strlen(needle)) == 0) {
        return 1;
    } else return 0;
}