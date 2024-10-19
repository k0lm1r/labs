#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "library.h"

int main() {
    char **name = (char **)malloc(10 * sizeof(char *));
    for (int i = 0; i < 10; i++) {
        name[i] = (char *)malloc(10 * sizeof(char));
        for (int j = 0; j < 10; j++)
            name[i][j] = (char)(i + 1);
    }
    printf("%p ", name);
}