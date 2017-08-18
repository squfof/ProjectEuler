/* 
 * File:    pe001.c
 * Author:  Jason Gower
 * Created: July 16, 2017, 9:25 AM
 * 
 * Problem: If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9.
 *          The sum of these multiples is 23.
 *          
 *          Find the sum of all the multiples of 3 or 5 below 1000.
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 1000

// "Math" version (loop-y CS version in comment below): 

int main(void)
{
    // use Gauss' summation formula for all the multiples of 3 and 5,
    // subtracting off all multiples of 15
    int sum = 0;
    
    // upper bounds on Gauss' formula
    int max3 = NUM/3;
    int max5 = NUM/5;
    int max15 = NUM/15;
    
    // terms must be strictly less than NUM, so back up one
    // if NUM is divisible by 3, 5, and/or 15
    if (NUM % 3 == 0)
        max3--;
    if (NUM % 5 == 0)
        max5--;
    if (NUM %15 == 0)
        max15--;
    
    // time for the formula
    sum = 3 * max3 * (max3 + 1) / 2 ;
    sum += 5 * max5 * (max5 + 1) / 2;
    sum -= 15 * max15 * (max15 + 1) / 2;
    
    printf("%i", sum);
    
    return EXIT_SUCCESS;
}

/*
// "CS" version:

int main(void)
{
    int sum = 0;
    
    for (int i = 3 ; i < NUM ; i++)
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    
    printf("%i", sum);
    
    return EXIT_SUCCESS;
}
 */

