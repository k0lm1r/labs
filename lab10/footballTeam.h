typedef struct statistic {
    char lastVictory[4];
    int loseCount;
} statistic;

typedef struct footballTeam {
    int victoriesCount;
    char *name;
    statistic stats;
} footballTeam;