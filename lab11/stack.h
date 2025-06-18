#include "functions.h"

typedef struct stack {
    void *data;
    struct stack *next;
}Stack;

Stack* push(Stack *lastElem, void *data);
void* pop(Stack **lastElem);
int fillStack(Stack **stc, int term);
