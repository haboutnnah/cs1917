// by hannah ivy
// for hs1917
// sorts three numbers given in stdin seperated by " "
// and then sorts them and prints them
// doesn't use "if, loops, or the ternary operator"
// On the other hand, emits a ton of branching in the machine code:
//    
//    $ objdump -d ./sort3-lim.out | grep 'jmp' | wc -l
//    20
//    $ objdump -d ./sort3-lim.out | grep 'jz' | wc -l
//    0
//    $ objdump -d ./sort3-lim.out | grep 'je' | wc -l
//    26
//    $ objdump -d ./sort3-lim.out | grep 'jne' | wc -l
//    2
//    $ objdump -d ./sort3-lim.out | grep 'jne' | wc -l
//    

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
    
    int swap;
    int firstGreaterThanThird, firstGreaterThanSecond, secondGreaterThanSecond;
    // literally useless
    int garbage;

    // Let's make the first one the lowest one:

    firstGreaterThanThird = (first > third);
    // if firstGreaterThanThird: swap first and third
    garbage = (firstGreaterThanThird) && (swap = first);
    garbage = (firstGreaterThanThird) && (first = third);
    garbage = (firstGreaterThanThird) && (third = swap);

    // if firstGreaterThanSecond: swap first and second
    firstGreaterThanSecond = (first > second);
    garbage = (firstGreaterThanSecond) && (swap = first);
    garbage = (firstGreaterThanSecond) && (first = second);
    garbage = (firstGreaterThanSecond) && (second = swap);
    
    // Now we have the lowest one being first.
    printf("%d\n", first);

    // if secondGreaterThanSecond: swap second and third
    secondGreaterThanSecond = (second > third);
    garbage = (secondGreaterThanSecond) && (swap = second);
    garbage = (secondGreaterThanSecond) && (second = third);
    garbage = (secondGreaterThanSecond) && (third = swap);

    swap = garbage;

    // And it's sorted
    printf("%d\n", second);
    printf("%d\n", third);
}