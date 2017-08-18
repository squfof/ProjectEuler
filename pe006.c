/* 
 * File:    pe006.c
 * Author:  Jason Gower
 * Created: July 16, 2017, 9:10 PM
 * 
 * Problem: The sum of the squares of the first ten natural numbers is:
 *          1^2 + 2^2 + ... + 10^2 = 385.
 *          The square of the sum of the first ten natural numbers is:
 *          (1 + 2 + ... + 10)^2 = 552 = 3025.
 *          Hence the difference between the sum of the squares of the first ten
 *          natural numbers and the square of the sum is 3025 − 385 = 2640.
 * 
 *          Find the difference between the sum of the squares of the first one
 *          hundred natural numbers and the square of the sum.
 */

#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(void)
{
    int sum_of_squares;
    int square_of_sum;
    
    // Gauss' formulas, that's it (CS loop-y version in comment below)
    sum_of_squares = N * (N+1) * (2*N + 1) / 6;
    
    square_of_sum = N * (N+1) / 2;
    square_of_sum *= square_of_sum;
    
    printf("%i", square_of_sum - sum_of_squares);
    
    return EXIT_SUCCESS;
}

/*
int main(void)
{
    int sum_of_squares = 0;
    int square_of_sum = 0;
    
    for (int i = 1 ; i <= N ; i++)
    {
        sum_of_squares += i * i;
        square_of_sum += i;
    }
    square_of_sum *= square_of_sum;
    
    printf("%i", square_of_sum - sum_of_squares);
    
    return EXIT_SUCCESS;
}
*/

