#include "functions.h"

int main() {
    footballTeam *teams;
    int choise;
    do {
        choise = 0;
        printf("1. Check older byte of a digit.\n2. Work with structs.\n3. Exit.\n");
        while (choise < '1' || choise > '3') choise = _getch();
        if (choise == '1') 
            olderByteFinding();
        else if (choise == '2')
            teamsEditor(teams);
    } while (choise != '3');

    free(teams);
}