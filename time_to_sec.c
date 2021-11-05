/*
 * time_to_sec.c
 *
 *  Created on: Jul 20, 2016
 *      Author: leune (original), edited by Will Torres
 */
// appropriate #include statements
#include <stdio.h>

/* Convert a time interval specified in hours, minutes and seconds to
 * seconds.
 * Parameters:
 *     hours, minutes, seconds: input time elements
 * Preconditions:
 *     0 <= minutes < 60
 *     0 <= seconds < 60 
 * Return:
 *     number of seconds in the interval
 */
unsigned int time_to_sec(unsigned int hours, unsigned int minutes, unsigned int seconds) {
        int sec = (hours * 3600) + (minutes * 60) + seconds;
        
        return sec;
}

/* Print a formatted representation of the calculation
 * Parameters:
 *     hours, minutes, seconds: input time elements
 * Postcondition:
 *     Function will write the calculation to standard output.
 */
void format_seconds(unsigned int hours, unsigned int minutes, unsigned int seconds) {
	// call the 'time_to_sec' function via the integer 'sec'
    int sec = time_to_sec(hours, minutes, seconds);

    printf("\n%d hours, %d minutes, and %d seconds is equal to %d.",
             hours, minutes, seconds, sec);
}

int main(void) {
    format_seconds(4, 13, 20);
    format_seconds(8, 0, 0);
    format_seconds(1, 30, 0);
    return 0;
}