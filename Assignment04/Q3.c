/*
 * Q3.c --> gcc -std=c99 <filename> -o <outputfile>
 * Robert O'Neill - 250052733
 *
 */
#include <stdio.h>
#include <stdlib.h>

// prototypes
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *lonnie);


/************************************************************
*   Main function
*************************************************************/
int main (void) {
	int input, dollars, twenty=0, ten=0, five=0, two=0, one=0;
	// get size from user and verify it is correct.
	printf("Enter the dollar amount to be calculated:");
	scanf("%d", &input);
	if (input < 0) {
		printf("Error: User Malfunction...\n");
	    exit(-1);
	}
	dollars = input;
	// call pay_amount function.
	pay_amount(dollars, &twenty, &ten, &five, &two, &one);
	// output the results.
	printf("The minimum amount of currency needed is as follows.\n");
	printf("Twenties: %d\nTens: %d\nFives: %d\nToonies: %d\nLonnies: %d\n", twenty, ten, five, two, one);

	return 0;
}

/************************************************************
*   pay_amount function.
*************************************************************/
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *toonies, int *lonnie){
	int amt = dollars;
	// start calculations.
	*twenties = amt / 20;
	amt = amt % 20;
	*tens = amt / 10;
	amt = amt % 10;
	*fives = amt / 5;
	amt = amt % 5;
	*toonies  = amt / 2;
	amt = amt % 2;
	*lonnie  = amt / 1;
	amt = amt % 1;
}
