#include "functions.h"

int tryInt(bool isPositive) {
    int result = '\0', inputChar = '^';
    bool isNegative = false;
    while (result == '\0' || inputChar != 13 && inputChar != ' ') {
        inputChar = _getch();
        if (inputChar >= '0' && inputChar <= '9')
            result = result * 10 + inputChar - '0';
        else if (inputChar == '-' && !isPositive && !isNegative && result == '\0') 
            isNegative = true, printf("%c", inputChar);
        else if (inputChar == 8) result /= 10, printf("\b \b");
        if (inputChar >= '0' && inputChar <= '9' || inputChar == ' ') {
            printf("%c", inputChar);
        }
    }
    if (inputChar == 13) printf("\n");
    return isNegative ? -result : result;
}

char* fillingString() {
    int size = 5, i;
    char *str = (char*)calloc(sizeof(char), size);

    while (str[0] == 0) {
        rewind(stdin);
        char inputChar = getchar();
        for (i = 0; inputChar != '\n'; ++i) {
            if (i == size) {
                size += 5;
                str = (char*)realloc(str, size * sizeof(char));
            }
            str[i] = inputChar;
            inputChar = getchar();
        }
        if (str[0] == 0) puts("Team name can't start with space!");
    }
    str = (char*)realloc(str, (i + 2) * sizeof(char));
    str[i + 1] = '\0';
    return str;
}

