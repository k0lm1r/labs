#include "functions.h"

int indexOf(char* str, char ch) {
    for (int i = 0; str[i] != '\0'; ++i)
        if (str[i] == ch) return i;
    return 0;
}

void swap(int i, int j, char *filename) {
    int numI, numJ;
    FILE *file = fopen(filename, "r+b");

    if (file != NULL) {
        fseek(file, i * sizeof(int), SEEK_SET);
        fread(&numI, sizeof(int), 1, file);
        fseek(file, j * sizeof(int), SEEK_SET);
        fread(&numJ, sizeof(int), 1, file);
        fseek(file, i * sizeof(int), SEEK_SET);
        fwrite(&numJ, sizeof(int), 1, file);
        fseek(file, j * sizeof(int), SEEK_SET);
        fwrite(&numI, sizeof(int), 1, file);
        fclose(file);
    } else 
        puts("Error! File wasn't open(swaping).");
}

void printFile(char *filename) {
    FILE *file = fopen(filename, "rb");
    for (int input; fread(&input, sizeof(int), 1, file) != 0;)
        printf("%d ", input);
    puts("");
    fclose(file);
}

int fillFileWithDigits(const char *filename) {
    FILE *outputFile = fopen(filename, "wb");
    if (outputFile != NULL) {
        int inputChar, countOfDigits = 0;
        puts("Enter digits:"), fflush(stdin);
        do {
            bool isNegative = false;
            int result = '\0';
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
                countOfDigits += fwrite(&result, sizeof(int), 1, outputFile);
            }
        } while (inputChar != 13);
        puts(""), fclose(outputFile);
        return countOfDigits;
    } else {
        puts("Error! File wasn't open(filling).");
        return -1;
    }
}

void fileSort(FileInfo info) {
    FILE *sortingFile = fopen(info.filename, "rb");

    if (sortingFile != NULL) {
        for (int i = 0; i < info.filesize - 1; ++i) {
            int maxElement, maxIndex = i, element;
            fseek(sortingFile, i * sizeof(int), SEEK_SET);
            fread(&maxElement, sizeof(int), 1, sortingFile);

            for (int j = i + 1; j < info.filesize; ++j) {
                fread(&element, sizeof(int), 1, sortingFile);
                if (element > maxElement)
                    maxElement = element, maxIndex = j;
            }

            fclose(sortingFile);
            swap(maxIndex, i, info.filename);
            sortingFile = fopen(info.filename, "rb");
        }
        fclose(sortingFile);
        puts("Sorted file:");
        printFile(info.filename);
    } else
        puts("Error! File wasn't open(sorting).");
}

void inputFilename(char *filename) {
    puts("Enter the name of output file"), fflush(stdin);
    fgets(filename, 20, stdin);
    filename[indexOf(filename, '\n')] = '\0';
}