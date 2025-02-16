#include "tasks.h"

void task1() {
    char filename[20];
    inputFilename(filename);
    fillFileWithDigits(filename);
    FILE *inputFile = fopen(filename, "rb");

    if (inputFile != NULL) {
        int count = 0, sum = 0, input;
        fread(&sum, sizeof(int), 1, inputFile);
        while (fread(&input, sizeof(int), 1, inputFile) != 0) {
            if (input > sum)
                count++;
            sum += input;
        }
        printf("\nCount of elements that bigger than sum of previous elements is %d\n", count);
        fclose(inputFile);
    } else
        puts("Error! File wasn't open");
}

void task2() {
    FileInfo info1, info2, infoBoth;
    inputFilename(info1.filename), inputFilename(info2.filename);
    info1.filesize = fillFileWithDigits(info1.filename), info2.filesize = fillFileWithDigits(info2.filename);

    fileSort(info1), fileSort(info2);
    inputFilename(infoBoth.filename);
    infoBoth.filesize = info1.filesize + info2.filesize;

    FILE *file1 = fopen(info1.filename, "rb"), *file2 = fopen(info2.filename, "rb"), *fileBoth = fopen(infoBoth.filename, "w+b");
    if (file1 != NULL && file2 != NULL && fileBoth != NULL) {
        int input1, input2;
        fread(&input1, sizeof(int), 1, file1);
        fread(&input2, sizeof(int), 1, file2);
        for(int i = 0, j = 0; i < info1.filesize || j < info2.filesize;) {
            if (i < info1.filesize && (input1 > input2 || j == info2.filesize)) {
                fwrite(&input1, sizeof(int), 1, fileBoth);
                fread(&input1, sizeof(int), 1, file1);
                i++;
            }
            else if (j != info2.filesize) {
                fwrite(&input2, sizeof(int), 1, fileBoth);
                fread(&input2, sizeof(int), 1, file2);
                j++;
            }
        }

        fseek(fileBoth, 0, SEEK_SET);
        for (int i = 0; i < infoBoth.filesize; ++i) {
            int input;
            fread(&input, sizeof(int), 1, fileBoth);
            printf("%d ", input);
        }
        puts("");
    } else 
        puts("Error! File wasn't open.");
}