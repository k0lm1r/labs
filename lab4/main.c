#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

void task1() {
    int a[100][100], res[100][100], characteristics[100];
    int n, m, characteristic = 0, max = -14881337, index_max;

    system("cls");
    puts("Enter the matrix size:");
    n = Try_int(true);
    m = Try_int(true);
    int_input(a, n, m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            characteristic += a[i][j] < 0 && a[i][j] % 2 == 0 ? a[i][j] : 0;
        characteristics[i] = characteristic;
        characteristic = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (characteristics[j] >= max && characteristics[j] <= 0) {
                max = characteristics[j];
                index_max = j;
            }
        }
        characteristics[index_max] = 1;
        max = -14881337;
        for (int j = 0; j < m; j++)
            res[i][j] = a[index_max][j];
    }

    puts("Sorted array:");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%d ", res[i][j]);
        printf("\n");
    }
}

void task2() {
    int n, m;
    double a[100][100];
    bool IsNegative = false;

    system("cls");
    puts("Enter the matrix size:");
    n = Try_int(true);
    m = Try_int(true);
    double_input(a, n, m);

    for (int i = 0; i < n; i++) {
        IsNegative = false;
        for (int j = 0; j < m; j++)
            if (a[i][j] < 0) {
                IsNegative = true;
                break;
            }
    }

    if (!IsNegative)
        printf("Not all strings have negative members.\n");
    else
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                printf("%.2lf ", a[i][j] == 0 ? a[i][j] : -a[i][j]);
            printf("\n");
        }
}

void task3() {
    int n, m;
    double summ = 0, a[100][100];

    system("cls");
    puts("Enter the matrix size:");
    n = Try_int(true);
    m = Try_int(true);
    double_input(a, n, m);

    for (int i = n / 2; i < n; i++)
        for (int j = 0; j < m / 2; j++)
            summ += a[i][j];
    printf("Sum of elements in 3 areas is %.2lf\n", summ);
}

int main() {
    srand(time(0));
    int ans;
    do {
        system("cls");
        fflush(stdin);
        puts("What task you want to test?");
        scanf("%d", &ans);
        fflush(stdin);
        switch(ans) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            default: puts("Task number must be from 1 to 3!"); break;
        }
        puts("Do you want to try again?(y/n)");
        ans = Try_answer();
    }while (ans != 'n' && ans != 'N');
}