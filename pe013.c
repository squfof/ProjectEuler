/* 
 * File:    pe013.c
 * Author:  Jason Gower
 * Created: July 18, 2017, 1:02 PM
 * 
 * Problem: Work out the first ten digits of the sum of the following one hundred
 *          50-digit numbers (see numbers.txt).
 * 
 *          Note: I actual compute all digits, out of curiosity.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 100
#define COLUMNS 50

int main(void)
{
    int digits[ROWS][COLUMNS];  // digits of the numbers
    int i, j;                   // indices
    int m;                      // max number of digits in sum
    char * s;                   // store digits of sum
    int sum = 0;                // sum of digits in one column
    int carry = 0;              // carry to next digit (column)
    
    // open file for read
    FILE * f = fopen("./pe013.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return EXIT_FAILURE;
    }
    
    // read and store digits from text file
    for (i = 0 ; i < ROWS ; i++)
    {
        for (j = 0 ; j < COLUMNS ; j++)
            digits[i][j] = fgetc(f) - '0';
        fgetc(f);   // should be \n, or EOF
    }

    fclose(f);
    
    // sum along columns, storing only the least significant digit...
    // and adding the carry to then next column's sum
    m = COLUMNS + (int) ceil(log10(ROWS));
    s = calloc(m + 1, sizeof(char)) ;
    
    *(s + COLUMNS) = '\0';
    for (j = COLUMNS - 1 ; j >= 0 ; j--)
    {
        sum = carry;
        for (i = 0 ; i < ROWS ; i++)
            sum += digits[i][j];
        
        *(s + j) = sum % 10 + '0';
        carry = (sum - sum % 10) / 10;
    }
    
    // print whatever is left in carry, then the column-sum digits
    printf("%i%s\n", carry, s);

    free(s);
    
    return EXIT_SUCCESS;
}

