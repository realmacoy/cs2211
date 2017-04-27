/*
 * Q1.c
 *
 *  Created on: Oct 19, 2016
 *      Author: Robert O'Neill
 *   			250052733
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	// integer array to store the three values in
	int values[2];
	int min, hr, new_time;
	// boolean to test for valid entry
	bool valid = false;

	// loop to run while the number entered is not valid.
	do {
		// asks for and takes input from user. Saving it in the first two spaces of the values array.
		printf("Please enter two integers separated by a space: ");
		scanf("%d%d", &values[0], &values[1]);
		// checks to see if the time of day is less than 2359 and not negative
		if ((values[0] < 2359) && (values[0] >= 0)) {
			// checks to see if the minutes of time of day are less than 60
			if ((values[0] % 100) < 60) {
				// checks to see if the duration has minutes less than 60
				if (abs((values[1]) % 100) < 60) {
					valid = true;
				}
			}
		}
		else {
			valid = false;
		}
	} while (!valid);

	// creates the new time
	new_time = values[0] + values[1];
	min = new_time % 100;
	hr = new_time / 100;

	// if the minutes is > 59, add 1 to hour and get minutes remainder
	if (min > 59) {
		hr += 1;
		min = min % 60;
	}
	// else if minutes is less than 0, minus 1 from hour and get minutes leftover subtracted from 60
	else if (min < 0) {
		hr -= 1;
		min = (60 - abs(min)) % 60;
	}
	// if hr is 24 or greater, get hr mod 24 to set it in 24 hour range
	if (hr >= 24) {
		hr = hr % 24;
	}
	// else if hr is less than 0, take the absolute of hr and add 24, then set it to mod 24 to get it in range.
	else if (hr < 0) {
		while (hr < 0) {
			hr = (24 - abs(hr)) % 24;
		}
	}

	// Prints out the new time, with 2 hr digits and 2 minute digits.
	printf("New Time: %02d%02d\n", hr, min);

	return 0;
}
