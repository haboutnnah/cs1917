// By Hannah Ivy
// Checks if a given year is a leap year.

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#define START_OF_GREGORIAN_CALENDAR 1582

int main ( int argc, char * argv[]) {
    // Set some space for the year
    int year;
    // Set some space aside for the bool value
    // of if it is a leap year or not.
    int is_leap_year;
    // Default to no
    is_leap_year = 0;

    // Ask the user for input
    printf("please enter the year you are interested in \n");

    // Store the year that the user gives us
    // The '&' is used because this is a pointer
    scanf("%d", &year);
    assert (year >= START_OF_GREGORIAN_CALENDAR);
    
    // '%' returns remainder, if == 0, fully divisible by 0
    
    // If the year is divisible by 4, but not if by 100,
    // unless it is also by 400
    if ((year % 4) == 0) {
        is_leap_year = 1;
        if ((year % 100) == 0) {
            is_leap_year = 0;
            if ((year % 400) == 0) {
               is_leap_year = 1; 
            }
        } 
    }

    // Inform the user
    if (is_leap_year) {
        printf("%d is leap year!\n", year); 
    } else {
        printf("%d is not a leap year\n", year);
    }

    // We didn't fail.
    return EXIT_SUCCESS;
}
