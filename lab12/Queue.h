#pragma once
#include "Functions.h"

typedef struct list {
    void *data;
    struct list *next;
    struct list *prev;
} list;

typedef struct queue {
    list *first;
    list *last;
} queue;

void printNegativeQueue(queue *item);
void add(queue *item, void *data);
void *take(queue *item);
int fill(queue *item);
void printQueue(queue *item);