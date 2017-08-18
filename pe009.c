/* 
 * File:    pe009.c
 * Author:  Jason Gower
 * Created: July 16, 2017, 11:02 PM
 * 
 * Problem: A Pythagorean triplet is a set of three natural numbers, a < b < c,
 *          for which a^2 + b^2 = c^2.
 *          For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
 * 
 *          There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 *          Find the product abc.
 */

#include <stdio.h>
#include <stdlib.h>

#define SPECIAL 1000

int main(void)
{
    int isPythagTriplet(int, int, int);
    
    int a = 1;
    int b = 1;
    int c = SPECIAL - a - b;    // c's value is determined by sum condition
    
    // brute-force: just check all a, b, c.
    // existence is given, so no infinite loop
    while (!isPythagTriplet(a, b, c))
    {
        if (++a == SPECIAL - 1) // increment a, but maybe a is too big...
            a = b++;            // ... give b's value to a (to avoid redundancy)
                                // ... and increment b.
        c = SPECIAL - a - b;    // update c's value, sum of a, b, c must be SPECIAL
    }
    
    printf("a = %i, b = %i, c = %i\n", a, b, c);
    printf("abc = %i", a * b * c);
    
    return EXIT_SUCCESS;
}

int isPythagTriplet(int a, int b, int c)
{
    return (a * a + b * b == c * c) ? 1 : 0;
}

