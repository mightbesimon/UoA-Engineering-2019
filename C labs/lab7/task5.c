#include <stdio.h>

int main(void)

{
/* Initialise resistors */
	double r1 = 5;
	double r2 = 10;
	double r3 = 2;

	double resistance;

/* Calculate circuit resistance */
	resistance = 1/(1/r1 + 1/r2) + r3;

	printf("%f ohms", resistance);


	return 0;
}