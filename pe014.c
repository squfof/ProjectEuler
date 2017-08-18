/* 
 * File:    pe014.c
 * Author:  Jason Gower
 * Created: July 18, 2017, 11:09 PM
 * 
 * Problem: The following iterative sequence is defined for the set of positive
 *          integers:
 *          n → n/2 (n is even)
 *          n → 3n + 1 (n is odd)
 * 
 *          Using the rule above and starting with 13, we generate the following
 *          sequence:
 *          13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
 *          It can be seen that this sequence (starting at 13 and finishing at 1)
 *          contains 10 terms. Although it has not been proved yet (Collatz Problem),
 *          it is thought that all starting numbers finish at 1.
 * 
 *          Which starting number, under one million, produces the longest chain?
 * 
 *          NOTE: Once the chain starts the terms are allowed to go above one million.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000L

int main(void)
{
    long long collatz(long long);
    
    long long longest_length = 1;
    long long longest_start = 1;
    long long current_length = 1;
    long long start_value;
    long long c_value;
    
    // brute-force: check lengths for integers 1, 2, ..., MAX-1
    // takes 4 secs on my machine
    for (start_value = 1 ; start_value < MAX ; start_value++)
    {
        current_length = 1;
        c_value = start_value;
        while (c_value > 1)
        {
            c_value = collatz(c_value);
            current_length++;
        }
        
        if (current_length > longest_length)
        {
            longest_length = current_length;
            longest_start = start_value;
        }
    }
    
    printf("Length %lli starting at %lli", longest_length, longest_start);
    return EXIT_SUCCESS;
}

long long collatz(long long n)
{
    if (n % 2 == 0)
        return n / 2;
    else
        return 3 * n + 1;
}
