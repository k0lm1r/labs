#include "functions.h"
#include "tasks.h"

int main() {
    char choice = ' ';
    do {
        system("cls");
        puts("Choose testing task: 1 - first and second tasks, 2 - thrid and fourth tasks. For exit enter 3");
        while (choice < '1' || choice > '3') choice = _getch();
        printf("%c\n", choice);

        switch(choice) {
            case '1': task1(); break;
            case '2': task2(); break;
            case '3': return 0;
        }

        puts("Do you want to try again?(y/n)");
        while (choice != 'y' && choice != 'n') choice = _getch();
        printf("%c\n", choice);
    } while(choice != 'n');
}