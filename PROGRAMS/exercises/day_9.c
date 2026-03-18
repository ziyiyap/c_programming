#include <stdio.h>

//counter()

void counter() {
    static int count = 0;
    count++;
    printf("Count: %d\n",count);
}

//Show that two functions can each have a local var named x without conflict

void funcA() {
    int x = 5;
    printf("FuncA: x = %d\n",x);
}

void funcB() {
    int x = 5;
    printf("FuncB: x = %d\n",x);
}

//Variable shadowing

int y = 5;

void funcC() {
    int y = 10;
    printf("FuncC: Y = %d\n",y); // Y=10. LOCAL takes priority.
}


//"Remembering functions"
void remember(int user_val) {
    static int r = 0;
    printf("%d\n",r);
    r = user_val;
}

void countdown(int i) {
    if (i > 0) {
        printf("%d\n",i);
        countdown(i-1);
    }
}

int main() {
    for (int times = 1; times <=5; times++) {
        counter();
    }
    printf("\n");
    funcA(); funcB(); funcC();
    printf("MAIN: Y = %d\n",y);
    remember(10); remember(25); remember(7); //0 10 25
    printf("\n");
    countdown(100);
    return 0;
}