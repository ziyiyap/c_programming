#include <stdio.h>
#include <limits.h>

// old C does not have booleans, we need to #include the <stdbool.h>
int main() {
    char name[] ="Alice"; //Each character is 1 byte, compiler autosizes to 'char name[6]', since the string includes a null terminator which indicates the end of a string. Ex. 'Alice\0'
    char letter = 'A';
    int age=30;
    float pi = 3.14; //C defaults  %f to 6 decimal points, to round of to N decimals use .Nf
    double pi_precise = 3.141592654;
    // 1-lettered strings: %c, Multi-lettered strings: %s, Integers: %d, Floats: %f, 
    printf("Name: %s \n",name);
    printf("Letter starts with: %c\n",letter); //For single charactered strings, use %c
    printf("Age: %d\n",age);
    printf("2 decimal pi: %.2f\n",pi);
    printf("pi: %f\n",pi_precise);
    //E1
    printf("\nBytes\n"); //default bytes of all data-types
    printf("char: %d bytes\n",(int)sizeof(char)); //takes the size of each data types and convert to int bytes. or we could replace as sizeof(char), and %d -> %zu
    printf("char %zu bytes\n", sizeof(char));
    printf("int: %d bytes\n",(int)sizeof(int));
    printf("float: %d bytes\n",(int)sizeof(float));
    printf("double: %d bytes\n",(int)sizeof(double));
    printf("long: %d bytes\n",(int)sizeof(long));
    printf("longlong : %d bytes\n",(int)sizeof(long long));
    //E2
    int max = INT_MAX;
    printf("\nmax int: %d\n",max); //2147483647
    printf("max+1: %d\n",max+1); //-2147483648
    /*
    Explanation:
    Assuming the direction from Alaska to Russia is left to right.
    Russia = Max, Alaska = Min
    Since the Earth is round, the Min and Max are just right each other.
    Normally, we walk the whole circumference of the Earth from the min to the max.
    However, what if we just walk one step to the right from Russia (max)?
    We end up at Alaska (min).
    Vice versa, if we walk one step to the left from Alaska (min), we end up in Russia (max).
    Since the direction is left to right, moving one step to the left is -1.
    Therefore, Max+1 = Min and Min-1 = Max
    */
    int min = INT_MIN;
    printf("min int: %d\n",min);
    printf("min-1: %d\n",min-1);
    //E3
    char letterZ = 'Z';
    printf("\nletter: %c\n",letterZ);
    printf("As number: %d\n",letterZ); //ASCII NO 90
    printf("letter+1: %c\n",letterZ+1); //[ , based on https://www.ascii-code.com/
    return 0;
} 