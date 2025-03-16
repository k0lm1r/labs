#include "teamsEditor.h"

footballTeam* fillingStructArray(int n) {
    footballTeam *teams = (footballTeam*)malloc(sizeof(footballTeam) * n);
    for (int i = 0; i < n; ++i) {
        puts("Enter count of victories:");
        teams[i].victoriesCount = tryInt(true);
        puts("Enter the teams name:");
        teams[i].name = fillingString();
    }
    return teams;
}

void searchingTeams(footballTeam *teams, int n) {
    system("cls");
    puts("Enter the required count of victories:");
    int requiredCount = tryInt(false);

    puts("Teams:");
    for (int i = 0; i < n; ++i)
        if (teams[i].victoriesCount > requiredCount)
            printf("%s\n", teams[i].name);
    puts("Press any key to return..."), _getch();
}

void destroingTeams(footballTeam *teams, int *n) {
    system("cls");
    int countOfTeams = 0;
    puts("Enter the name for removal:");
    char *nameForRemoval = fillingString();

    for (int i = 0; i < *n; ++i) {
        if (strcmp(teams[i].name, nameForRemoval) == 0) {
            countOfTeams++;
            for (int j = i; j < *n - 1; ++j)
                teams[j] = teams[j + 1];
            (*n)--;
            teams[*n].name = NULL;
            teams[*n].victoriesCount = 0;
        }
    }

    printf("%d teams were removed.\n", countOfTeams);
    puts("Press any key to return..."), _getch();
}

void printTeams(footballTeam *teams, int n) {
    system("cls");
    for (int i = 0; i < n; ++i)
        printf("%d. Team name: %s\n   Count of victories: %d.\n", i + 1, teams[i].name, teams[i].victoriesCount);
    puts("Press any key to return..."), _getch();
}

int printMenu() {
    printf("1. Print teams with a given count of victories.\n2. Remove teams with given name.\n3. Print all teams\n4. Return.\n");
    int choise = 0;
    while (choise < '1' || choise > '5') choise = _getch();
    return choise;
}

void teamsEditor(footballTeam *teams) {
    system("cls");
    int choise = 0, n = 0;
    puts("Enter count of teams:");
    n = tryInt(true);
    teams = fillingStructArray(n);

    do {
        system("cls");
        choise = printMenu();
        switch(choise) {
            case '1': searchingTeams(teams, n); break;
            case '2': destroingTeams(teams, &n); break;
            case '3': printTeams(teams, n); break;
        }
    } while (choise != '4');
}