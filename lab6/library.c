#include <stdio.h>
#include <stdlib.h>
#include "library.h"

char Try_answer() {
    char answer;
    scanf(" %c", &answer);
    while (answer != 'N' && answer != 'n' && answer != 'Y' && answer != 'y') {
        fflush(stdin), puts("Give a correct answer!");
        scanf(" %c", &answer);
    }
    fflush(stdin);
    return answer;
}

double Try_Digit(bool IsDouble, bool IsLen) {
    double a;
    while(scanf(" %lf", &a) != 1 || a != (int)a && !IsDouble || (a != (int)a || a <= 0 || a > 100) && IsLen)
        if (IsLen)
            puts("The size must be a natural number from 1 to 100:"), fflush(stdin);
        else
            puts("Enter the valid number:"), fflush(stdin);
    return a;
}