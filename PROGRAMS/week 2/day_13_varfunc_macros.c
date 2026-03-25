#include <stdio.h> // this is a preprocessor directive
#include <stdarg.h> //allows functions to accept an indefinite number of arguments

//Macros

#define PI 3.141592654 // This is a macro, it replaces 'PI' into 3.141592654 when you call it
// everywhere you write PI, the preprocessor replaces it with 3.14159


#define DOUBLE(x) x + x

#define DOUBLE_(x) (x+x)

//Variadic Functions
void sum(int count, ...) { // number of arguments after count must match the number of count, otherwise it will produce garbage values
    va_list args; //Declare args variable with type va_list
    // C functions store arguments in memory like: [n = arg0][arg1][arg2][arg3]...

    va_start(args,count); // count auto sets to the value given, Eg. count = 3 when sum(3,...),
    int total = 0;
    for (int i = 0; i < count; i++) {
        int num = va_arg(args,int); //Go to next element in the argument, and check for integers 
        total += num;
    }
    va_end(args);
    printf("Sum: %d",total);
}

int main() {
    printf("%f\n",PI); //3.141592654

    int result = 10 * DOUBLE(3); // It replaces DOUBLE(3) into 3 + 3, so 10 * 3 + 3 = 33
    int r = 10 * DOUBLE_(3);


    printf("%d\n",result);
    printf("%d\n",r); //It replaces DOUBLE_(3) into 3 + 3, so 10 * (3 + 3) = 60  (PEMDAS)

    sum(6, 1,3,5,7,9,11);
    return 0;
}
