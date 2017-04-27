/********************************************************
*   Robert O'Neill - 250052733
*   cs2211 - Assignment 5 - operation_functions.h
*/

// structure complex_tag
struct complex_tag{
    double real;
    double imaginary;
};

// typedef Complex_type
typedef struct complex_type{
    double real;
    double imaginary;
}Complex_type;

// function prototypes
Complex_type complex_multiply(struct complex_tag num_one, struct complex_tag num_two);
int complex_division(struct complex_tag *num_one, struct complex_tag *num_two, struct complex_tag *num_three);
int complex_difference(struct complex_tag num1, struct complex_tag num2, struct complex_tag **num3, struct complex_tag **num4);
