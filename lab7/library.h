#ifndef LIBRARY_H
#define LIBRARY_H
#include <stdio.h>
#include <stdlib.h>

char Try_Answer();
double Try_Digit(const bool IsDouble, const bool IsLen);
int* String(const int n, char** string);
bool Compare(const char* word1, const char* word2, const int length);
void QuickSort(int *arr, const int left, const int right);

#endif //LIBRARY_H
