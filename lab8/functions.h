#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>
#include "FileInfo.h"

int fillFileWithDigits(const char*);
void fileSort(FileInfo);
void inputFilename(char*);
int indexOf(char*, char);

#endif