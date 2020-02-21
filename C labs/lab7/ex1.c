/* ENGGEN131 (2019) - Lab 7 (17th - 20th September, 2019)
   EXERCISE ONE
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)

{
	// housekeeping //
	char currencySymbol;
	int numberOfWinners;
	int totalCashPrize;
	double sharedPrize;

	
	// prompt //
	printf("\nenter curency symbol =\t\t");
	scanf ("%c" , &currencySymbol);
	printf("\nenter cash total (in %c) =\t" , currencySymbol);
	scanf ("%d" , &totalCashPrize);
	printf("\nenter number of winners =\t");
	scanf ("%d" , &numberOfWinners);

	
	sharedPrize = (double) totalCashPrize / numberOfWinners;		// prize each person

	
	// response //
	printf("\ntotal prize per winner =\t");
	printf("%c%f\n" , currencySymbol , sharedPrize);


	return 0;
}
