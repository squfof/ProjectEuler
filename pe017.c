/* 
 * File:    pe017.c
 * Author:  Jason Gower
 * Created: July 20, 2017
 * 
 * Problem: If the numbers 1 to 5 are written out in words: one, two, three, four,
 *          five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * 
 *          If all the numbers from 1 to 1000 (one thousand) inclusive were written
 *          out in words, how many letters would be used?
 * 
 *          Note: Do not count spaces or hyphens. For example, 342 (three hundred
 *          and forty-two) contains 23 letters and 115 (one hundred and fifteen)
 *          contains 20 letters. The use of "and" when writing out numbers is in
 *          compliance with British usage.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // letter counts for English words used for numbers
    // note we have "zero" but count its letters as 0 (for sane loops)
    int zero_to_nine[10];
    int ten_to_nineteen[10];
    int twenty_to_ninety[8];
    int hundred, thousand, and;
    
    int sum = 0;        // letter count
    int weird_sum = 0;  // sum for one through ninety-nine
    int i, j, k;        // indices
    char temp[10];      // store string read from text file
    
    // open file for read
    FILE * f = fopen("./pe017.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return EXIT_FAILURE;
    }
    
    // read and store letter counts from text file
    zero_to_nine[0] = 0;
    
    for (i = 1 ; i < 10 ; i++)
    {
        fscanf(f, "%s", temp);
        zero_to_nine[i] = strlen(temp);
    }
    
    for (i = 0 ; i < 10 ; i++)
    {
        fscanf(f, "%s", temp);
        ten_to_nineteen[i] = strlen(temp);
    }
    
    for (i = 0 ; i < 8 ; i++)
    {
        fscanf(f, "%s", temp);
        twenty_to_ninety[i] = strlen(temp);
    }
    
    fscanf(f, "%s", temp);
    hundred = strlen(temp);
    
    fscanf(f, "%s", temp);
    thousand = strlen(temp);
    
    fscanf(f, "%s", temp);
    and = strlen(temp);
    
    fclose(f);
    
    // one through nineteen don't really follow a pattern
    for (i = 0 ; i < 10 ; i++)
        weird_sum += zero_to_nine[i] + ten_to_nineteen[i];
    
    // twenty through ninety-nine do follow a pattern
    for (i = 0 ; i < 8 ; i++)       // tens place
        for (j = 0 ; j < 10 ; j++)  // ones place
            weird_sum += twenty_to_ninety[i] + zero_to_nine[j];
    
    // weird_sum now counts the letters of one to ninety-nine...
    // which repeats for one hundred, two hundred, ..., nine hundred
    sum = 10 * weird_sum;
    
    // the letters for "X hundred" repeat 100 times for each hundred (X = 1, 2, ..., 9)
    // the word "and" repeats 99 times for each hundred
    for (i = 1 ; i < 10 ; i++)
        sum += 100 * (zero_to_nine[i] + hundred);
    sum += 9 * 99 * and;
    
    // finally, one thousand and print
    sum += zero_to_nine[1] + thousand;
    printf("%i", sum);
    
    return EXIT_SUCCESS;
}

