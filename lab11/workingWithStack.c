#include "workingWithStack.h"

void elementsSearch() {
    stack *first = NULL, *second = NULL;
    fillStack(&first, 0);
    fillStack(&second, 0);

    puts("Elements second stacks that are found in first more 2 times:");
    while (second) {
        int count = 0, secondElement = pop(&second);
        for (stack* firstElement = first; firstElement; firstElement = firstElement->prev)
            if (firstElement->data == secondElement) count++;
        if (count > 2) printf("%d ", secondElement);
    }
    puts("\nPress any key to return..."), _getch();
}

void margeStacks() {
    stack *descending = NULL, *ascending = NULL, *newStack = NULL, *descendingElements = NULL;
    fillStack(&descending, -1);
    fillStack(&ascending, 1);
    
    while (ascending) {
        stack *element = descending;
        for (; element && element->data > ascending->data; element = element->prev);
        for (; element && (newStack == NULL || element->data > newStack->data); element = element->prev) push(&descendingElements, element->data);
        if (descendingElements)
           while (descendingElements) push(&newStack, pop(&descendingElements));
        push(&newStack, pop(&ascending));
    }

    while (descending->data > newStack->data) push(&descendingElements, pop(&descending));
    while(descendingElements) push(&newStack, pop(&descendingElements));

    puts("New stack:");
    while(newStack) printf("%d ", pop(&newStack));
    puts("\nPress any key to return..."), _getch();
}