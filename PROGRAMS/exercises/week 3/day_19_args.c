#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    for (int i = 0; i < argc; i ++) {
        printf("%s\n",argv[i]);
        printf("%d\n",strlen(argv[i]));
    }

    // For i = 0; it always prints the program file PATH,
    // For i > 0; we have to add the argument ourselves with the command below.
    return 0;
}
// Terminal: ./day_19_args hello world 123