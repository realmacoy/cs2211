/*
 * Q2.c --> gcc -std=c99 <filename> -o <outputfile>
 * Robert O'Neill - 250052733
 *
 */
#include <stdio.h>
#include <stdlib.h>

// prototypes
void print(int *a, int size);
void populate(int *a, int size);


/************************************************************
*   Main function
*************************************************************/
int main (void) {
	//variable declarations
	int size, *temp, *t;    

    // get size from user and verify it is correct.
    printf("Enter Size of magic square as a positive odd integer between (1 - 13):");
    scanf("%d", &size);
    if ( (size < 0) || ((size % 2) == 0) || (size > 13)) {
        printf("Error: User Malfunction...\n");
        exit(-1);
    }

    // create the array.	
	int magic_square[size][size];
    temp = &magic_square[0][0];
    for (t = temp; t < temp + (size * size); t++) {
        *t = 0;
    }

    // populate the array with correct numbers and then print it out.
    populate(temp, size);
    print(temp, size);
    
	return 0;
}

/************************************************************
* Print function
*************************************************************/
void print(int *a, int size) {
    int *t, i=0;
    for (t = a; t < a + (size * size); t++) {
        if (((i % size) == 0) && (i != 0)) printf("\n");
        printf("%3d\t", *t);
        i++;
    }
    printf("\n");
}

/************************************************************
* Populate function
*************************************************************/
void populate(int *a, int size) {
    int n = size * size;
    int prev, temp, loc;
    temp = (size / 2) % n;
    prev = temp;

    // this loop will fill all the empty slots.
    for (int i = 1; i < n + 1; i++) {   
        // if the spot is already taken             
        if (*(a + temp) != 0) {
            // loop through to find an empty spot for size-1 times     
            for (int k = 0; k < size-1; k++) {
                loc = (prev + size) % n;
                // if next spot is not empty, go to the next.
                if (*(a + loc) != 0) loc = (loc + size) % n; 
                // if it is empty, then insert there.
                else {                        
                    *(a + loc) = i;                                                                                             
                    prev = loc;
                    temp = loc;
                    break;
                }
            }            
        }
        // if its empty, add the number there.
        else {
            *(a + temp) = i;            
            prev = temp;
        }       
        
        // if last column
        if ((temp % (size)) == size-1) temp = temp - (size-1);        
        // if inside column
        else temp = temp + 1;        
        // if first row
        if ((temp % n) < size) temp = temp + (n - size);
        // not first row
        else temp = temp - size;        
    }        
}
