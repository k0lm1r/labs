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

void* safeMalloc(size_t size) {
    void *newPointer = malloc(size);
    if (newPointer) return newPointer;
    else {
        perror("Malloc error");
        exit(0xAB6566);
    }
}

bool contains(char* string, char symbol) {
    for (char *s = string; *s; ++s)
        if (*s == symbol) return true;
    return false;
}

int getDigit(double *digit, char *filename, int position) {
    FILE *file = fopen(filename, "r+");
    int doublePartPower = 1;
    char inputChar;
    bool isDoublePart = false;

    fseek(file, position, SEEK_SET);
    while (fscanf(file, "%c", &inputChar) != EOF && (inputChar >= '0' && inputChar <= '9' || inputChar == '.')) {
        if (inputChar != '.')
            *digit = isDoublePart ? *digit + (inputChar - '0') * pow(10, -doublePartPower++) : *digit * 10 + inputChar - '0';
        else
            isDoublePart = true;
    }

    int pos = inputChar >= '0' && inputChar <= '9' ? ftell(file) : ftell(file) - 1;
    fclose(file);
    return pos;
}

char* findChar(char* str, char ch) {
    for (; *str; str++) if (*str == ch) return str;
    return NULL;
}