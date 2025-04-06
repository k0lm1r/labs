#include "functions.h"

typedef struct stack {
    int data;
    struct stack* prev;
} stack;

typedef struct stackDouble {
    double data;
    struct stackDouble *prev;
} stackDouble;

typedef struct stackChar {
    char data;
    struct stackChar *prev;
} stackChar;

void push(stack** lastElem, int newData);
int pop(stack** lastElem);
int fillStack(stack** stc, int term);
void pushDouble(stackDouble **lastElem, double newData);
double popDouble(stackDouble **lastElem);
void pushChar(stackChar **lastElem, char newData);
char popChar(stackChar **lastElem);