#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int tryInt(bool isPositive);
void* safeMalloc(size_t size);
bool contains(char* string, char symbol);
int getDigit(double *digit, char *filename, int position);
char* findChar(char *str, char ch);