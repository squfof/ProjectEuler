/* 
 * File:    pe016.c
 * Author:  Jason Gower
 * Created: July 19, 2017, 12:19 AM
 * 
 * Problem: 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * 
 *          What is the sum of the digits of the number 2^1000?
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define POWER 1000      // exponent of two

int main(void)
{
    int m = 1 + floor(POWER * log10(2));    // number of digits in result of power
    int digits[m];                          // digits of result (reverse order)
    int i, j;                               // indices
    int carry;                              // used in repeated multiplication by two
    int sum = 0;                            // sum of digits
    
    // initialize result of power to 1
    digits[0] = 1;
    for (i = 1 ; i < m ; i++)
        digits[i] = 0;
    
    // multiply previous set of digits by 2, then deal with carry
    for (i = 0 ; i < POWER ; i++)
    {
        carry = 0;
        for (j = 0 ; j < m ; j++)
            {
                digits[j] *= 2;
                digits[j] += carry;
                if (digits[j] > 9)
                {
                    carry = 1;
                    digits[j] %= 10;
                }
                else
                    carry = 0;
            }
    }

    // compute sum of digits, print result of power (just curious), print sum
    for (i = m - 1; i >= 0 ; i--)
    {
        printf("%i", digits[i]);
        sum += digits[i];
    }
    printf("\n\n%i", sum);
    
    return EXIT_SUCCESS;
}

