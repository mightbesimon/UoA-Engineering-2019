/* ENGGEN131 (2019) - Lab 8 (24th - 27th September, 2019)
   EXERCISE THREE
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_PEOPLE 1000

int main(void)

{
	// These variables may be useful to you.  However, please feel free to
	// modify them, or create additional variables.
	int people[MAX_PEOPLE] = {0};
	int numPeople, totalAmount, currentAmount, index;
	int i;

	printf("Enter number of people: ");
	scanf("%d", &numPeople);

	printf("Enter money to distribute: ");
	scanf("%d", &totalAmount);

	currentAmount = 0;
	index = 0;
	while (totalAmount > currentAmount) {

		currentAmount ++;
		people[index] += currentAmount;
		totalAmount -= currentAmount;
		
		index ++;
		if (index == 5) {index = 0;}

	}

	people[index] += totalAmount;

	// Display the amount of money distributed to each person
	for (i = 0; i < numPeople; i++) {
		printf("%d ", people[i]);
	}

	printf("\n");


	return 0;
}
