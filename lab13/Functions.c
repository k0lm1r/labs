#include "Functions.h"

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