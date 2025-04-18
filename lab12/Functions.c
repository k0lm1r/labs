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
        if (inputChar >= '0' && inputChar <= '9' || inputChar == ' ') {
            printf("%c", inputChar);
        }
    }
    if (inputChar == 13) printf("\n");
    return isNegative ? -result : result;
}

char* findChar(char *string, char ch) {
    for (char *s = string; *s; ++s)
        if (*s == ch) return s;
    return NULL;
}

char* enterString() {
    char *string = (char*)malloc(10 * sizeof(char));
    int capacity = 10;
    char inputChar = '\0';

    puts("Enter string:"), rewind(stdin);
    for (int i = 0; inputChar != '\n'; ++i) {
        if (i > capacity) {
            capacity += 10;
            string = (char*)realloc(string, capacity * sizeof(char));
        }
        inputChar = getchar();
        string[i] = inputChar;
    }
    
    *findChar(string, '\n') = '\0';
    return string;
}