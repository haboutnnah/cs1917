//
//  main.c
//  memory
//
//  Created by Richard Buckland on 20/11/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long add (int x, int y);

int main(int argc, const char * argv[]) {

    char c ='a';

    unsigned long ul       = 0;
    unsigned int ui        = 1;
    unsigned long long ull = 2;
    unsigned short us      = 3;

    signed long sl       = 4;
    signed int si        = 5;
    signed long long sll = 6;
    signed short ss      = 7;

    long l       = 8;
    int i        = 9;
    long long ll = 10;
    short s      = 11;

    float f = 3.1;
    double d = 3.14;
    printf("========== OTHER ========\n");
    printf("sizeof char = %lu bytes\n", sizeof(c));
    printf("========= UNSIGNED =======\n");
    printf("sizeof(ul) = %lu bytes\n", sizeof(ul));
    printf("sizeof(ui) = %lu bytes\n", sizeof(ui));
    printf("sizeof(ull) = %lu bytes\n", sizeof(ull));
    printf("sizeof(us) = %lu bytes\n", sizeof(us));
    printf("========== SIGNED ========\n");
    printf("sizeof(sl) = %lu bytes\n", sizeof(sl));
    printf("sizeof(si) = %lu bytes\n", sizeof(si));;;;
    printf("sizeof(sll) = %lu bytes\n", sizeof(sll));
    printf("sizeof(ss) = %lu bytes\n", sizeof(ss));
    printf("========= OTHER =======\n");
    printf("sizeof(l) = %lu bytes\n", sizeof(l));
    printf("sizeof(i) = %lu bytes\n", sizeof(i));
    printf("sizeof(ll) = %lu bytes\n", sizeof(ll));
    printf("sizeof(s) = %lu bytes\n", sizeof(s));
    printf("sizeof(f) = %lu bytes\n", sizeof(f));
    printf("sizeof(d) = %lu bytes\n", sizeof(d));

    printf("address of c %p \n", (void*)&c);
    printf("address of ul %p \n", (void*)&ul);
    printf("address of ui%p \n", (void*)&ui);
    printf("address of ull%p \n", (void*)&ull);
    printf("address of us %p \n", (void*)&us);
    printf("address of sl %p \n", (void*)&sl);
    printf("address of si %p \n", (void*)&si);
    printf("address of sll %p \n", (void*)&sll);
    printf("address of ss %p \n", (void*)&ss);
    printf("address of l %p \n", (void*)&l);
    printf("address of i %p \n", (void*)&i);
    printf("address of ll%p \n", (void*)&ll);
    printf("address of s %p \n", (void*)&s);
    printf("address of f %p \n", (void*)&f);
    printf("address of d %p \n", (void*)&d);

    printf("Minimum of char: %d\n", CHAR_MIN);
    printf("Maximum of char: %d\n", CHAR_MAX);
    printf("Minimum of signed short: %d\n", SHRT_MIN);
    printf("Maximum of signed short: %d\n", SHRT_MAX);
    printf("Maximum of unsigned short: %d\n", USHRT_MAX);
    printf("Minimum of signed int: %d\n", INT_MIN);
    printf("Maximum of signed int : %d\n", INT_MAX);
    printf("Maximum of unsigned int: %d\n", UINT_MAX);
    printf("Maximum of char: %d\n", SCHAR_MAX);
    printf("Minimum of char: %d\n", SCHAR_MIN);
    printf("Maximum of char: %d\n", SCHAR_MAX);
    printf("Minimum of char: %d\n", SCHAR_MIN);
    printf("Maximum of char: %d\n", SCHAR_MAX);

/*
    c
    ul
    ui
    ull
    us
    sl
    si
    sll
    ss
    l
    i
    ll
    s
    f
    d
*/

    return EXIT_SUCCESS;
}

