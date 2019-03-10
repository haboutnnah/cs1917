/*
 *  doomsday.c
 *  A program to test a function dayOfWeek which determines which
 *  day of the week a particular date falls on.
 *  (only for dates after the start of the Gregorian calendar).
 *
 *  Program stub created by Richard Buckland on 17/03/14
 *  This program by Hannah Ivy
 *  Freely licensed under Creative Commons CC-BY-3.0
 *
 *
 */
 
// TODO: SWAP 7 FOR CONST
// TODO: COMMENTS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MONDAY       0
#define TUESDAY      1
#define WEDNESDAY    2
#define THURSDAY     3
#define FRIDAY       4
#define SATURDAY     5
#define SUNDAY       6

#define DAYS_IN_WEEK 7

#define JANUARY      1
#define FEBRUARY     2
#define MARCH        3
#define APRIL        4
#define MAY          5
#define JUNE         6
#define JULY         7
#define AUGUST       8
#define SEPTEMBER    9
#define OCTOBER      10
#define NOVEMBER     11
#define DECEMBER     12

#define TRUE         1
#define FALSE        0
#define ERROR        -1

void runTests (void);
void runStudentTests (void);
int dayOfWeek (int doomsday, int leapYear, int month, int day);
int daysInMonth (int leapYear, int month);
int distanceFromDoomsday (int doomsday, int month, int day);

int main (int argc, char *argv[]) {
    runTests();
    printf ("all tests passed - You are awesome!\n");
    return EXIT_SUCCESS;
}

void runTests (void) {
    // Richard
    assert (dayOfWeek (THURSDAY,  FALSE,  4,  4) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  6,  6) == FRIDAY);
    assert (dayOfWeek (MONDAY,    FALSE,  8,  8) == MONDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 12) == FRIDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  9,  5) == THURSDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  5,  9) == FRIDAY);
    assert (dayOfWeek (SUNDAY,    FALSE,  7, 11) == SUNDAY);
    assert (dayOfWeek (TUESDAY,   FALSE, 11,  7) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE,  3,  7) == WEDNESDAY);

    assert (dayOfWeek (THURSDAY,  FALSE,  4,  5) == FRIDAY);
    assert (dayOfWeek (SATURDAY,  FALSE,  6,  5) == FRIDAY);
    assert (dayOfWeek (MONDAY,    FALSE,  8,  9) == TUESDAY);
    assert (dayOfWeek (WEDNESDAY, FALSE, 10,  9) == TUESDAY);
    assert (dayOfWeek (FRIDAY,    FALSE, 12, 20) == SATURDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  9,  9) == MONDAY);
    assert (dayOfWeek (FRIDAY,    FALSE,  5,  5) == MONDAY);
    assert (dayOfWeek (SUNDAY,    FALSE,  7,  7) == WEDNESDAY);
    assert (dayOfWeek (TUESDAY,   FALSE, 11, 11) == SATURDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  3, 30) == SATURDAY);
 
    assert (dayOfWeek (TUESDAY,   FALSE,  2,  28) == TUESDAY);
    assert (dayOfWeek (TUESDAY,   FALSE,  2,  27) == MONDAY);
    assert (dayOfWeek (THURSDAY,  FALSE,  1,  3)  == THURSDAY);
    runStudentTests();
}

void runStudentTests (void) {
    //Please add your own unit tests here with a comment beside, 
    //to indicate that you wrote them For example:
    assert (dayOfWeek (WEDNESDAY, FALSE,  8, 31) == FRIDAY);   // Angela Finlayson
    
    //2017 cohort:
    assert (dayOfWeek (TUESDAY  ,  TRUE,  8, 18) == FRIDAY);   // Stanley Su
    assert (dayOfWeek (MONDAY   ,  TRUE,  1,  1) == FRIDAY);   // Alex Huang
    assert (dayOfWeek (TUESDAY  ,  TRUE,  2, 28) == MONDAY);   // Felicia Ee
    assert (dayOfWeek (SATURDAY , FALSE,  1,  2) == FRIDAY);   // Maksim Lisau
    assert (dayOfWeek (SATURDAY , FALSE,  3, 15) == SUNDAY);   // Angeni Bai
    assert (dayOfWeek (FRIDAY   ,  TRUE,  2, 29) == FRIDAY);   // Alex Tan
    assert (dayOfWeek (MONDAY   ,  TRUE,  1,  9) == SATURDAY); // Luke Fisk-Lennon
    assert (dayOfWeek (THURSDAY ,  TRUE,  2, 29) == THURSDAY); // Jarrod Li
    assert (dayOfWeek (FRIDAY   ,  TRUE,  1,  3) == THURSDAY); // Mirela Tomicic
    assert (dayOfWeek (TUESDAY  , FALSE,  3, 16) == THURSDAY); // Andrew Yu
    assert (dayOfWeek (SUNDAY   , FALSE,  7, 11) == SUNDAY);   // Samuel Hagan
    assert (dayOfWeek (TUESDAY  , FALSE,  4,  6) == THURSDAY); // Tracey Chiu
    assert (dayOfWeek (MONDAY   ,  TRUE, 12, 31) == SATURDAY); // Andrew Timkov
    assert (dayOfWeek (TUESDAY  , FALSE, 12, 25) == MONDAY);   // Matthew Darley
    assert (dayOfWeek (TUESDAY  , FALSE, 12,  5) == TUESDAY);  // Nicholas Austen
    assert (dayOfWeek (FRIDAY   ,  TRUE,  2, 29) == FRIDAY);   // Christina Shi
    assert (dayOfWeek (MONDAY   , FALSE,  8, 10) == WEDNESDAY);// Noa Challis 
    assert (dayOfWeek (FRIDAY   ,  TRUE, 11, 24) == MONDAY);   // Evan Lee
    assert (dayOfWeek (WEDNESDAY,  TRUE,  2, 29) == WEDNESDAY);// Callum Predavec
    assert (dayOfWeek (TUESDAY  , FALSE, 11, 11) == SATURDAY); // Joel Perry
    assert (dayOfWeek (SATURDAY , FALSE,  3,  1) == SUNDAY);   // Phoebe Zuo 
    assert (dayOfWeek (MONDAY   , FALSE,  2, 25) == FRIDAY);   // Sebastien Higgs
    assert (dayOfWeek (TUESDAY  , FALSE,  3, 25) == SATURDAY); // Nicholas Patrikeos
    assert (dayOfWeek (MONDAY   ,  TRUE,  2,  2) == TUESDAY);  // Rahul Kumar
    assert (dayOfWeek (MONDAY   ,  TRUE,  2,  2) != MONDAY);   // Roman Ozerski
    assert (dayOfWeek (MONDAY   ,  TRUE,  2,  2) != THURSDAY); // Dylan Stephens
    assert (dayOfWeek (TUESDAY  , FALSE, 12,  4) == MONDAY);   // Lucas Barbosa :)
    assert (dayOfWeek (WEDNESDAY,  TRUE,  1,  4) == WEDNESDAY);// Eddie Qi
    assert (dayOfWeek (TUESDAY  , FALSE,  7, 12) == WEDNESDAY);// Jason Hidajat
    assert (dayOfWeek (TUESDAY , TRUE, 4, 4) == TUESDAY);      // Charlotte Low
    assert (dayOfWeek (MONDAY   ,  TRUE,  2,  1) == MONDAY);   // Tim Lee
    assert (dayOfWeek (MONDAY   ,  TRUE, 12, 25) == SUNDAY);   // George Flabouris
    assert (dayOfWeek (TUESDAY, TRUE, 2, 28) == MONDAY);       // 28/02/1972 (Jack Jiang)
    assert (dayOfWeek (TUESDAY  , FALSE,  7,  1) == SATURDAY); // Kevin Yan
    assert (dayOfWeek (THURSDAY, FALSE, 4, 5) == FRIDAY);      // Archie Croston
    assert (dayOfWeek (SUNDAY  , FALSE, 7, 12) != FRIDAY);     // Chris Law 
    assert (dayOfWeek (WEDNESDAY, FALSE, 12, 19) == 
            dayOfWeek (WEDNESDAY, TRUE, 12, 19) );             // Marcus Handley
    assert (dayOfWeek (THURSDAY, FALSE, 4, 2) == TUESDAY);     // Callum Koh (2017)
    
    //2018 cohort:
    assert (dayOfWeek (THURSDAY, FALSE, 1, 2) == WEDNESDAY);   // Paul Lapinski
    assert (dayOfWeek (TUESDAY, TRUE, 2, 27) == SUNDAY);       // Paul Lapinski
    assert (dayOfWeek (TUESDAY, TRUE, 2, 28) == MONDAY);       // Paul Lapinski
    assert (dayOfWeek (THURSDAY, TRUE, 2, 2) == 
            dayOfWeek (WEDNESDAY, FALSE, 2, 2));               // Tom Harrison-Brown
    assert (dayOfWeek (MONDAY, TRUE, 8, 1) == MONDAY);         // Tom Harrison-Brown
    assert (dayOfWeek (SATURDAY, FALSE, 1, 21) == WEDNESDAY);  // Jennivine Chen
    assert (dayOfWeek (SUNDAY   , TRUE, 1, 4) == SUNDAY);      // Kai Mashimo
    assert (dayOfWeek (WEDNESDAY, FALSE, 8, 23) == THURSDAY);  // Lily Yang
    assert (dayOfWeek (MONDAY, TRUE, 2, 27) != MONDAY);        // Joshua Quail :P
    assert (dayOfWeek (WEDNESDAY, FALSE, 10, 8) == MONDAY);    // Luke Cantor
    assert (dayOfWeek (SUNDAY, TRUE, 12, 14) == TUESDAY);      // Dillon de Silva XD
    assert (dayOfWeek (WEDNESDAY, FALSE, 12, 31) == MONDAY);   // Izaac Coffey
    assert (dayOfWeek (MONDAY, TRUE, 1, 1) == FRIDAY);         // James Wilkie
    assert (dayOfWeek (WEDNESDAY, FALSE, 11, 9) == FRIDAY);    // Darby Thompson
    assert (dayOfWeek (WEDNESDAY, FALSE, 1, 29) == MONDAY);    // Reilly Fox
    assert (dayOfWeek (FRIDAY, FALSE, 8, 12) == TUESDAY);      // Lucca Harvey
    assert (dayOfWeek (TUESDAY, TRUE, 4, 20) == THURSDAY);     // Callum Koh (2018) ;)
    assert (dayOfWeek (THURSDAY, FALSE, 1, 1) == TUESDAY);     // Harold Chin
    assert (dayOfWeek (WEDNESDAY, TRUE, 3, 14) == WEDNESDAY);  // Luke Cantor (pi day)
    assert (dayOfWeek (FRIDAY, TRUE, 3, 0) == FRIDAY);         // Josh Harcombe
    assert (dayOfWeek (THURSDAY, TRUE, 6, 6) == THURSDAY);     // Sophie Ogilvy
    assert (dayOfWeek (FRIDAY, FALSE, 12, 12) == FRIDAY);      // James Balajan
    assert (dayOfWeek (WEDNESDAY, FALSE, 8, 26) == SUNDAY);    // Tay your bae
    assert (dayOfWeek (TUESDAY, TRUE, 5, 27) == SATURDAY);     // Allan Goodman
    assert (dayOfWeek (FRIDAY, FALSE, 3, 26) == WEDNESDAY);    // Eric R Chang
    assert (dayOfWeek (MONDAY, FALSE, 6, 27) == MONDAY);       // Patrick Fennell
    assert (dayOfWeek (TUESDAY, TRUE, 8, 23) == WEDNESDAY);    // Harris Borman (You forgot a parenthesis!)
    assert (dayOfWeek (SATURDAY, TRUE, 5, 13) == WEDNESDAY);   // Luka Lafaye de Micheaux
    assert (dayOfWeek (SATURDAY, TRUE, 10, 9) == FRIDAY);      // Luka Lafaye de Micheaux
    assert (dayOfWeek (TUESDAY, FALSE,  3, 4) == SATURDAY);    // Zachary Cheng
    assert (dayOfWeek (THURSDAY, FALSE, 7, 2) == TUESDAY);     // Sam Chapman - trying to get negative answers
    assert (dayOfWeek (WEDNESDAY, FALSE, 10, 2) == TUESDAY);   // Sam Chapman - trying to get negative answers
    assert (dayOfWeek (THURSDAY, FALSE, 11, 0) == THURSDAY);   // Sam Chapman - trying to get negative answers
    assert (dayOfWeek (WEDNESDAY, FALSE, 12, 4) == TUESDAY);   // Sam Chapman - trying to get negative answers
    assert (dayOfWeek (THURSDAY, FALSE, 5, 1) == WEDNESDAY);   // Sam Chapman - trying to get negative answers
    assert (dayOfWeek (MONDAY, FALSE, 3, 10) == THURSDAY);     // Sam McKay
    assert (dayOfWeek (FRIDAY, TRUE, 1, 20) == SUNDAY);        // Sam McKay
    assert (dayOfWeek (FRIDAY, TRUE, 4, 4) == FRIDAY);         // Josh Green: Ensuring LeapYear Doesn't throw off
    assert (dayOfWeek (MONDAY, TRUE, 12, 12) == MONDAY);       // Josh Green: same as above
    assert (dayOfWeek (SUNDAY, FALSE, 4, 5) == MONDAY);        // Josh Green above
    assert (dayOfWeek (WEDNESDAY, FALSE, 12, 11) == TUESDAY);  // Josh Green below
    assert (dayOfWeek (THURSDAY, FALSE, 6, 14) == FRIDAY);     // Jessica Luo 
    // assert (dayOfWeek (SATURDAY, FALSE, 2, 10) == SATURDAY);   // Mehidi Hussaini (this is wrong - Ben Hepburn)
    assert (dayOfWeek (THURSDAY, TRUE, 2, 29) == THURSDAY);    // Laeeque Jamdar
    assert (dayOfWeek (SATURDAY, TRUE, 12, 30) == WEDNESDAY);  // Jason Yu
    assert (dayOfWeek (TUESDAY, TRUE, 2, 28) == MONDAY);       // Taylor Wood
    assert (dayOfWeek (FRIDAY, TRUE, 1, 1) == TUESDAY);        // James Leib
    assert (dayOfWeek (THURSDAY, FALSE, 1, 21) == MONDAY);     // Ayden Gebran
    assert (dayOfWeek (THURSDAY, TRUE, 2, 23) == FRIDAY);      // Dominic Lee (ovo)
    assert (dayOfWeek (THURSDAY, FALSE, 6, 21) == FRIDAY);     // Monique Curulli
    assert (dayOfWeek (WEDNESDAY, TRUE, 6, 10) == SUNDAY);     // Matthew Rossouw
    assert (dayOfWeek (SUNDAY, FALSE, 4, 17) == SATURDAY);     // Matthew Rossouw
    assert (dayOfWeek (THURSDAY, FALSE, 1, 4) == FRIDAY);      // Justin Lou
    assert (dayOfWeek (THURSDAY, FALSE, 1, 3) == THURSDAY);    // Justin Loud 
    assert (dayOfWeek (THURSDAY, FALSE, 1, 2) == WEDNESDAY);   // Justin Lou
    assert (dayOfWeek (FRIDAY, FALSE, 12, 2) == TUESDAY);      // Zach Leong
    assert (dayOfWeek (WEDNESDAY, FALSE, 1, 1) == MONDAY);     // Ezra Hui
    assert (dayOfWeek (WEDNESDAY, TRUE, 12, 31) == MONDAY);    // Ezra Hui 
    assert (dayOfWeek (SUNDAY, FALSE, 2, 29) == MONDAY);       // Manu Masson :) This one may break some people
    assert (dayOfWeek (THURSDAY, TRUE, 2, 29) == THURSDAY);    // Gidon Kessler
    assert (dayOfWeek (MONDAY, FALSE, 1, 364) == FRIDAY);      // Oden Petersen, abnormal value for day of month
    assert (dayOfWeek (THURSDAY, TRUE , 1, 5) == FRIDAY);      // Nan Yan
    assert (dayOfWeek (FRIDAY, TRUE, 2, 28) == THURSDAY);      // Nan Yan
    assert (dayOfWeek (MONDAY, TRUE, 12, 31) == SATURDAY);     // Nan Yan
    assert (dayOfWeek (FRIDAY, FALSE, 12, 5) == FRIDAY);       // Kathryn Betts
    assert (dayOfWeek (WEDNESDAY, FALSE, 3, 25) == SUNDAY);    // William Gao (2018), the date that the assignments due!
    assert (dayOfWeek (WEDNESDAY, FALSE, 5, 5) == SATURDAY);   // Anna Brew
    assert (dayOfWeek (THURSDAY, FALSE, 9, 18) == WEDNESDAY);  // Steven Li
    assert (dayOfWeek (FRIDAY, FALSE, 12, 1) == MONDAY);       // Steven Li
    assert (dayOfWeek (MONDAY, FALSE, 8, 30) == TUESDAY);      // Steven Li
    
    //2019 cohort:
    assert (dayOfWeek (TUESDAY, TRUE, 8, 1) == TUESDAY);       // Ronaldo Keng
    assert (dayOfWeek (SUNDAY, FALSE, 1, 17) == SUNDAY);       // Ronaldo Keng
    assert (dayOfWeek (MONDAY, FALSE, 7, 28) == THURSDAY);     // Ronaldo Keng
    assert (dayOfWeek (SATURDAY, TRUE, 8, 9) != MONDAY);       // Moe Iwasawa (can't be Monday; day after Doomsday is Sunday)
    assert (dayOfWeek (SATURDAY, TRUE, 1, 32) == SATURDAY);    // Moe Iwasawa (should theoretically roll over to Feb)
    assert (dayOfWeek (THURSDAY, FALSE, 2, 29) == FRIDAY);     // Moe Iwasawa (also should be 1 Mar since it's not leap year)
    assert (dayOfWeek (SUNDAY, TRUE, 1, 18) == SUNDAY);        // Alessandro Eliot - My Birthday!
    assert (dayOfWeek (TUESDAY, TRUE, 2, 29) == TUESDAY);      // Aiden Jin (Leap day on Leap year)
    assert (dayOfWeek (TUESDAY, TRUE, 2, 28) == MONDAY);       // Aiden Jin (Day before Leap day on Leap year)
    assert (dayOfWeek (FRIDAY, TRUE, 1, 4) == FRIDAY);         // Aiden Jin January 4 in Leap year
    assert (dayOfWeek (FRIDAY, TRUE, 1, 1) == TUESDAY);        // Aiden Jin January 1 in Leap year
    assert (dayOfWeek (FRIDAY, TRUE, 7, 10) == THURSDAY);      // Ethan Moliver
    assert (dayOfWeek (FRIDAY, TRUE, 10, 22) == WEDNESDAY);    // Ethan Moliver
    assert (dayOfWeek (FRIDAY, TRUE, 2, 29) == FRIDAY);        // Ethan Moliver
    assert (dayOfWeek (TUESDAY, TRUE, 1, 3) == MONDAY);        // Ben Hepburn
    assert (dayOfWeek (TUESDAY, TRUE, 5, 7) == SUNDAY);        // Ben Hepburn
    assert (dayOfWeek (THURSDAY, FALSE, 8, 19) == MONDAY);     // Isaac Ng
    assert (dayOfWeek (WEDNESDAY, FALSE, 6, 27) == 
            dayOfWeek (WEDNESDAY, TRUE, 2, 29));               // Isaac Ng
    assert (dayOfWeek (THURSDAY, FALSE, 3, 8) == FRIDAY);       // Isaac Ng
    //assert (dayOfWeek (MONDAY, FALSE, 6, 17) == SUNDAY);       // Kelvin Huang (Pretty sure this one doesn't work - Hannah Ivy)
    assert (dayOfWeek (WEDNESDAY, FALSE, 10, 23) == TUESDAY);  // Hannah Ivy -- My birthday!
    assert (dayOfWeek (SATURDAY , FALSE, 3, 1) == SUNDAY); // Hannah Ivy
    assert (dayOfWeek (WEDNESDAY , FALSE, 10, 25) == THURSDAY); // Leo Shchurov
    assert (dayOfWeek (SATURDAY , FALSE, 3, 21) == SATURDAY); // Ethan Samuels
    assert (dayOfWeek (SUNDAY, TRUE, 2, 22) == SUNDAY); //Angus Mclean
    assert (dayOfWeek (THURSDAY, FALSE, 10, 17) == THURSDAY); //Damjan Stevanoski
    assert (dayOfWeek (WEDNESDAY, FALSE, 5, 11) == FRIDAY); // Shunyao Liang
}
 
 
// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.
int dayOfWeek (int doomsday, int leapYear, int month, int day) {
    int dayOfWeek;
    int daysInGivenMonth = daysInMonth(leapYear, month);
    if (month > 3 && month % 2 == 0) {
        // Even months >3 have a doomsday on the _n_th of the _n_th
        dayOfWeek = distanceFromDoomsday(doomsday, month, day);
    } else if (month == 1) {
        // January: dd = 4 if leapear, and dd = 3 if not leap year
        if (leapYear) {
            dayOfWeek = distanceFromDoomsday(doomsday, 4, day);
        } else {
            dayOfWeek = distanceFromDoomsday(doomsday, 3, day);
        }
    } else if (month == 2) {
        // February: dd = last day of the month
        dayOfWeek = distanceFromDoomsday(doomsday, daysInGivenMonth, day);
    } else if (month == 3) {
        // March: dd = last day of feb - or march 0th
        dayOfWeek = distanceFromDoomsday(doomsday, 0, day);
    } else if (month == 5) {
        // May: dd = 9th of 5th (Work 9-5) (Wikipedia)
        dayOfWeek = distanceFromDoomsday(doomsday, 9, day);
    } else if (month == 7) {
        // July: dd = 11th of 7th (Work at 7/11) (Wikipedia)
        dayOfWeek = distanceFromDoomsday(doomsday, 11, day);
    } else if (month == 9) {
        // September - 5th of the 9th
        dayOfWeek = distanceFromDoomsday(doomsday, 5, day);
    } else if (month == 11) {
        // November 7th of the eleventh
        dayOfWeek = distanceFromDoomsday(doomsday, 7, day);
    } else {
        // They gave us a different month
        dayOfWeek = ERROR;
    }
    /*printf("dayOfWeek (%d, %d, %d, %d) = %d\n\n", 
          doomsday, leapYear, month, day, dayOfWeek);*/
    return (dayOfWeek);
}

// Given if a year is a leapyear and a month,
// calculates the day in the month.
int daysInMonth(int leapYear, int month) {
    // Note: This is only used for februaries
    // so I overengineered this, oops 

    int daysInGivenMonth;
    if (month < 8) {
        // Covers months 1, 3, 5, 7
        if (month == 2) {
            // February depends on leap year
            if (leapYear) {
                daysInGivenMonth =  29;
            }
            else {
                daysInGivenMonth = 28;
            }
        } else if (month % 2 == 0) {
            // If it's even, it has 30 days
            daysInGivenMonth = 30;
        } else {
            // If it's odd it has 31
            daysInGivenMonth = 31;
        } 
    } else {
        // Covers months 8, 10, 12
        if (month % 2 == 0) {
            // Even has 31
            daysInGivenMonth =  31;
        } else {
            // Odd has 30
            daysInGivenMonth = 30;
        }
    }

    return daysInGivenMonth;
}

// Given the doomsday, the dooms day for the month 
// (or any day to compare to), calculates the difference between
// the last two and this case adjusts it to the doomsday
int distanceFromDoomsday (int doomsday, int compareAgainst, int day) {
    int dayOfWeek;
    // Add DAYS_IN_WEEK to all to fix possible negatives
    day += DAYS_IN_WEEK;
    compareAgainst += DAYS_IN_WEEK;
    doomsday += DAYS_IN_WEEK;

    /*printf("%d, %d, %d\n", doomsday, compareAgainst, day);*/

    if (day == compareAgainst) {
        /*printf("day is on doomsday\n");*/
        dayOfWeek = doomsday;
    } else if (day > compareAgainst) {
        /*printf("day is above doomsday\n");*/
        dayOfWeek = ((day - compareAgainst) % DAYS_IN_WEEK);
        /*printf("difference mod DAYS_IN_WEEK = %d\n", dayOfWeek);*/
        dayOfWeek = ((doomsday + dayOfWeek) % DAYS_IN_WEEK);
        /*printf("and now adding the doomsday is %d\n", dayOfWeek);*/
    } else {
        /*printf("day is below doomsday\n");*/
        dayOfWeek = ((compareAgainst - day) % DAYS_IN_WEEK);
        /*printf("difference mod DAYS_IN_WEEK = %d\n", dayOfWeek);*/
        dayOfWeek = ((doomsday - dayOfWeek) % DAYS_IN_WEEK);
        /*printf("and now subbing from the doomsday is %d\n", dayOfWeek);*/
    }

    // Negate negative values
    dayOfWeek = (dayOfWeek + DAYS_IN_WEEK) % DAYS_IN_WEEK;
    return dayOfWeek;
}
