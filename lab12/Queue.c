#include "Queue.h"

void add(queue *item, void *data) {
    if (item->last) {
        list *newNode = (list*)calloc(1, sizeof(list));
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = item->last;
        item->last->next = newNode;
        item->last = newNode;
    } else {
        item->last = (list*)realloc(item->last, sizeof(list));
        item->last->data = data;
        item->last->next = NULL;
        item->last->prev = NULL;
    }
    if (!item->first) item->first = item->last;
}

void* take(queue *item) {
    if (item->first) {
        void *data = item->first->data;
        list *temp = item->first;
        item->first = item->first->next;
        free(temp);
        return data;
    }
    return NULL;
}

int fill(queue *item) {
    puts("Enter count of elements:");
    int n = tryInt(true);

    puts("Enter elements:");
    for (int i = 0; i < n; ++i) {
        int *element = (int*)malloc(sizeof(int));
        *element = tryInt(false);
        add(item, element);
    }
    return n;
}

void printQueue(queue *item) {
    puts("Elements of queue:");
    for (list *element = item->first; element; element = element->next) printf("%d ", *(int*)element->data);
    puts("");
}

void printNegativeQueue(queue *item) {
    system("cls");
    fill(item);
    int *data = (int*)take(item);
    puts("First and second negative elements:");
    for (int i = 0; data && i < 2; data = (int*)take(item))
        if (*data < 0)
            printf("%d ", *data), i++;
    puts("\nPress any key to return..."), _getch();
}