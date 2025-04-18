#include "StringAnalysis.h"

int takeDigit(char **pos) {
    int result = 0;
    for (; **pos && **pos >= '0' && **pos <= '9'; ++*pos)
        result = result * 10 + **pos - '0';
    return result;
}

void stringAnalysis(queue *item) {
    system("cls");
    char *string = enterString();

    for (char *str_p = string; *str_p; ++str_p)
        if (*str_p >= '0' && *str_p <= '9') {
            int *digit = (int*)malloc(sizeof(int));
            *digit = takeDigit(&str_p);
            add(item, digit);
        }

    printQueue(item);
    int result = 0;
    for (int *data = (int*)take(item); data; data = (int*)take(item)) result += *data;
    printf("Sum of numbers %d.\nPress any key to return...", result), _getch();
}