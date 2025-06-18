#include "stack.h"

Stack* push(Stack *last, void *data) {
    Stack *newNode = (Stack*)safeMalloc(sizeof(Stack));
    newNode->data = data;
    newNode->next = last;
    return newNode;
}

void* pop(Stack **last) {
    if (*last) {
        void *data = (*last)->data;
        Stack *newLast = (*last)->next;
        free(*last);
        *last = newLast;
        return data;
    } else return NULL;
}

int fillStack(Stack** stc,  int term) {
    puts("Enter stack length:");
    int n = tryInt(true);

    puts("Enter stack elements:");
    for (int i = 0; i < n; ++i) {
        int *element = (int*)safeMalloc(sizeof(int));
        *element = tryInt(false);
        if ((*stc) == NULL || term == 0 || term < 0 && *element >= *(int*)(*stc)->data || term > 0 && *element <= *(int*)(*stc)->data)
            *stc = push(*stc, element);
        else
            puts("Enter valid element!"), i--;
    }
    return n;
}