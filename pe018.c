/* 
 * File:    pe018.c
 * Author:  Jason Gower
 * Created: July 20, 2017, 8:07 PM
 * 
 * Problem: By starting at the top of the triangle below and moving to adjacent
 *          numbers on the row below, the maximum total from top to bottom is 23
 *          (using path 3 -> 7 -> 4 -> 9).
 *             3
 *            7 4
 *           2 4 6
 *          8 5 9 3
 *          That is, 3 + 7 + 4 + 9 = 23.
 * 
 *          Find the maximum total from top to bottom of the triangle below
 *          (contained in pe018.txt).
 * 
 *          Note 1: As there are only 16384 routes, it is possible to solve this
 *          problem by trying every route. However, Problem 67, is the same challenge
 *          with a triangle containing one-hundred rows; it cannot be solved by
 *          brute force, and requires a clever method! ;o)
 * 
 *          Note 2: It was not immediately obvious to me what the trick is so I
 *          went ahead and did brute-force. I'll keep thinking about it!
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 15

int main(void)
{
    unsigned int * triangle[MAX];   // store numbers from triangle
    unsigned int i, j;              // indices
    unsigned int ch10, ch01;        // tens and ones place of numbers
    int max_path_sum = 0;           // store max path sum so far
    int temp_path_sum;              // current path sum under consideration
    int position;                   // "x" coordinate in triangle
    int delta;                      // left/right movement when moving down a row
    
    // open file for read
    FILE * f = fopen("./pe018.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return EXIT_FAILURE;
    }
    
    // read in and store numbers from text file
    for (i = 0 ; i < MAX ; i++)
    {
        triangle[i] = calloc(i + 1, sizeof(int));
        for (j = 0 ; j <= i ; j ++)
        {
            ch10 = fgetc(f);
            ch01 = fgetc(f);
            fgetc(f);
            triangle[i][j] = 10 * (ch10 - '0') + 1 * (ch01 - '0');      
        }
    }
    
    // to get the movement pattern, look at bits of a number between 0 and 2^MAX - 1
    // it's easier to think of the triangle as a right triangle extending to the right
    // so either move straight down (delta = 0) or down and right (delta = 1)
    for (i = 0 ; i < (int) pow(2, MAX - 1) ; i++)
    {
        temp_path_sum = triangle[0][0];
        position = 0;
        for (j = 1 ; j < MAX ; j++)
        {
            delta = (int) (0x01 & (i >> (j - 1)));
            position += delta;
            temp_path_sum += triangle[j][position] ;
        }
        if (temp_path_sum > max_path_sum)
            max_path_sum = temp_path_sum;
    }
    
    printf("%i", max_path_sum);
    
    return EXIT_SUCCESS;
}

