/*
 * Q2.c
 *	Use -std=c99
 *  Created on: Oct 20, 2016
 *      Author: Robert O'Neill
 *      		250052733
 *      		Assignment 03 - Question #2
 */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


int main (){
	bool valid = false;
    float amt = 0.0, rate = 0.0, payment = 0.0, balance = 0.0;
    float prevBalance = 0.0, interest = 0.0;
    int months = 0;
    // get input until it is all valid.
	do {
        printf("Enter amount of loan: ");
        scanf("%f", &amt);
        printf("Enter yearly interest rate: ");
        scanf("%f", &rate);
        printf("Enter monthly payment: ");
        scanf("%f", &payment);
        printf("Enter number of payments: ");
        scanf("%d", &months);
        if ((amt < 0) || (rate < 0) || (payment < 0) || (months < 0)) {
            valid = false;
        }
		else valid = true;
	} while (!valid);

	// do the calculations
	balance = amt;
	for (int i = 0; i < months; i++) {
		if (balance < 0) {
			break;
		}
		prevBalance = balance;
		interest = balance * ((rate/12)/100);
		balance = balance + interest - payment;
		if (balance < 0) {
			printf("The last payment was $%.2f, there are no more payments.", prevBalance + interest);
			break;
		}
		printf("Balance after %d months is: $%.2f\n", (i+1), balance);
	}
	return 0;
}
