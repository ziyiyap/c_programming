#include <stdio.h>

int main() {
    //BITWISE DIGITS: 0 and 1
    int AND = 5 & 3; // = 1. It converts 5 and 3 into binary which is 101 and 011, and check whether each column of bitwise digits are the same. (AND), 
    // First column: 1 AND 0 = TRUE AND FALSE = FALSE = 0
    // Second column: 0 AND 1 = FALSE AND TRUE = FALSE = 0
    // Third column: 1 AND 1 = TRUE AND TRUE = TRUE = 1
    // Extra: 0 AND 0 = FALSE AND FALSE = FALSE = 0

    // So the answer is 001 in binary which is also 1 in decimal.
    printf("%d\n",AND);

    int OR = 6 | 4; // =6. It converts 6 and 4 into binary which is 110 and 100, and check whether each column of digits has 1. (OR)
    // First column: 1 OR 1 = TRUE OR TRUE = TRUE = 1
    // Second column: 1 OR 0 = TRUE OR FALSE = TRUE = 1
    // Third column: 0 OR 0 = FALSE OR FALSE = FALSE = 0

    // So the answer is 110 in binary which is also 6 in decimal.
    printf("%d\n",OR);

    int XOR = 5 ^ 3; // = 6. It converts 5 and 3 into binary which is 101 and 011, and check whether each column of bitwise digits have same bits (0) or different bits (1).
    // First column: 1 XOR 0 = TRUE = 1
    // Second column: 0 XOR 1 = TRUE = 1
    // Third column: 1 XOR 1 = FALSE = 0

    //EXTRA: 0 XOR 0 = FALSE = 0
    //So the answer is 110 in binary which is 6 in decimal.
    printf("%d\n",XOR);

    int LEFTSHIFT = 5 << 3;
    // Convert 5 into binary: 101
    // Move 101 3 digits to the left -> 101000
    // Convert 101000 back to decimal -> 40

    //Formula: k << n == k2**n
    printf("%d\n",LEFTSHIFT);

    int RIGHTSHIFT_1 = 5 >> 3;
    // Convert 5 into binary: 101
    // Move 101 3 digits to the right -> 0
    printf("%d\n", RIGHTSHIFT_1);

    int RIGHTSHIFT_2 = 8 >> 2;
    // Convert 8 into binary: 1000
    // Move 1000 two digits to the right -> 10
    // Convert 10 back to decimal -> 2 

    //Formula : k >> n == k/(2**n)
    printf("%d\n", RIGHTSHIFT_2);
    return 0;
}