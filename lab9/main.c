#include "functions.h"

void task(char *filename) {
    int length, pos = 0;
    fillFile(filename);
    printFile(filename);

    puts("Enter the lenght.");
    scanf("%d", &length);
    puts("Words that have entered length.");

    char *word = readWord(filename, 0);
    while (word != NULL) {
        int wordLength = stringLength(word);
        if (wordLength == length)
            printf("%s ", word);
        else if (wordLength > length)
            reverseWord(filename, pos, wordLength);
            
        pos += wordLength + 1;
        word = readWord(filename, pos);
    }
    puts("");
    printFile(filename);
}

int main(int argc, char **argv) {
    system("cls");
    if (argc > 1)
        task(argv[1]);        
    else 
        puts("Filename should be entering like argument");
}