#include <stdio.h>

long long factorial(long long n);
long long fib(int n);
long long sumDigits(int n);

void printh(char from, char to) {
    printf("%c -> %c\n", from, to);
}

void hanoi(int n, char from, char to, char via) { // n-disks, A, B, C rods
    if (n != 0) {
        hanoi(n-1, from, via,to); // 'A', 'B', 'C'
        printh(from,to);
        hanoi(n-1,via,to,from);
        
    }
}

/* Say n = 3, 'A', 'C', 'B'. 

hanoi(3, 'A', 'C', 'B')

        hanoi(2, 'A', 'B','C');

        -> hanoi(1,'A','C','B')

            -> hanoi(0,'A','B','C') (ignored)
                printh('A','C'); [A -> C]
            -> hanoi(0,'B','C','A') (ignored)

        printh('A', 'B') [A -> B]

        -> hanoi(1,'C','B','A')

            -> hanoi(0, 'C', 'A', 'B') (ignored)
                printh('C', 'B'); [C -> B]
            -> hanoi(0, 'A', 'B', 'C') (ignored)

    printh('A','C'); [A -> C]

        hanoi(2,'B','C','A');

        -> hanoi(1,'B','A','C')

            -> hanoi(0,'B','C','A') (ignored)
                printh('B','A'); [B -> A]
            -> hanoi(0,'C','A','B') (ignored)

        printh('B', 'C') [B -> C]

        -> hanoi(1,'A','C','B')

            -> hanoi(0, 'A', 'B', 'C') (ignored)
                printh('A', 'C'); [A -> C]
            -> hanoi(0, 'B', 'C', 'A') (ignored)

*/

int main() {
    printf("%lld\n",factorial(15));
    printf("%lld\n",fib(40));
    printf("%lld\n",sumDigits(9999));

    hanoi(3, 'A','C','B');
    return 0;
}
// factorial(5) -> result = 1 * parameter -> return factorial(5-1) -> result = 5*4 -> return factorial(4-1) -> result = 20*3 -> return factorial(3-1) -> result = 60 * 2 -> return factorial(2-1) -> result = 120*1
long long factorial(long long n) {
    if (n >= 1) {
        return n * factorial(n-1);
    } else if (n == 0) {
        return 1;
    } else {
        printf("Factorial cannot be negative");
        return -1; //Signals an error
    }

}

long long fib(int n) { // 0,1, 1,2, 3,5, 8,13, 21,34,...
    if (n == 0 || n == 1) return n; else {
        return fib(n-1) + fib(n-2);
    }
}

long long sumDigits(int n) { // n = 1234, take n%10 = 4, n=123, ...
    int sum = 0;
    if (n == 0) return n; else {
        sum = n % 10;
        int result = n / 10;
        return sum + sumDigits(result);
    }
}