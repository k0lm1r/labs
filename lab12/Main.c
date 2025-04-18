#include "Queue.h"
#include "Deck.h"
#include "StringAnalysis.h"

int main() {
    char choice;
    queue *item = (queue*)malloc(sizeof(queue));
    item->first = NULL, item->last = NULL;
    do {
        system("cls");
        choice = '\0';
        puts("1 - Work with queue.\n2 - Work with deck.\n3 - String analysis.\n4 - Exit.");
        while (choice < '1' || choice > '4') choice = _getch();
        switch(choice) {
            case '1': printNegativeQueue(item); break;
            case '2': printNegativeDeck(item); break;
            case '3': stringAnalysis(item);
        }
    } while (choice != '4');
}