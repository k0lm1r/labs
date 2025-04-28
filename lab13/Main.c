#include "BinaryTree.h"

int main() {
    binaryTree *item = NULL;
    char choice;
    createTree(&item);
    do {
        system("cls");
        choice = '\0';
        puts("1 - Delete node.\n2 - Print last level with positive elements.\n3 - Print tree.\n4 - Exit.");
        while (choice < '1' || choice > '4') choice = _getch();
        switch(choice) {
            case '1':
                system("cls");
                puts("Enter deleted digit:");
                int data = tryInt(false);
                deleteElement(&item, data); 
                break;
            case '2': 
                system("cls");
                printf("Last level with positive elements: %d\nPress any key to return...", findLastPositive(item, 0, 0)), _getch();
                break;
            case '3':
                system("cls");
                treeVisualisation(item, 0);
                puts("\nPress any key to return..."), _getch();
        }
    } while (choice != '4');
}