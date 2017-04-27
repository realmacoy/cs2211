/********************************************************
*   Robert O'Neill - 250052733
*   cs2211 - Assignment 5 - operation.c
*/
// include guards
#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif
#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#include "operation_functions.h"

int main (int argc, char *argv[]) {
    struct complex_tag number1, number2, division_result, sum_results, diff_results,
        *sum, *diff;
    Complex_type multiply_result;
    int division, difference;
    sum = &sum_results;
    diff = &diff_results;

    // check to see if right amount of command arguments.   
    if (argc != 5) {
        printf("Usage: Enter 4 seperate numbers.\n");
        return 1;
    }

   // give the complex_tag objects their values
    number1.real = atof(argv[1]);
    number1.imaginary = atof(argv[2]);
    number2.real = atof(argv[3]);
    number2.imaginary = atof(argv[4]);

    // call the functions and store the results.
    multiply_result = complex_multiply(number1, number2);
    division = complex_division(&number1, &number2, &division_result);
    difference = complex_difference(number1, number2, &sum, &diff);

    //outputs the results
    printf("**********************************************************************\n");
    printf("*                         Operation                                  *\n");
    printf("**********************************************************************\n");
    printf("Complex Number 1: %.2f + i(%.2f)\n", number1.real, number1.imaginary);
    printf("Complex Number 2: %.2f + i(%.2f)\n", number2.real, number2.imaginary);
    printf("\t Multiplication\n");
    printf("Results of Multiplication: %.2f + i(%.2f)\n", multiply_result.real, multiply_result.imaginary);
    printf("\t Division\n");
    // check if division was done.
    if (division == 0) {
        printf("Results of Division: %.2f + i(%.2f)\n", division_result.real, division_result.imaginary);
    }
    else {
        printf("Division could not be performed.\n");
    }
    printf("\t Difference\n");
    // check if difference was done.
    if (difference == 0) {
        printf("Results of Summing: %.2f + i(%.2f)\n", sum_results.real, sum_results.imaginary);
        printf("Results of Difference: %.2f + i(%.2f)\n", diff_results.real, diff_results.imaginary);
    }
    else {
        printf("Difference could not be performed.\n");   
    }
    printf("\n");


    return 0;
}
