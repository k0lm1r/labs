#include "olderByteSearch.h"

void olderByteSearch() {
    system("cls");
    puts("Enter digit:");
    unsigned a = tryInt(false);
    printf("Older byte contains: %lld\n", a >> 24);
    puts("Press any key to return..."), _getch();
}