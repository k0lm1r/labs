#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

void task1() {
    system("cls");
    puts("Enter the matrix size:");
    int n = Try_int(true, true), m = Try_int(true, true), max = 0, m_max = 0, sum = 0;
    int** matrix = int_input(n, m, true);
    bool StrWasFound = false;

    for (int i = 0; i < n && !StrWasFound; i++) {
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j];
            if (matrix[i][j] <= max && matrix[i][j] > m_max)
                m_max = matrix[i][j];
            else if (matrix[i][j] > max)
                m_max = max, max = matrix[i][j];
        }
        StrWasFound = max > sum - max && m_max <= sum - m_max;
        sum = 0, max = 0, m_max = 0;
    }

    if (StrWasFound)
        puts("String was found!");
    else
        puts("String wasn't found.");

    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

void task2() {
    system("cls");
    puts("Enter the matrix size:");
    int n = Try_int(true, true), k = 0;
    fflush(stdin);
    int **matrix = int_input(n, n, false), **result = malloc(n * sizeof(int*));
    bool IsSymmetrical = true;

    for (int i = 0; i < n; i++)
        result[i] = malloc((n - 1) * sizeof(int));
    
    for (int i = 0; i < n && IsSymmetrical; i++)
        for (int j = 0; j < n - 1 - i; j++)
            IsSymmetrical = matrix[i][j] == matrix[n - 1 - i][n - 1 - j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if (IsSymmetrical && j != n - 1 - i || !IsSymmetrical && j != i)
                result[i][k++] = matrix[i][j];
        k = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++)
            printf("%d ", result[i][j]);
        printf("\n");
        free(result[i]), free(matrix[i]);
    }
    free(result), free(matrix);
}

void task3() {
    system("cls");
    puts("Enter the count of strings:");
    int n = Try_int(true, true), limit;
    int *length = malloc(n * sizeof(int));
    int **matrix = malloc(n * sizeof(int*));

    puts("Enter the matrix elements:"), fflush(stdin);
    for (int i = 0; i < n; i++) {
        matrix[i] = NULL;
        int temp = Try_int(true, false), m = 0;
        while (temp != 0) {
            matrix[i] = realloc(matrix[i], ++m * sizeof(int));
            matrix[i][m - 1] = temp;
            temp = Try_int(true, false);
        }
        length[i] = m;
    }

    puts("Enter the limit:"), fflush(stdin);
    limit = Try_int(true, false);

    for (int i = 0; i < n; i++) {
        int TrueRemainder = 0;
        for (int j = 0; j < length[i]; j++) {
            if (matrix[i][j] < limit && j % 2 == TrueRemainder) {
                TrueRemainder = !TrueRemainder;
                for (int k = j; k < length[i] - 1; k++)
                    matrix[i][k] = matrix[i][k + 1];
                matrix[i] = realloc(matrix[i], --length[i] * sizeof(int));
                j--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < length[i]; j++)
            printf("%d ", matrix[i][j]);
        puts(""), free(matrix[i]);
    }
    free(matrix), free(length);
}

int main() {
    srand(time(0));
    char answer = 'y';

    while (answer == 'y' || answer == 'Y') {
        system("cls");
        puts("What task you want to check?");
        int task = Try_int(false, false);

        switch (task) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            default: puts("Task number must be from 1 to 3");
        }

        puts("Do you want to try again?(y/n)");
        answer = Try_answer();
    }
}