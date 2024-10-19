#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

void task1() {
    system("cls");
    puts("Enter the array size:"), fflush(stdin);
    int n = (int)Try_Digit(false, true);
    int *arr = (int*)malloc(n * sizeof(int));

    puts("Do you want to fill array with random numbers?(y/n)"), fflush(stdin);
    char answer = Try_answer();
    if (answer == 'n' || answer == 'N') {
        puts("Enter the array elements:");
        for (int i = 0; i < n; ++i)
            arr[i] = (int)Try_Digit(false, false);
    }
    else {
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() / 1000;
            printf("%d ", arr[i]);
        }
        puts("");
    }

    int max_index = 0, max = arr[0];
    for (int i = 1; i < n; ++i)
        if (arr[i] > max)
            max = arr[i], max_index = i;

    int min_index = 0, min = INT_MAX;
    for (int i = max_index + 1; i < n; ++i) {
        if (arr[i] % 2 == 0) {
            for (int j = i + 1; j < n; ++j)
                if (arr[j] < min && arr[j] % 2 == 0)
                    min = arr[j], min_index = j;
            int temp = arr[i];
            arr[i] = arr[min_index], arr[min_index] = temp;
            min = INT_MAX;
        }
    }

    puts("The sorted array:");
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    puts(""), fflush(stdin);
    free(arr);
}

void task2() {
    system("cls");
    puts("Enter the array size:"), fflush(stdin);
    int n = (int)Try_Digit(false, true), m = (int)Try_Digit(false, true);

    double **arr = (int**)malloc(n * sizeof(double*)), *sum = (double*)calloc(n, sizeof(double));
    for (int i = 0; i < n; ++i)
        arr[i] = (double*)malloc(m * sizeof(double));

    puts("Do you want to fill array with random numbers?(y/n)"), fflush(stdin);
    char answer = Try_answer();
    if (answer == 'n' || answer == 'N') {
        puts("Enter the array elements:");
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                arr[i][j] = Try_Digit(true, false);
    }
    else {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                arr[i][j] = rand() / 1000.0;
                printf("%.2lf ", arr[i][j]);
            }
            puts("");
        }
        puts("");
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            sum[i] += arr[i][j];
        printf("%.2lf ", sum[i]);
    }

    for (int d = n / 2; d > 0; d /= 2) {
        for (int i = d; i < n; ++i) {
            for (int j = i - d; j >= 0 && sum[j] > sum[j + d]; j -= d) {
                double *temp_arr = arr[j];
                arr[j] = arr[j + d], arr[j + d] = temp_arr;
                double temp_sum = sum[j];
                sum[j] = sum[j + d], sum[j + d] = temp_sum;
            }
        }
    }

    puts("\n\nSorted array:");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            printf("%.2lf ", arr[i][j]);
        free(arr[i]), puts("");
    }
    free(arr), free(sum);
}

int main() {
    srand(time(0));
    char answer;
    do {
        system("cls");
        puts("What task you want to test?"), fflush(stdin);
        int task_number = (int)Try_Digit(false, false);

        switch (task_number) {
            case 1: task1(); break;
            case 2: task2(); break;
            default: puts("Task number isn't correct."), fflush(stdin);
        }

        puts("Do you want to try again?(y/n)"), fflush(stdin);
        answer = Try_answer();
    }while (answer != 'N' && answer != 'n');
}