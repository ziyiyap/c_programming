#include <stdio.h>

int main() {
    // FOR loops syntax: for (variable; condition; what it should do;) {}
    for (int i = 1; i<=10; i++) { //i++ means i+=1 (python)
        printf("%d\n",i);
    }

    // WHILE loops syntax : while (condition) {}
    int x = 0;
    while (x >= -10) { // checks the condition first, then only runs the loop. 
        printf("%d\n",x);
        x--;
    }

    //DO-WHILE loops, syntax: do {body} while (condition);
    int integer =1;
    do { //runs the block first THEN only check condition, hence it always run at least once.
        printf("%d\n",integer);
        integer++;
    } while (integer<=10);
    return 0;

}