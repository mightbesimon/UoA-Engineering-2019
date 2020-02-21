/* ENGGEN131 (2019) - Lab 7 (17th - 20th September, 2019)
   EXERCISE THREE
*/

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>   // This is needed for using sqrt() and pow()

int main(void)

{
	// declear variables //
	int n , result;
	double answer;

	// prompt //
	printf("\nwhich fibonacci number? =\t");	//largest = 46
	scanf ("%d" , &n);


	// formula
	answer = (pow(1+sqrt(5) , n) - pow(1-sqrt(5) , n)) / (pow(2 , n) * sqrt(5));
	result = (int) answer;


	// response //
	printf("\nthe %dth fibonacci number is =\t%d\n" , n , result);
	printf("%d" , result);


	return 0;
}
