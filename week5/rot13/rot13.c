// by Hannah I and Jordan T
// HS1917: Hornsby Tutorial
// Encodes a character using the ROT13 algorithm

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ITERATIONS 13

char encode (char letter);
void testEncode (void);
void tester (char letter, char expected);

int main (int argc, char* argv[]) {
	testEncode();
	char letter = 's';
	printf("%c in to ", letter);
	letter = encode(letter);
	printf("%c\n", letter);
    return EXIT_SUCCESS;
}

char encode (char letter) {
	int i = 0;
	while (i < ITERATIONS) {
		if (letter == 'Z') {
			letter = 'A';
		} else if (letter == 'z'){
			letter = 'a';
		} else {
			letter += 1;
		}
		i++;
	}
	return letter;
}

void testEncode (void) {
	tester('t', 'g');
	tester('h', 'u');
	tester('e', 'r');

	tester('q', 'd');
	tester('u', 'h');
	tester('i', 'v');
	tester('c', 'p');
	tester('k', 'x');

	tester('b', 'o');
	tester('r', 'e');
	tester('o', 'b');
	tester('w', 'j');
	tester('n', 'a');

	tester('f', 's');
	tester('o', 'b');
	tester('x', 'k');

	tester('j', 'w');
	tester('u', 'h');
	tester('m', 'z');
	tester('p', 'c');
	tester('e', 'r');
	tester('d', 'q');

	tester('o', 'b');
	tester('v', 'i');
	tester('e', 'r');
	tester('r', 'e');

	tester('t', 'g');
	tester('h', 'u');
	tester('e', 'r');

	tester('l', 'y');
	tester('a', 'n');
	tester('z', 'm');
	tester('y', 'l');

	tester('d', 'q');
	tester('o', 'b');
	tester('g', 't');

	tester('R', 'E');
	tester('I', 'V');
	tester('C', 'P');
	tester('H', 'U');
	tester('A', 'N');
	tester('R', 'E');
	tester('D', 'Q');

	tester('B', 'O');
	tester('R', 'E');
	tester('E', 'R');
	tester('A', 'N');
	tester('D', 'Q');

	tester('g', 't');
	tester('c', 'p');
	tester('c', 'p');
}

void tester (char letter, char expected) {
	printf("%c in to ", letter);
	letter = encode(letter);
	printf("%c\n", letter);
	assert(letter == expected);
}
