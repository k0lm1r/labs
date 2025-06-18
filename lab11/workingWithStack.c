#include "workingWithStack.h"

void elementsSearch() {
    Stack *first = NULL, *second = NULL;
    fillStack(&first, 0);
    fillStack(&second, 0);

    puts("Elements second stacks that are found in first more 2 times:");
    while (second) {
        int count = 0, secondElement = *(int*)pop(&second);
        for (Stack* firstElement = first; firstElement; firstElement = firstElement->next)
            if (*(int*)firstElement->data == secondElement) count++;
        if (count > 2) printf("%d ", secondElement);
    }
    puts("\nPress any key to return..."), getch();
}

void margeStacks() {
    Stack *descending = NULL, *ascending = NULL, *newStack = NULL, *descendingElements = NULL;
    fillStack(&descending, -1);
    fillStack(&ascending, 1);
    
    while (ascending) {
        Stack *element = descending;
        for (; element && *(int*)element->data > *(int*)ascending->data; element = element->next);
        for (; element && (newStack == NULL || *(int*)element->data > *(int*)newStack->data); element = element->next) descendingElements = push(descendingElements, element->data);
        if (descendingElements)
           while (descendingElements) newStack = push(newStack, pop(&descendingElements));
        newStack = push(newStack, pop(&ascending));
    }

    while (*(int*)descending->data > *(int*)newStack->data) descendingElements = push(descendingElements, pop(&descending));
    while(descendingElements) newStack = push(newStack, pop(&descendingElements));

    puts("New stack:");
    while(newStack) printf("%d ", *(int*)pop(&newStack));
    puts("\nPress any key to return..."), getch();
}