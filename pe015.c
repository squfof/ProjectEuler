/* 
 * File:    pe015.c
 * Author:  Jason Gower
 * Created: July 18, 2017, 11:55 PM
 * 
 * Problem: Starting in the top left corner of a 2×2 grid, and only being able to
 *          move to the right and down, there are exactly 6 routes to the bottom-
 *          right corner: RRDD, RDRD, RDDR, DRRD, DRDR, DDRR.
 * 
 *          How many such routes are there through a 20×20 grid?
 */

#include <stdio.h>
#include <stdlib.h>

// since we have 40 moves to make total, and 20 must be down and 20 must be right,
// we are just counting the number of ways to choose 20 from 40
int main(void)
{
    long long binomial_coef(int, int);
    
    printf("%lli", binomial_coef(40, 20));
    
    return EXIT_SUCCESS;
}

long long binomial_coef(int n, int k)
{
    if (k == 0)
        return 1;
    else if (k > n / 2)
        return binomial_coef(n, n - k);
    else
        return n * binomial_coef(n - 1, k - 1) / k;
}

