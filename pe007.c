/* 
 * File:    pe007.c
 * Author:  Jason Gower
 * Created: July 16, 2017, 9:21 PM
 * 
 * Problem: By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can
 *          see that the 6th prime is 13.
 * 
 *          What is the 10,001st prime number?
 */

#include <stdio.h>
#include <stdlib.h>

#define N 10001

int main(void)
{
    int isPrime(int);
    
    int current_prime = 2;
    int prime_counter = 1;
    int possible_prime = 3;
    
    // brute-force: look at integers 2, 3, 4, ..., increment a counter each time 
    // we find a prime, stop when counter reaches desired number
    while (prime_counter < N)
    {
        while (!isPrime(possible_prime))
            possible_prime++;
        
        current_prime = possible_prime++;
        prime_counter++;
    }
    
    printf("The %ith prime is %i", prime_counter, current_prime);
    
    return EXIT_SUCCESS;
}

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
