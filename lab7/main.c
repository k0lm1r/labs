#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

void task1() {
    system("cls");
    puts("Enter the string length:");
    int n = (int)Try_Digit(false, true);
    char **string = (char**)malloc(n * sizeof(char*));
    int *length = String(n, string);

    int max = length[0], index = 0;
    for (int i = 0; i < n; ++i)
        if (length[i] > max)
            max = length[i], index = i;

    printf("The longest word is %s.\n", string[index]);
    for (int i = 0; i < n; ++i)
        free(string[i]);
    free(string), free(length);
}

void task2() {
    system("cls");
    puts("Enter the first string length:");
    int n1 = (int)Try_Digit(false, true);
    char **string1 = (char**)malloc(n1 * sizeof(char*));
    int *len1 = String(n1, string1);

    puts("Enter the second string length:");
    int n2 = (int)Try_Digit(false, true);
    char **string2 = (char**)malloc(n2 * sizeof(char*));
    int *len2 = String(n2, string2);

    int index = -1;
    for (int i = 0; i < n1; ++i)
        if (len1[i] == len2[0] && Compare(string1[i], string2[0], len1[i])) {
            index = i;
            break;
        }

    if (index != -1) {
        for (int i = index; i < n1 - 1; ++i) {
            char *temp = string1[i];
            int temp_len = len1[i];
            string1[i] = string1[i + 1], string1[i + 1] = temp;
            len1[i] = len1[i + 1], len1[i + 1] = temp_len;
        }
        string1 = (char**)realloc(string1, --n1 * sizeof(char*));

        for (int i = 0; i < n1; ++i) {
            printf("%s ", string1[i]), free(string1[i]);
        }
        puts("");
    }else
        puts("First word from second string wasn't found in first one.");

    for (int i = 0; i < n2; ++i)
        free(string2[i]);
    free(string1), free(string2), free(len1), free(len2);
}

void task3() {
    system("cls");
    puts("Enter the array length:");
    int arr_len = (int)Try_Digit(false, true);
    puts("Enter the string length:");
    int str_len = (int)Try_Digit(false, true), *words_len = (int*)malloc(arr_len * sizeof(int));
    char ***string = (char***)malloc(arr_len * sizeof(char**));

    for (int i = 0; i < arr_len; ++i) {
        int *temp = (int*)malloc(str_len * sizeof(int));
        string[i] = (char**)malloc(str_len * sizeof(char*));
        temp = String(str_len, string[i]);

        int min = temp[0];
        for (int j = 0; j < str_len; ++j)
            if (temp[j] < min)
                min = temp[j];
        words_len[i] = min * 100 + i;
    }

    QuickSort(words_len, 0, arr_len - 1);
    for (int i = 0; i < arr_len; ++i) {
        for (int j = 0; j < str_len; ++j)
            printf("%s ", string[words_len[i] % 100][j]);
        puts("");
    }
    for (int i = 0; i < arr_len; ++i) {
        for (int j = 0; j < str_len; ++j)
            free(string[i][j]);
        free(string[i]);
    }
    free(string), free(words_len);
}

int main() {
    srand(time(0));
    MOSSAD();
    char ans;
    do {
        system("cls");
        puts("What tack you want to test?");
        ans = (char)Try_Digit(false, false);
        switch (ans) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            default: puts("Task number must be from 1 to 3."); break;
        }
        puts("Do you want to try again?(y/n)");
        ans = Try_Answer();
    }while (ans != 'n' && ans != 'Y');
}