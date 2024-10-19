#include <stdio.h>
#include <stdlib.h>
#include "library.h"

char Try_Answer() {
    char answer;
    fflush(stdin), scanf(" %c", &answer);
    while (answer != 'N' && answer != 'n' && answer != 'Y' && answer != 'y') {
        fflush(stdin), puts("Give a correct answer!");
        scanf(" %c", &answer);
    }
    fflush(stdin);
    return answer;
}

double Try_Digit(bool IsDouble, bool IsLen) {
    double a;
    fflush(stdin);
    while (scanf(" %lf", &a) != 1 || a != (int) a && !IsDouble || (a != (int) a || a <= 0 || a > 100) && IsLen)
        if (IsLen)
            puts("The size must be a natural number from 1 to 100:"), fflush(stdin);
        else
            puts("Enter the valid number:"), fflush(stdin);
    return a;
}

int *String(int n, char **string) {
    puts("Do you want to feel string with random words?(y/n)"), fflush(stdin);
    char ans = Try_Answer();
    int *length = (int *) malloc(n * sizeof(int));

    if (ans == 'N' || ans == 'n') {
        puts("Enter the string:"), fflush(stdin);
        for (int i = 0; i < n; ++i) {
            int temp = getchar(), m = 1;
            string[i] = NULL;
            while (temp != ' ' && temp != '\n') {
                string[i] = realloc(string[i], ++m * sizeof(char));
                string[i][m - 2] = (char) temp, temp = getchar();
            }
            length[i] = m, string[i][m - 1] = '\0';
        }
    } else {
        for (int i = 0; i < n; ++i) {
            int m = rand() / 5000 + 2;
            string[i] = NULL, length[i] = m;
            string[i] = realloc(string[i], m * sizeof(char));
            for (int j = 0; j < m - 1; ++j)
                string[i][j] = (char) ((int) (rand() / (double) RAND_MAX * 10) + 65);
            string[i][m - 1] = '\0', printf("%s ", string[i]);
        }
        puts("");
    }

    return length;
}

bool Compare(char *word1, char *word2, int length) {
    for (int i = 0; i < length; ++i)
        if (word1[i] != word2[i])
            return false;
    return true;
}

void QuickSort(int *arr, int left, int right) {
    if (left < right) {
        int i = left, j = right, lim = arr[(right + left) / 2] / 100;
        while (i < j) {
            while (arr[i] / 100 < lim && i < j) i++;
            while (arr[j] / 100 > lim && j > i) j--;
            int temp = arr[i];
            arr[i] = arr[j], arr[j] = temp;
            i++, j--;
        }
        QuickSort(arr, left, j), QuickSort(arr, i, right);
    }
}

void MOSSAD() {
    char star[100][20] = {{"        *"}, {"      * * *"}, {"* * * * * * * * *"}, {" * * * * * * * *"}, {"  * * * * * * *"},{"  * * * * * * *"}, {" * * * * * * * *"}, {"* * * * * * * * *"}, {"      * * *"}, {"        *"}};
    puts("SPECK FOR MOSSAD LOADING...");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++)
            printf("%c", star[i][j]);
        puts(""), _sleep(150);
    }
    system("cls");
}
