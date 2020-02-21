/* ENGGEN131 (2019) - Lab 8 (24th - 27th September, 2019)
   EXERCISE TWO
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 100

int main(void)

{
	// variable declearation
	int bits[MAX_SIZE];
	int numBits;
	int index;

	// prompt //
	printf("enter a number = ");
	scanf ("%d" , &numBits);

	// dec to bin
	index = 0;
	while (numBits > 0) {

		bits[index] = numBits % 2;
		numBits /= 2;
		index ++;

	}

	// terminal output
	for (int i = index - 1 ; i >= 0 ; i--) {

		printf("%d" , bits[i]);

	}

	printf("\n");


	return 0;
}

