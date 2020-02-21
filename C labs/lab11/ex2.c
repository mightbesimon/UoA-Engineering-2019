#define _CRT_SECURE_NO_WARNINGS

/* ENGGEN131 - 2019 - Lab 11 */
/* Decreasing values */

#include <stdio.h>

#define MAX_VALUES 1000


// This program prompts the user to enter a series of integer values, terminated by the
// value -1.  It then generates an output file which contains all entered values, space
// separated, sorted in decreasing order
int main(void)
{
	// Some variables (that you might find useful) have been declared for you:
	int values[MAX_VALUES] = {0};
	int numValues = 0;
	int value = 0;
	FILE *outputFile;


	// Open the output file for writing
	outputFile = fopen("output.txt", "w");




	// Read all input values from the user, until the terminating -1
	printf("\nenter positive integers (-1 to end) = ");

	do {

		scanf ("%d", &value);

		if (value != -1) {
			values[numValues] = value;
			numValues++;
		}

	} while (value != -1);




	// Sort the values into decreasing order (see the Lab Preparation exercises)
	int temp;
	for (int i = 0; i < numValues - 1; i++) {
		for (int j = 0; j < numValues - 1 - i; j++) {
			if (values[j] < values[j + 1]) {
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
		}
	}





	// Write the values to file (and close the file using fclose(fp))
	for (int i = 0; i < numValues; i++) {
		fprintf(outputFile, "%d ", values[i]);
	}

	fclose(outputFile);



	return 0;
}

