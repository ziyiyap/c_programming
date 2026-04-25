#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void addName(char names[][20], float *grades, int *count) {
    system("cls");
    char name[50]; float grade; int test;
    printf("Enter students name and grade: Ex. Billy 50\n> ");
    scanf(" %49s %f", name, &grade);

    strcpy(names[*count], name); grades[*count] = grade;
    *count +=1;
}

void menu() {
    bool quit = false;
    char names[20][20]; float grades[20]; int count = 0;

    do {
        system("cls");
        char choice;

        for (int i = 0; i < count; i ++) {
            printf("%s %f\n", names[i], grades[i]);
        }
        printf("1. Add Student\n2. Print all sorted by grade\n3. Student Stats\n4. Search by name\n5. Quit\n> ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                addName(names, grades, &count);
                break;
            }

            case '5' : {
                quit = true;
                break;
            }

    
        }
        
    } while (quit != true);
}

int main() {
    menu();
    return 0;
}