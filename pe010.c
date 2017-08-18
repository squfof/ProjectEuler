/* 
 * File:    pe010.c
 * Author:  Jason Gower
 * Created: July 16, 2017, 11:32 PM
 * 
 * Problem: The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * 
 *          Find the sum of all the primes below two million.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 2000000

int main(void)
{
    int isPrime(long);
    
    long long sum = 0;
    
    // brute-force: just add 'em up! (only takes 1 sec on my laptop)
    if (2 < MAX)
        sum += 2;
    
    for (long i = 3 ; i < MAX ; i += 2)
        if (isPrime(i))
            sum += i;
    
    printf("%lli", sum);
    
    return EXIT_SUCCESS;
}

int isPrime(long n)
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
