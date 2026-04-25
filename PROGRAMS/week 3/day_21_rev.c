#include <stdio.h>
#include <string.h>

void stringTokeniser(char *string, char *delimiter) {
    char stringcopy[strlen(string) + 1];
    strcpy(stringcopy,string);
    char *token = strtok(stringcopy, delimiter);
    int t = 1;
    while (token != NULL) {
        printf("Token %d: %s\n", t, token);
        token = strtok(NULL, delimiter);
        t++;
    }
}

void slideWinMax(int *arr, int n, int k) {
    for (int i = 0 ; i < n - k + 1; i ++) {
        int max = arr[i];
        printf("Window [");
        for (int j = i; j < i+k; j ++) {
            if (arr[j] > max) {
                max = arr[j];
            }
            printf("%d ", arr[j]);
        }
        printf("] max %d", max);
        printf("\n");
    }
}

void pairSumTarget(int *arr, int n,int target) {
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {

            int sumPair = arr[i] + arr[j];

            if (sumPair == target) {
                printf("(%d, %d)\n", arr[i], arr[j]);
            }

        }
        }
    }

int main() {
    char str[] = "apple|strawberry|banana";
    stringTokeniser(str, "|");

    printf("%s\n",str); 
    printf("\n");

    int arr[10] = {10,9,2,7,6,5,4,3,2,1};
    slideWinMax(arr,10,3);

    int arrpair[2] = {3,4};
    pairSumTarget(arrpair, 2, 7);
    return 0;
}