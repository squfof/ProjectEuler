/* 
 * File:    pe019.c
 * Author:  Jason Gower
 * Created: July 20, 2017, 10:24 PM
 * 
 * Problem: You are given the following information, but you may prefer to do some
 *          research for yourself.
 *          
 *          1 Jan 1900 was a Monday.
 *          Thirty days has September,
 *          April, June and November.
 *          All the rest have thirty-one,
 *          Saving February alone,
 *          Which has twenty-eight, rain or shine.
 *          And on leap years, twenty-nine.
 *          A leap year occurs on any year evenly divisible by 4, but not on a
 *          century unless it is divisible by 400.
 * 
 *          How many Sundays fell on the first of the month during the twentieth
 *          century (1 Jan 1901 to 31 Dec 2000)?
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year = 1900;        // keep track of year
    int day_of_week = 1;    // Jan 1, 1900 was a Monday (Sunday = 0, Monday = 1, etc)
    int i = 0;              // index that counts month
    int j = 0;              // index that counts day in month
    int count = 0;          // only count Sundays on 1st of month starting in 1901
    
    while (year < 2001)
    {
        // check if leap year
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            days_in_month[1] = 29;
        else
            days_in_month[1] = 28;
        
        // rip through months of year
        for (i = 0 ; i < 12 ; i++)
        {
            // check if it's Sunday and in 1901 or later
            if (year > 1900 && day_of_week == 0)
                count++;
            
            // rip through days of month
            for (j = 0 ; j < days_in_month[i] ; j++)
            {
                day_of_week++;
                day_of_week %= 7;
            }
        }
        year++;
    }
    
    printf("%i", count);
    
    return EXIT_SUCCESS;
}

