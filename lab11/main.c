#include "workingWithStack.h"
#include "fileCalculator.h"

int main() {
    int choice;
    do {
        system("cls");
        choice = '\0';
        puts("1 - Search elements.\n2 - Marge stacks.\n3 - Solve task in file.\n4 - Exit.");
        while(choice < '1' || choice > '4') choice = _getch();

        switch(choice) {
            case '1': elementsSearch(); break;
            case '2': margeStacks(); break;
            case '3': 
                puts("Enter filename:");
                char filename[20];
                fgets(filename, 20, stdin);
                calculateFile(filename); 
                break;
        }
    } while(choice != '4');
}