#include "teamsEditor.h"
#include "olderByteSearch.h"

int main() {
    footballTeam *teams = NULL;
    int choise;
    do {
        system("cls");
        choise = 0;
        printf("1. Check older byte of a digit.\n2. Work with structs.\n3. Exit.\n");
        while (choise < '1' || choise > '3') choise = _getch();
        if (choise == '1') 
            olderByteSearch();
        else if (choise == '2') {
            teamsEditor(teams);
            free(teams);
        }
    } while (choise != '3');
}