#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ERROR -1

int printWondrous (int current_term);
int getWondrous (int current_term);
void runPrintWondrousTests (void);
void runGetWondrousTests (void);

int main (int argc, char* argv[]) {
    //int start;
    //printf("Enter starting point: ");
    //scanf("%d", &start);
    //printf("%d had %d terms\n", start, printWondrous (start));

    runGetWondrousTests();
    runPrintWondrousTests();
    return EXIT_SUCCESS;
}

int printWondrous (int current_term) {
    int count = 1;
    while (current_term > 1) {
        printf("%d ", current_term);
        count++;
        current_term = getWondrous(current_term);
    }
    printf("%d\n", current_term);
    return count;
}

int getWondrous (int current_term) {
    if (current_term <= 1) {
        current_term = ERROR;
    } else if (current_term % 2 == 0) {
        current_term /= 2;
    } else {
        current_term = (current_term * 3) + 1;
    }
    return current_term;
}

void runPrintWondrousTests (void) {
    printf(" = = = R U N N I N G  P R I N T  T E S T S = = =\n");
    assert(printWondrous(2) == 2);
    assert(printWondrous(4) == 3);
    assert(printWondrous(8) == 4);
    assert(printWondrous(16) == 5);
    assert(printWondrous(5) == 6);
    assert(printWondrous(10) == 7);
    assert(printWondrous(3) == 8);
    printf(" = = =F I N I S H E D  P R I N T  T E S T S= = =\n");
}

void runGetWondrousTests (void) {
    assert(getWondrous(2) == 1);
    assert(getWondrous(3) == 10);
    assert(getWondrous(10) == 5);
    assert(getWondrous(5) == 16);
    assert(getWondrous(8) == 4);
    assert(getWondrous(2) == 1);
    assert(getWondrous(1) == ERROR);
    assert(getWondrous(0) == ERROR);
    assert(getWondrous(-51983) == ERROR);
}