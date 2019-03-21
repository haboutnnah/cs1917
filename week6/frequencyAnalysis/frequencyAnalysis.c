#include <stdio.h>
#include <stdlib.h>

//#define SIZE 1024 * 1024
#define NUM_IN_ALPHABET 26 

int main (int argc, char* argv[]) {
	//FILE * fp = fopen("test.txt", "r");
    //char fileArray[SIZE];
    int alphabetFrequency[NUM_IN_ALPHABET];
    int curChar;
    int totalLetters = 0;
    int i = 0;
    while(i < NUM_IN_ALPHABET) {
    	alphabetFrequency[i] = 0;
    	i++;
    }
    i = 0;
    curChar = getchar();
    while(curChar != EOF) {
    	if (curChar <= 'z' && curChar >= 'a'){
    		curChar -= ('a' - 'A');
    	}
    	if (curChar <= 'Z' && curChar >= 'A'){
    		totalLetters++;
    		alphabetFrequency[curChar - 'A']++;
    	}
    	curChar = getchar();
    }
    i = 0;
    printf("Total alphabetical characters counted: %d\n", totalLetters);
    while(i < NUM_IN_ALPHABET - 1)
    {
    	printf("%c: %d, ", i + 'a', alphabetFrequency[i]);
    	i++;
    }
    printf("%c: %d\n", NUM_IN_ALPHABET - 1 + 'a', alphabetFrequency[25]);
    return EXIT_SUCCESS;
}
