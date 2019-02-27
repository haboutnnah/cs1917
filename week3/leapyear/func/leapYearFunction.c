// By Hannah Ivy
// By Jordan Terzian
// Checks if a given year is a leap year.
// == TEST CASES ==
// 1581 => Dies
// 1999 => False
// 2000 => True
// 2016 => True
// 1900 => False
// 1582 => False
// 2018 => False

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define START_OF_GREGORIAN_CALENDAR 1582

int isLeapYear (int year); 

int main ( int argc, char * argv[]) {
    // Set some space for the year
    int year = 0;

    // Ask the user for input
    printf("please enter the year you are interested in \n");
    // Store the year that the user gives us
    // The '&' is used because this is a pointer
    scanf("%d", &year);
    assert (year >= START_OF_GREGORIAN_CALENDAR);
    
    if (isLeapYear(year)) {
        printf("%d is leap year!\n", year); 
    } else {
        printf("%d is not a leap year\n", year);
    }

    // We didn't fail.
    return EXIT_SUCCESS;
}

int isLeapYear (int year) {
	int leapYearStatus = 0;
	// is divisible by 4
	if (year % 4 == 0){
		printf("divisible by 4\n");
		// is divisible by 100
		if (year % 100 == 0){
			printf("divisible by 100\n");
			// is divisible 400
			if (year % 400 == 0){
				printf("divisible by 400\n");
				leapYearStatus = 1;
			} else {
				leapYearStatus = 0;
			}
		} else {
			leapYearStatus = 1;
		}
	} else {
		leapYearStatus = 0;
	}
	// Returns the status
	return leapYearStatus;
}
