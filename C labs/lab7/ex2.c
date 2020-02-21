/* ENGGEN131 (2019) - Lab 7 (17th - 20th September, 2019)
   EXERCISE TWO
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)

{
	int capacityLarge , capacitySmall , numItems , numLarge , numSmall;

	// prompt //
	printf("\nenter capacity of large containers =\t");
	scanf ("%d" , &capacityLarge);
	printf("\nenter capacity of small containers =\t");
	scanf ("%d" , &capacitySmall);
	printf("\nenter number of items =\t");
	scanf ("%d" , &numItems);


	// calculate
	numLarge = numItems / capacityLarge;
	numItems %= capacityLarge;
	numSmall = numItems / capacitySmall;
	numItems %= capacitySmall;


	// response //
	printf("\nallocated:\n");
	printf("\n - large =\t");
	printf("%d\n" , numLarge);
	printf("\n - small =\t");
	printf("%d\n" , numSmall);
	printf("\n - scrap =\t");
	printf("%d\n" , numItems);


	return 0;
}
