#include <stdio.h>

int main() {
    char name[50]; //we need to specify how many bytes allocated into the string variable.
    printf("Enter your name: ");
    scanf("%49s",name); //49 bytes of characters + 1 byte of null terminator. \0
    printf("Your name is %s\n", name);

    int age; double height;
    printf("Enter age and height: ");
    scanf("%d %lf",&age, &height); //Except for strings, all variable datatypes require & to address it. without &: You are 3223552 years old. The number given is the amount of bytes of the variable.
    // user input must be passed as: int float
    printf("You are %d years old\n", age); //scanf needs to declare a & onto the variable while printf does not.
    printf("You are %.2f cm tall\n", height);

    printf("INFO:\n %-10s | %3d | %.2f\n", name, age, height);
    
    double pi;
    printf("Enter the value of pi: ");
    //long: win: 4 bytes, mac/linux : 8bytes,  float: 4 bytes, double: 8 bytes
    // long = upgraded version of a data type. Since pi is a double, we need to use %lf. (long double, %Lf.)
    // the default maximum of an upgraded float is 8 bytes.
    scanf("%lf",&pi); //scanf is specific. it needs to know how many bytes we are allocating. Since we are allocating a double, it requires 8 bytes.
    printf("%f",pi); //printf isnt specific, it automatically rounds off the number based on how many bytes the format specifier has. (%s, %d, %f, ...)
    return 0;
}