/* 
 * File:    pe002.c
 * Author:  Jason Gower
 * Created: July 16, 2017, 9:34 AM
 * 
 * Problem: Each new term in the Fibonacci sequence is generated by adding the
 *          previous two terms. By starting with 1 and 2, the first 10 terms will
 *          be:
 * 
 *          1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 * 
 *          By considering the terms in the Fibonacci sequence whose values do
 *          not exceed four million, find the sum of the even-valued terms.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 4000000

int main(void)
{
    int sum = 0;
    
    int f_a = 1;
    int f_b = 1;
    int f_c;
    
    while ((f_c = f_a + f_b) <= MAX)
    {
        if (f_c % 2 == 0)
            sum += f_c;
        
        f_a = f_b;
        f_b = f_c;
    }
    
    printf("%i", sum);
    
    return EXIT_SUCCESS;
}
