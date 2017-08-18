/* 
 * File:    pe020.c
 * Author:  Jason Gower
 * Created: July 21, 2017, 12:31 AM
 * 
 * Problem: n! means n × (n − 1) × ... × 3 × 2 × 1
 *          For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, and the sum of
 *          the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
 * 
 *          Find the sum of the digits in the number 100!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int main(void)
{
    // will store decimal digits of MAX! in an array...
    // ... so need to know how many digits before we can do anything else
    int m = 0;          // number of digits in MAX!
    float temp = 0.0;   // temp storage
    int i, j;           // indices
    int carry;          // carry from multiplication
    int sum = 0;        // sum of digits of MAX!
    
    // compute how many digits
    for (i = 1 ; i <= MAX ; i++)
        temp += log10(i);
    m = 1 + (int) floor(temp);
    
    // initialize digits to represent the number 1
    int digits[m];      // store digits (in reverse order)
    digits[0] = 1;
    for (i = 1 ; i < m ; i++)
        digits[i] = 0;
    
    // multiply digits by 2, 3, ..., MAX, and deal with carry
    for (i = 2 ; i <= MAX ; i++)
    {
        carry = 0;
        for (j = 0 ; j < m ; j++)
        {
            digits[j] *= i;
            digits[j] += carry;
            if (digits[j] > 9)
            {
                carry = (digits[j] - (digits[j] % 10)) / 10;
                digits[j] %= 10;
            }
            else
                carry = 0;
        }
    }
    
    // print MAX! (just curious) and sum of digits
    for (i = 0 ; i < m ; i++)
    {
        printf("%i", digits[m - 1 - i]);
        sum += digits[i];
    }
    printf("\n\n%i", sum);
    
    return EXIT_SUCCESS;
}

