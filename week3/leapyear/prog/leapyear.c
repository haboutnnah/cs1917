// by Hannah and Jordan for hs1917
// 2019-02-27, Hornsby tutorial
// checks if a given year is a leap year
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define START_OF_GREG_CALENDAR 1582

int main (int argc, char *argv[]) {
	int year = 0; // initialise to 0
	printf("please enter the year you are interested in\n");
	scanf("%d", &year); // read year
	// check if after start after greg calendar
	assert(year >= START_OF_GREG_CALENDAR);
	// if div by 4 then is leap year
	if (year % 4 == 0) {
		//printf("div by 4\n");
		// unless its by 100 as well
		if (year % 100 == 0){
			//printf("div by 100\n");
			// unless its by 400 as well
			if (year % 400 == 0){
				//printf("div by 400\n");
				printf("%d is a leap year\n", year);
			} else {
				printf("%d is not a leap year\n", year);
			}
		} else {
			printf("%d is a leap year\n", year);
		}
	} else {
		printf("%d is not a leap year\n", year);
	}
	return EXIT_SUCCESS;
}