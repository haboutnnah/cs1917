// by hannah ivy
// for hs1917
// sorts three numbers given in stdin seperated by " "
// and then sorts them and prints them

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void sortThreeNumbers (int first, int second, int third);

int main (int argc, char* argv[]) {
    int first, second, third;
    // Get numbers from the user
    scanf ("%d %d %d", &first, &second, &third);
    // Is there a way to run tests on a printf()ing function?
    // Sort the numbers
    sortThreeNumbers(first, second, third);

    return EXIT_SUCCESS;
}

void sortThreeNumbers (int first, int second, int third) {
    // Let's make the first one the lowest one:
    int swap;

    if (first > third) {
        swap = first;
        first = third;
        third = swap;
    }
    // Now let's check if the new/old first is > second
    if (first > second) { 
        swap = first;
        first = second;
        second = swap;
    }
    // Now we have the lowest one being first.
    printf("%d\n", first);
    // Now we just have to check if the second is > the third one
    if (second > third) {
        swap = second;
        second = third;
        third = swap;
    }
    // And it's sorted
    printf("%d\n", second);
    printf("%d\n", third);
}