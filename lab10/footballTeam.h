typedef struct {
    int victoriesCount;
    char *name;
    struct statistic {
        char lastVictory[4];
        int loseCount;
    };
} footballTeam;