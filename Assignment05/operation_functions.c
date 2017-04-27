/********************************************************
*   Robert O'Neill - 250052733
*   cs2211 - Assignment 5 - operation_functions.c
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

/******************************************************
*   complex_multiply - takes two parameters of type complex_tag
*   and returns the multiplication of them
*******************************************************/
Complex_type complex_multiply(struct complex_tag num_one, struct complex_tag num_two){
    Complex_type temp;
    temp.real = ( (num_one.real * num_two.real) - (num_one.imaginary * num_two.imaginary) );
    temp.imaginary = ( (num_two.real * num_one.imaginary) + (num_one.real * num_two.imaginary) );

    return temp;
}

/******************************************************
*   complex_division - takes three parameters of pointers to type complex_tag
*   and returns the division of the first two as the third.
*******************************************************/
int complex_division(struct complex_tag *num_one, struct complex_tag *num_two, struct complex_tag *num_three) {
    // variables    
    double ab = 0.0;
    ab = ((*num_one).imaginary * (*num_one).imaginary) + ((*num_two).imaginary * (*num_two).imaginary);

    if (ab == 0) return -2;
    // now do division
    (*num_three).real = ( (((*num_one).real * (*num_two).real) + ((*num_one).imaginary * (*num_two).imaginary)) / ab);
    (*num_three).imaginary = ( (((*num_two).real * (*num_one).imaginary) - ((*num_one).real * (*num_two).imaginary)) / ab );

    return 0;
}

/******************************************************
*   complex_difference - 
*******************************************************/
int complex_difference(struct complex_tag num1, struct complex_tag num2, struct complex_tag **num3, struct complex_tag **num4) {
    struct complex_tag *number3, *number4;

    // memory allocation
    number3 = malloc(sizeof(struct complex_tag));
    number4 = malloc(sizeof(struct complex_tag));
    // check to see if the memory was allocated properly.
    if (number3 == NULL) {
        printf("Error: malloc failed to allocate the memory.");
        return -1;
    }
    if ((number4 == NULL)) {
        printf("Error: malloc failed to allocate the memory.");
        free(number3);        
        return -1;
    }

    // do the addition
    number3->real = (num1.real + num2.real);
    number3->imaginary = (num1.imaginary + num2.imaginary);
    // do the difference
    number4->real = (num1.real - num2.real);
    number4->imaginary = (num1.imaginary - num2.imaginary);
    // set the 3rd and 4th parameters to numbers 3 and 4
    (**num3) = *number3;
    (**num4) = *number4;

    return 0;
}
