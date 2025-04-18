#include "Deck.h"

void addFront(queue *item, void *data) {
    if (item->first) {
        list *newNode = (list*)calloc(1, sizeof(list));
        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = item->first;
        item->first->prev = newNode;
        item->first = newNode;
    } else {
        item->first = (list*)realloc(item->last, sizeof(list));
        item->first->data = data;
        item->first->prev = NULL;
        item->first->next = NULL;
    }
    if (!item->last) item->last = item->first;
}

void *takeBack(queue *item) {
    if (item->last) {
        void *data = item->last->data;
        list *temp = item->last;
        item->last = item->last->prev;
        free(temp);
        return data;
    }
    return NULL;
}

void printNegativeDeck(queue *item) {
    system("cls");
    fill(item);
    int *data = (int*)takeBack(item);
    puts("First and second right negative elements:");
    for (int i = 0; i < 2 && data; data = (int*)takeBack(item))
        if (*data < 0) 
            printf("%d ", *data), i++;
    puts("\nPress any key to return..."), _getch();
}