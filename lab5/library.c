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

int Try_int(bool IsNatural, bool IsLen) {
    double a;
    while(scanf(" %lf", &a) != 1 || a != (int)a || a < 0  && IsNatural || (a <= 0 || a > 100) && IsLen)
        puts("Enter the valid number:"), fflush(stdin);
    return (int)a;
}

void** int_input(int n, int m, bool IsNatural) {
    int **a = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        a[i] = malloc(m * sizeof(int));

    puts("Do you want to fill the matrix with random numbers?(y/n)");
    char ans = Try_answer();

    if (ans == 'n' || ans == 'N') {
        puts("Enter the matrix elements:"), fflush(stdin);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = Try_int(IsNatural, false);
    } else {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = rand();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                printf("%d ", a[i][j]);
            puts("");
        }
        puts(""), fflush(stdin);
    }
    return a;
}
