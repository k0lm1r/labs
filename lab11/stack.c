#include "stack.h"

void push(stack **lastElem,  int newData) {
    stack *temp = *lastElem;
    *lastElem = (stack*)malloc(sizeof(stack));
    (*lastElem)->data = newData;
    (*lastElem)->prev = temp;
}

int pop(stack **lastElem) {
    if (*lastElem != NULL) {
        int data = (*lastElem)->data;
        (*lastElem) = (*lastElem)->prev;
        return data;
    }
    return INT_MIN;
}

int fillStack(stack** stc,  int term) {
    puts("Enter stack length:");
    int n = tryInt(true);

    puts("Enter stack elements:");
    for (int i = 0; i < n; ++i) {
        int element = tryInt(false);
        if ((*stc) == NULL || term == 0 || term < 0 && element >= (*stc)->data || term > 0 && element <= (*stc)->data)
            push(stc, element);
        else
            puts("Enter valid element!"), i--;
    }
    return n;
}

void pushDouble(stackDouble **lastElem, double newData) {
    stackDouble *temp = *lastElem;
    *lastElem = (stackDouble*)malloc(sizeof(stackDouble));
    (*lastElem)->data = newData;
    (*lastElem)->prev = temp;
}

double popDouble(stackDouble **lastElem) {
    if (*lastElem != NULL) {
        double data = (*lastElem)->data;
        *lastElem = (*lastElem)->prev;
        return data;
    }
    return INT_MIN;
}

void pushChar(stackChar **lastElem, char newData) {
    stackChar *temp = *lastElem;
    *lastElem = (stackChar*)malloc(sizeof(stackChar));
    (*lastElem)->data = newData;
    (*lastElem)->prev = temp;
}

char popChar(stackChar **lastElem) {
    if (*lastElem != NULL) {
        char data = (*lastElem)->data;
        (*lastElem) = (*lastElem)->prev;
        return data;
    }
    return '\0';
}