#include "functions.h"

void reverseWord(char* filename, int pos, int length) {
    FILE *file = fopen(filename, "r+");
    for (int i = 0; i < length / 2; i++) {
        char chB, chE;
        fseek(file, pos + i, SEEK_SET);
        fscanf(file, "%c", &chB);
        fseek(file, pos + length - i - 1, SEEK_SET);
        fscanf(file, "%c", &chE);
        fseek(file, pos + i, SEEK_SET);
        fprintf(file, "%c", chE);
        fseek(file, pos + length - i - 1, SEEK_SET);
        fprintf(file, "%c", chB);
    }
    fclose(file);
}

void fillFile(char *filename) {
    FILE *file = fopen(filename, "w");
    puts("Enter words.");
    char ch = getchar();
    while (ch != '\n') {
        fprintf(file, "%c", ch);
        ch = getchar();
    }
    fclose(file);
}

int stringLength(char* str) {
    char *s;
    for (s = str; *s; s++);
    return s - str;
}

char* readWord(char* filename, int pos) {
    char* word = NULL, ch = '\0';
    int i = 0;
    FILE *file = fopen(filename, "r");
    fseek(file, pos, SEEK_SET);

    while (fread(&ch, sizeof(char), 1, file) != 0 && ch != ' ') {
        word = (char*)realloc(word, (i + 2) * sizeof(char));
        word[i++] = ch;
    }

    if (word != NULL) word[i] = '\0';
    fclose(file);

    return word;
}

void printFile(char *filename) {
    int pos = 0;
    char *word = readWord(filename, 0);
    while (word != NULL) {
        pos += stringLength(word) + 1;
        printf("%s ", word);
        word = readWord(filename, pos);
    }
    puts("");
}
/*int tryInt() {
    int result, inputChar;
    do {
        bool isNegative = false;
        result = '\0';
        inputChar = '$';

        while (inputChar != ' ' && inputChar != 13) {
            inputChar = _getch();
            if (inputChar >= '0' && inputChar <= '9') {
                result = result * 10 + inputChar - '0';
            } else if (result == 0 && inputChar == '-')
                isNegative = true;
            if (inputChar == ' ' || inputChar >= '0' && inputChar <= '9')
                printf("%c", inputChar);
        }
        if (result != '\0') {
            result = isNegative ? -result : result;
        }
    } while (inputChar != 13 || result == '\0');
    puts("");
} */