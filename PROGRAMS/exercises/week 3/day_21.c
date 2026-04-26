#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void addName(char names[][20], float *grades, int *count) {
    system("cls");
    char name[20]; float grade; int test;
    printf("Enter students name and grade: Ex. Billy 50\n> ");
    scanf(" %19s %f", name, &grade);

    strcpy(names[*count], name); grades[*count] = grade;
    *count +=1;
}

void printSortGrade(char names[][20], float *grades, int count) {
    system("cls");
    for (int i = 1; i < count; i ++) {
        float keygrade = grades[i]; char keyname[20];
        strcpy(keyname, names[i]);
    
        int j = i-1;
        for (j; j >=0 && grades[j] < keygrade; j--) {
            grades[j+1] = grades[j];
            strcpy(names[j+1], names[j]);
        }
        grades[j+1] = keygrade;
        strcpy(names[j+1], keyname);
        
    }

    for (int i = 0; i < count; i ++) {
        printf("%d. %s %.2f%%\n", i+1, names[i], grades[i]);
    }
    printf("\nPress enter to return...\n");
    while (getchar() != '\n');
    getchar();
}

void stats(float *grades, int count) {
    system("cls");
    float sum = 0; float min = grades[0]; float max = grades[0];
    for (int i = 0; i < count; i ++) {
        sum += grades[i];

        if (grades[i] < min) {
            min = grades[i];
        } else if (grades[i] > max) {
            max = grades[i];
        }
    }

    float mean = sum / count;
    printf("Student Statistics\nMean: %.2f%%\nMin Marks: %.2f%%\nMax Marks: %.2f%%\n", mean, min, max);
    while (getchar() != '\n');
    getchar();
}

void searchName(char names[][20], float *grades, int count) {
    system("cls");
    char find[20]; bool found = false;
    printf("Find Student: ");
    scanf(" %s", find);

    for (int i = 0; i < count; i ++) {
        if (strcmp(find, names[i]) == 0) {
            found = true;
            printf("%s : %.2f%%\n", names[i], grades[i]);
            break;
        }
    }

    if (found == false) {
        printf("Student not found\n");
    }
    while (getchar() != '\n');
    getchar();
}

void menu() {
    bool quit = false;
    char names[20][20]; float grades[20]; int count = 0;

    do {
        system("cls");
        char choice;
        printf("1. Add Student\n2. Print all sorted by grade\n3. Student Stats\n4. Search by name\n5. Quit\n> ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                addName(names, grades, &count);
                break;
            }

            case '2' :{
                printSortGrade(names, grades, count);
                break;
            }
            
            case '3': {
                stats(grades, count);
                break;
            }

            case '4': {
                searchName(names, grades, count);
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