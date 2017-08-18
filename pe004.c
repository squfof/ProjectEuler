/* 
 * File:    pe004.c
 * Author:  Jason Gower
 * Created: July 16, 2017, 4:46 PM
 * 
 * Problem: A palindromic number reads the same both ways. The largest palindrome
 *          made from the product of two 2-digit numbers is 9009 = 91 × 99.
 * 
 *          Find the largest palindrome made from the product of two 3-digit numbers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int isPalindrome(int);
    
    int largest_pal = 1;    // largest palindrome so far
    int x, y;               // factors of largest_pal
    int temp;               // product under consideration
    
    // straightforward approach, kept track of the factors out of curiosity
    for (int i = 100 ; i < 1000 ; i++ )
        for (int j = i ; j < 1000 ; j++)
        {
            temp = i * j;
            if (temp > largest_pal && isPalindrome(temp))
            {
                largest_pal = temp;
                x = i;
                y = j;
            }
        }
    
    printf("%i times %i equals %i", x, y, largest_pal);
    
    return EXIT_SUCCESS;
}

int isPalindrome(int n)
{
    int m = (int) floor(log10(n)) + 1;  // number of decimal digits of n
    int digits[m];                      // stores digits of n (in reverse order)
    int x = n;                          // used to get digits
    int i;                              // index
    
    // extract digits (in reverse order, doesn't matter)
    for (i = 0 ; i < m ; i++)           
    {
        digits[i] = x % 10;
        x = (x - digits[i]) / 10;
    }
    
    // check if we have a palindrome
    for (i = 0 ; i < m / 2 ; i++)       
        if (digits[i] != digits[m - 1 - i])
            return 0;
    return 1;
}
