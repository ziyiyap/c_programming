#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//E1
void sortStrArr(int n, int size, char strarr[][size]) {
    int min_index;
    for (int i = 0; i < n; i ++) {
        min_index = i;
        for (int j = i+1 ; j < n; j ++) {
            if (strcmp(strarr[min_index], strarr[j]) > 0) {
                min_index = j;
            }
        }
    char temp[size];

    strcpy(temp,strarr[min_index]);
    strcpy(strarr[min_index],strarr[i]);
    strcpy(strarr[i],temp);

}
}
//E2
void stringSearch(int n, int size, char strarr[][size], char target[]) {
    // Lower each string first, including the target

        // Strings
    for (int str_index = 0; str_index < n; str_index ++) {
        for (int char_index = 0; char_index < strlen(strarr[str_index]); char_index++) {
            if ((int)strarr[str_index][char_index] >= 'A' && (int)strarr[str_index][char_index] <= 'Z') {
                int conversion = strarr[str_index][char_index] + 32;

                strarr[str_index][char_index] = conversion;
            }
        }
    }
        //target

    for (int target_index = 0; target_index < strlen(target); target_index ++ ) {
        if ((int)target[target_index] >= 'A' && (int)target[target_index] <= 'Z') {
            int target_conv = target[target_index] + 32;

            target[target_index] = target_conv;
        }
    }
    // Search
    bool found = false;
    for (int i = 0; i < n; i ++) {
        if (strcmp(strarr[i],target) == 0) { //strcmp does char by char comparison
            found = true;

        }
    }

    if (found == true) {
        printf("%s exists in the array.\n", target);
    } else printf("%s does not exist in the array.\n",target);

}

void uniqueCount(char sentence[]) {
    // Declare variables

    char words[100][30]; // Set a fixed max of 100 strings, each with maximum 30 size
    int counts[100] = {0}; //Initialise counts at 0 value
    int unique = 0;


    // Get first token
    char *token = strtok(sentence," ");

    while (token != NULL) {
        bool exists = false; // Assuming that the current token does not exist
        int i = 0;
        for (i; i < unique; i ++) {
            if (strcmp(words[i],token) == 0) { // If the ASCII value of both strings are same, exists
                exists = true;
                counts[i] ++; // Add count according to the word index
                break;
            }
        }

        if (exists == false) {
            strcpy(words[unique],token); // If it doesnt exist, append the current word into the words array
            counts[unique] = 1; // Set the current word count to 1 in the counts array
            unique++;
        }

        token = strtok(NULL, " ");
    }

    //printing

    for (int j = 0; j < unique; j ++) {
        printf("%s : %d\n",words[j], counts[j]);
    }
}

char *join(char **words, int n, char sep);

int main() {
    char names[5][30] = {"Isaac", "Royce", "Apple", "Bob", "Charlie"};
    int size = sizeof(names) / sizeof(names[0]);
    sortStrArr(size,30,names);

    for (int i = 0; i < 5; i ++) { 
        printf("%s ",names[i]);
    }
    printf("\n");
    char target[] = "CHARLIE";
    stringSearch(size,30,names,target);

    char sentence[] = "the cat sat on the mat the cat";
    uniqueCount(sentence);
    
    char *strarr[] = {"hello","world","foo"};
    
    char *result = join(strarr, 3, '-');
    printf("%s\n",result);
    free(result); // Free the memory after printing
    return 0;
}

char *join(char **words, int n, char sep) { // Returns a string (a pointer to the first character of the string)
    int total_length = n;
    for (int i = 0; i < n; i ++) {
        total_length += strlen(words[i]);
    }

    char *strarr = malloc(total_length); // Allocate 1 * total length bytes (since char = 1 byte in C)
    
    if (strarr == NULL) {
        return NULL;
    }
    strarr[0] = '\0';

    for (int i = 0; i < n; i++) {
        strcat(strarr,words[i]);

        if (i < n-1) { // If its not the last element, add separator
            strncat(strarr,&sep,1);
        }
    }

    return strarr;

}