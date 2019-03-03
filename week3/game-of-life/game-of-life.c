// By Hannah Ivy
// The starting point for a program that validates inputs
// for Conway's game of life
// Tests:
// 1 1 => DEAD
// 1 2 => ALIVE
// 0 0 => DEAD

#include <stdio.h>
#include <stdlib.h>

#define DEAD 0
#define ALIVE 1

int cellLifeCheck(int curCell, int cellsAround);

int main (int argc, char *argv[]) {
    int curCell     = 0;
    int cellsAround = 0;
    scanf("%d %d", &curCell, &cellsAround);
    int cellAfterProcessing = cellLifeCheck(curCell, cellsAround);
    if (cellAfterProcessing == DEAD) {
        printf("DEAD\n");
    }
    else {
        printf("ALIVE\n");
    }
    return EXIT_SUCCESS;
}

int cellLifeCheck(int curCell, int cellsAround) {
    if (curCell == ALIVE) {
        if (!(cellsAround == 2 || cellsAround == 3)) {
            curCell = DEAD;
        }
    }
    else {
        if (cellsAround == 3) {
            curCell = ALIVE;
        }
    }
    return curCell;
}
