#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)

{
	int choice;

	printf("\n\nHello ENGGEN131!\n");
	printf("Please fix the bugs in this program.\n\n");

	printf("Have you programmed in C before ");
	printf("(0=no / 1=yes)? ");
	scanf("%d", &choice);

	if (choice == 1) {

		printf("\nThis should be easy then!\n\n");
		
	} else if (choice == 0) {

		printf("\nWell, you are now!\n\n");

	}


	return 0;
}
