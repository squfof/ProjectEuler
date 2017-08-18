/* 
 * File:    pe005.c
 * Author:  Jason Gower
 * Created: July 16, 2017, 7:47 PM
 * 
 * Problem: 2520 is the smallest number that can be divided by each of the numbers
 *          from 1 to 10 without any remainder.
 * 
 *          What is the smallest positive number that is evenly divisible by all
 *          of the numbers from 1 to 20?
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 20

int main(void)
{
    int isPrime(int);
    
    int smallest_mult = 1;      // store smallest multiple here
    int prime_exp;              // largest exponent of prime under consideration such that
                                // prime to this power is <= MAX
    
    // clearly only the primes in 1..MAX will be considered.
    // to get the exponent of each, just compute the largest e such that p^e <= MAX.
    // finally, multiply each of these p^e.
    for (int i = 2 ; i <= MAX ; i++)
        if (isPrime(i))
        {
            prime_exp = (int) floor(log(MAX) / log(i));
            smallest_mult *= (int) pow(i, prime_exp);
        }
    
    printf("%i", smallest_mult);
    
    return EXIT_SUCCESS;
}

// brute-force
int isPrime(int n)
{
    if (n == 2)
        return 1;
    else if (n % 2 == 0)
        return 0;
    
    for (int i = 3 ; i * i <= n ; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}
