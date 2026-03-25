#include <stdio.h>

/*
There are two types of functions: (void), (datatype) 
void - does something and gives nothing back
datatype - does something and GIVES something back.

Examples
*/
//voids
void printHello() {
    printf("Hello");
} // <- does not need to return because voids do not return

//datatypes, Two forms

//FORM 1
int add(int a,int b); //<- declare function first

//FORM 2
int subtract(int a,int b) {
    return a-b;
}

int main() {
    printHello(); // Prints "Hello"
    printf("\n%d\n",add(5,2)); //7
    printf("%d\n",subtract(5,2)); //3
} 

//FORM 1
int add(int a, int b) {
    return a+b; //<- returns sum of two numbers
}