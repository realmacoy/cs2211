/*
 * Q1.c --> gcc -std=c99 -lm <filename> -o <outputfile>
 * Robert O'Neill - 250052733
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

// prototypes
double pi(unsigned int n);

/*************************************************************
 * Main function.
 *************************************************************/
int main (void) {
	// variable declarations.
	double pie, sum, avg, stdev = 0.0, p[10] = {0};
	long int input;
	unsigned long int n;
	time_t t;

	// get input from user and verify it is correct.
	printf("Enter a positive integer: ");
	scanf("%d", &input);
	if (input < 0) {
		printf("Error: User Malfunction...\n");
		exit(-1);
	}
		
	// seed the random number generator.
	srand((unsigned) time(&t));

	printf("When n = %u:\n", n);
	// run the test 10 times;
	for (int k = 0; k < 10; k++){
		pie = pi(n);
		sum += pie;
		p[k] = pie;
		printf("\tPI = %f\n", pie);
	}

	// calculate the mean;
	avg = sum / 10.0;
	printf("\tMean = %f\n", avg);

	// calculate the standard deviation.
	for (int i = 0; i < 10; ++i) {
		stdev += pow(p[i] - avg, 2);
	}
	stdev = sqrt(stdev/10);
	printf("\tStandard Deviation = %f\n", stdev);

	return 0;
}

/*************************************************************
 * Function to calculate pi, with n amount of iterations.
 *************************************************************/
double pi(unsigned int n){
	double x, y, pi;
	int inside = 0;

	for (int i = 0; i < n; i++) {
		// get random numbers for x and y
		x = (double) rand() / (double)RAND_MAX;
		y = (double) rand() / (double)RAND_MAX;

		// check where it lies
		if (((x*x) + (y*y)) <= 1){
			inside++;
		}
	}
	// calculate pi
	pi = (double) inside / (double) n;
	pi = pi * 4;

	return pi;
}
