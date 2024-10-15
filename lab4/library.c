#include <stdio.h>
#include <stdlib.h>
#include "library.h"

char Try_answer() {
    char answer;
    scanf(" %c", &answer);
    while (answer != 'N' && answer != 'n' && answer != 'Y' && answer != 'y') {
        fflush(stdin);
        puts("Give a correct answer!");
        scanf(" %c", &answer);
    }
    fflush(stdin);
    return answer;
}

int Try_int(bool IsLen) {
    double a;
    while(scanf(" %lf", &a) != 1 || a != (int)a || (a <= 0 || a > 100) && IsLen) {
        puts("Enter the valid number:");
        fflush(stdin);
    }
    return (int)a;
}

double Try_double() {
    double a;
    while(scanf(" %lf", &a) != 1) {
        printf("Enter the valid number:");
        fflush(stdin);
    }
    return a;
}

void int_input(int a[][100], int n, int m) {
    char ans;
    fflush(stdin);
    puts("Fill array with random numbers?(y/n)");
    ans = Try_answer();
    if (ans == 'n' || ans == 'N') {
        puts("Enter the array elements:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = Try_int(false);
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = rand();
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}

void double_input(double a[][100], int n, int m) {
    char ans;
    fflush(stdin);
    puts("Fill array with random numbers?(y/n)");
    ans = Try_answer();
    if (ans == 'n' || ans == 'N') {
        puts("Enter the array elements:");
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = Try_double();
    }
    else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = rand() / (double)RAND_MAX * 100;
                printf("%.2lf ", a[i][j]);
            }
            printf("\n");
        }
    }
    printf("\n");
}