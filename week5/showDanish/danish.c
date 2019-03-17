#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void showDanish (void);

int main (int argc, char* argv[]) {
    showDanish();
    printf("Does this look like:\n");
    printf("\n** *********\n** *********\n\n** *********\n** *********\n");
}

void showDanish (void) {
    int i = 1;
    while (i <= 5) {
        if (i != 3) {
            printf("** *********");
        }
        printf("\n");
        i++;
    }
}