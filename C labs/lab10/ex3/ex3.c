#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ENGGEN131 (2019) - Lab 10 (8th - 11th October, 2019)
   EXERCISE THREE - Word builder
*/

// The name of the dictionary file
#define DICTIONARY_FILE "wordlist.txt"

// Function prototype declarations
int IsSolution(char *word, char *letters);
int IsValidInput(char *s);

// =========================================================================================
// ================ Lab 10 - Exercise 3: Complete the IsSolution() function ================
// =========================================================================================
int IsSolution(char *word, char *letters)
{
	int len = strlen(word);
	if (len < 3) return 0;

	int contains, occurence[5] = {0};
	for (int i = 0; i < len; i++) {

		contains = 0;

		for (int j = 0; j < 5; j++) {
			if (word[i] == letters[j]) {
				contains = 1;
				occurence[j]++;
				if (occurence[j] > 1) return 0;
			}
		}

		if (!contains) return 0;
	}

	return 1;
}









// =========================================================================================
// =========================================================================================
// =========================================================================================
// =========================================================================================
// =================== YOUR SHOULD NOT MODIFY ANY CODE BELOW THIS LINE =====================
// =========================================================================================
// =========================================================================================
// =========================================================================================
// =========================================================================================
/*
This program reads all of the words from a dictionary file called "words.txt"
Each word is then passed to a function called IsSolution().  The IsSolution()
function returns true or false, depending on whether or not the word is a
solution to a puzzle.  All words in the dictionary that are solutions to the
puzzle are printed to the screen.
*/
int main(void)
{
	FILE *input;
	char word[100];
	char userword[100];
	int count;

	printf("\nWelcome to Lab 10 - \"Word builder\"\n\n");

	input = fopen(DICTIONARY_FILE, "r");
	count = 0;

	if(input == NULL) {
		printf(" -- File I/O Error...\n\n");
		printf("  - Sorry, it was not possible to open the file \"%s\".\n\n", DICTIONARY_FILE);
		printf("    If you are using Visual Studio, you should have created a new, empty\n");
		printf("    Win32 Console Application project.  Then you should have placed \n");
		printf("    the ex1.c and the wordlist.txt files into the folder that was made \n");
		printf("    when the project was created.  Finally, you should have added the  \n");
		printf("    ex1.c source file to the project before building and running. \n\n");
		printf("    If you have done these things, and you are still getting this error\n");
		printf("    message then please use the Developer Command Prompt.  This is 100%%\n");
		printf("    reliable.  Just put the source file (ex1.c) and the dictionary file\n");
		printf("    (wordlist.txt) into a folder and compile with: \"cl /W4 ex1.c\"\n\n");
		printf(" -- Good luck!\n\n");
		return 1;
	}

	printf("Please enter 5 lower case letters without any spaces (e.g. abcde): ");
	scanf("%s", userword);

	// Check if the input is valid
	if (!IsValidInput(userword)) {
		printf("\n -- User input Error...\n\n");
		printf("  - You entered: \"%s\"\n\n", userword);
		printf("  - Sorry, you need to enter a string that is exactly 5 characters long\n");
		printf("    and that consists of lower case alphabetic characters only.\n\n");
		fclose(input);
		return 1;
	}

	// The input is valid, so search for a solution
	printf("\nAll solutions:\n\n");
	while (fscanf(input, "%s", word) != EOF) {
		if (IsSolution(word, userword)) {
			printf("  %d) %s\n", count, word);
			count++;
		}
	}

	printf("\nThere are %d solutions to the puzzle.\n\n", count);
	fclose(input);

	return 0;
}

/*
This function checks whether or not the input string is a valid input for
the Word Builder game.  It must be of length 5, and it must consist only
of lower case letters.
*/
int IsValidInput(char *s)
{
	int i, len;

	// Calculate the length of the input string
	len = strlen(s);

	// The input must be exactly 5 characters
	if (len != 5) {
		return 0;
	}

	// The input must be lower case letters only
	for (i = 0; i < 5; i++) {
		if (s[i] < 97 || s[i] > 122) {
			return 0;
		}
	}
	return 1;
}

