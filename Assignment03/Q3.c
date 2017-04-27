/*
 * Q3.c
 *	Use -std=c99
 *  Created on: Oct 20, 2016
 *      Author: Robert O'Neill
 *      		250052733
 *      		Assignment 03 - Question #3
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
	bool valid = false;
	long double epsilon = 0.0, current = 0.0;
	long double e = 0.0;
	int count = 0;
	unsigned long long factorial = 1;
	// ask for epsilon until a valid number is entered.
	while (!valid) {
		printf("Enter an epsilon value: ");
		scanf("%Lf", &epsilon);
		if ((epsilon >= 1) || (epsilon <=0)) {
			valid = false;
		}
		else {
			valid = true;
		}
	}

	// Calculates the value of e repeatedly as long as current is bigger than epsilon
	do {
		current = 1.0 / factorial;
		e += current;
		count++;
		factorial = factorial * count;
	} while (current >= epsilon);

	// output
	printf("e: %.15Lf\n", e);
	printf("Number of times tried: %d\n", count);

	return 0;
}

