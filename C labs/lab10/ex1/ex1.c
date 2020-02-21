#define _CRT_SECURE_NO_WARNINGS

/* ENGGEN131 (2019) - Lab 10 (8th - 11th October, 2019)
   EXERCISE ONE - Crossword helper
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************
You must complete the WordMatchesPattern function below,
so that it returns true only if the word matches the pattern
*******************************************************/
int WordMatchesPattern(char *word, char *pattern)
{
	int idx = 0;

	while ((word[idx] != '\0') && (pattern[idx] != '\0')) {
		
		if ((pattern[idx] != '-') && (word[idx] != pattern[idx])) {
			return 0;
		}

		idx++;
	}

	if (word[idx] == pattern[idx]) {
		return 1;
	}

	return 0;

}


/**************************************************************************************
YOU DO NOT NEED TO MODIFY ANY CODE BELOW HERE.
The code below defines the main() function that *calls* the WordMatchesPattern() function
you must define above.  Feel free to examine the code below, but you should not make
any changes to the following code.
**************************************************************************************/
int main(void)
{
	FILE *input;
	char word[100];
	char pattern[100];
	int count;

	input = fopen("wordlist.txt", "r");
	count = 0;

	if (input == NULL) {
		printf("Could not open file.");
	} else {
		printf("Enter pattern: ");
		scanf("%s", pattern);

		while (fscanf(input, "%s", word) != EOF) {
			if (WordMatchesPattern(word, pattern)) {
				printf("%s\n", word);
				count++;
			}
		}
		printf("\n%d matches", count);
	}

	return 0;
}

