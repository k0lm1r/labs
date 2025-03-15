#include "functions.h"

int tryInt(bool isPositive) {
    int result = '\0', inputChar = '^';
    bool isNegative = false;
    while (result == '\0' || inputChar != 13) {
        inputChar = _getch();
        if (inputChar >= '0' && inputChar <= '9')
            result = result * 10 + inputChar - '0';
        else if (inputChar == '-' && !isPositive && result == '\0') 
            isNegative = true;
        if (inputChar >= '0' && inputChar <= '9' || inputChar == ' ' || inputChar == '-' && !isPositive) {
            printf("%c", inputChar);
        }
    }
    printf("\n");
    return isNegative ? -result : result;
}

void olderByteFinding() {
    puts("Enter digit:");
    unsigned a = tryInt(false);
    printf("Older byte contains: %lld\n", a >> 24);
}

char* fillingString() {
    int size = 5, i;
    char *str = (char*)calloc(sizeof(char), size);

    while (str[0] == 0) {
        rewind(stdin);
        char inputChar = getchar();
        for (i = 0; inputChar != '\n'; ++i) {
            if (i == size) {
                size += 5;
                str = (char*)realloc(str, size * sizeof(char));
            }
            str[i] = inputChar;
            inputChar = getchar();
        }
        if (str[0] == 0) puts("Team name can't start with space!");
    }
    str = (char*)realloc(str, (i + 2) * sizeof(char));
    str[i + 1] = '\0';
    return str;
}

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
    puts("Enter the required count of victories:");
    int requiredCount = tryInt(false);

    puts("Teams:");
    for (int i = 0; i < n; ++i)
        if (teams[i].victoriesCount > requiredCount)
            printf("%s\n", teams[i].name);
    puts("Press any key to continue..."), _getch();
}

void destroingTeams(footballTeam *teams, int *n) {
    int countOfTeams = 0;
    puts("Enter the name for removal:");
    char *nameForRemoval = fillingString();

    for (int i = 0; i < *n; ++i) {
        if (strcmp(teams[i].name, nameForRemoval) == 0) {
            countOfTeams++;
            for (int j = i; j < *n - 1; ++j)
                teams[j] = teams[j + 1];
            teams = (footballTeam*)realloc(teams, --(*n) * sizeof(footballTeam));
        }
    }

    printf("%d teams were removed.\n", countOfTeams);
    puts("Press any key to continue..."), _getch();
}

void printTeams(footballTeam *teams, int n) {
    for (int i = 0; i < n; ++i)
        printf("%d. Team name: %s\n   Count of victories: %d.\n", i + 1, teams[i].name, teams[i].victoriesCount);
    puts("Press any key to continue..."), _getch();
}

int printMenu() {
    printf("1. Print teams with a given count of victories.\n2. Remove teams with given name.\n3. Print all teams\n4. Exit.\n");
    int choise = 0;
    while (choise < '1' || choise > '5') choise = _getch();
    return choise;
}

void teamsEditor(footballTeam *teams) {
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