/*
ENGGEN131 Lab 11 - Exercise Three
Generate an ASCII histogram using data of exam scores read from file.

As described in the lab document, you may find it useful to define a function
called PrintXs() which takes one input and simply prints that many 'X' characters
in a single line.  The prototype declaration for this function is provided
below, just in case you decide to implement it!
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_STUDENTS 250

// Prototype declaration for PrintXs function - this will be useful to define!
void PrintXs(int howMany);

int main(void)
{
	FILE *inputFile;
	int buckets[11] = {0};

	printf("\nWelcome to Lab 11 - Exercise Two\n\n");

	// Open the input file for reading
	inputFile = fopen("large_input.txt", "r");

	if (inputFile == NULL) {
		printf("sorry could not open file\n");
		return -1;
	}

	int scores[MAX_STUDENTS] = {0};
	int score, idx = 0;

	while (fscanf(inputFile, "%d\n", &score) != EOF) {
		scores[idx] = score;
		idx++;
	}

	for (int i = 0; i < idx; i++) {
		buckets[scores[i] / 10]++;
	}




	int max = 0;
	for (int i = 0; i < 11; i++) {
		printf("%3d|", i * 10);
		PrintXs(buckets[i]);
	}

	printf("\n\n\n");



	for (int i = 0; i < 11; i++) {
		if (buckets[i] > max) max = buckets[i];
	}



	for (int i = max; i > 0; i--) {
		for (int j = 0; j < 11; j++) {
			if (buckets[j] >= i) {
				printf("X");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}

	printf("-----------\n");
	printf("01234567891\n");
	printf(" 0000000000\n");
	printf("          0\n");

	// Close the input file
	fclose(inputFile);

	return 0;
}

void PrintXs(int howMany)
{
	for (int i = 0; i < howMany; i++) {
		printf("X");
	}
	printf("\n");
}

