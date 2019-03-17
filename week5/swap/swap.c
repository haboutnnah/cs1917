// by Hannah I and Jordan T
// HS1917: Hornsby Tutorial
// Sorts three numbers

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap (int* first, int* second);
void testSwap (void); 
void tester (int f, int s);

int main (int argc, char* argv[]) {
	testSwap();
	int first, second;
	first = 5;
	second = 6;
	printf("%d %d \n", first, second);
	swap(&first, &second);
	printf("%d %d \n", first, second);
    return EXIT_SUCCESS;
}

void swap (int* first, int* second) {
	int swap;
	swap   = *first;
	*first  = *second;
	*second = swap;
}

void testSwap (void) {
	tester(5, 6);
	tester(2, 3);
	tester(19239, 12388);
	tester(1238, 2654);
	tester(1738, 420);
	tester(-121328, 137);
	tester(273981723, 182739);
	tester('A', 'd');
}

void tester (int f, int s) {
	int first = f;
	int second = s;
	printf("%d %d \n", first, second);
	swap(&first, &second);
	printf("%d %d \n", first, second);
	assert (first == s);
	assert (second == f);
}
