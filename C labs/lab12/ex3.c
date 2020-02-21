#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
You need to complete the definition of the SolveTowersOfHanoi() function
*/
void SolveTowersOfHanoi(int n, char source, char destination, char spare)
{
	if (n == 1) {
		printf("move disk %d from %c to %c\n", n, source, destination);
	} else {
		SolveTowersOfHanoi(n - 1, source, spare, destination);
		printf("move disk %d from %c to %c\n", n, source, destination);
		SolveTowersOfHanoi(n - 1, spare, destination, source);
	}
}

int main(void)
{
	int numberOfDiscs;

	printf("Lab 12 - Towers of Hanoi\n");

	printf("How many discs? ");
	scanf("%d", &numberOfDiscs);

	SolveTowersOfHanoi(numberOfDiscs, 'A', 'C', 'B');

	return 0;
}

