#include "functions.h"

typedef struct stack {
    int data;
    struct stack* prev;
} Stack;

typedef struct stackD {
    double data;
    struct stackD *prev;
} stackDouble;

typedef struct stackCh {
    char data;
    struct stackCh *prev;
} stackChar;

void push(Stack** lastElem, int newData);
int pop(Stack** lastElem);
int fillStack(Stack** stc, int term);
void pushDouble(stackDouble **lastElem, double newData);
double popDouble(stackDouble **lastElem);
void pushChar(stackChar **lastElem, char newData);
char popChar(stackChar **lastElem);