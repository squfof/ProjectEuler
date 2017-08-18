/* 
 * File:    pe003.c
 * Author:  Jason Gower
 * Created: July 16, 2017, 9:45 AM
 * 
 * Problem: The prime factors of 13195 are 5, 7, 13 and 29.
 * 
 *          What is the largest prime factor of the number 600851475143 ?
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 600851475143LL

int main(void)
{
    long long smallestPrime(long long);
    
    long long p = 1;  // largest prime divisor so far
    long long q = 1;  // product of all prime divisor so far
    
    // find the smallest prime divisor, divide it out but multiply it into q
    // once q = NUM, we're done. having kept track of the largest prime so far
    // p will store the answer
    while (q < NUM)
    {
        p = smallestPrime(NUM / q);
        q *= p;
    }
    
    printf("%lli", p);
    
    return EXIT_SUCCESS;
}

// brute-force stuff below -- consider yourself warned!
int isPrime(long long n)
{
    if (n == 2)
        return 1;
    else if (n % 2 == 0)
        return 0;
    
    for (long long i = 3 ; i * i <= n ; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

long long smallestPrime(long long n)
{
    int isPrime(long long);
    
    if (n % 2 == 0)
        return 2;
    
    for (long long i = 3 ; i * i <= n ; i += 2)
        if (isPrime(i) && n % i == 0)
            return i;
    return n;
}
