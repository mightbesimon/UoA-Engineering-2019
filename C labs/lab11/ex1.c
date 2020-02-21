#define _CRT_SECURE_NO_WARNINGS

/* ENGGEN131 - 2019 - Lab 11 */
/* Word Chain */
/* A word game where each player must substitute one letter in a word to generate a new word */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* The dictionary we are using has fewer than 70000 words */
#define MAX_WORDS 70000
#define WORD_LENGTH 35

/* Function prototype declarations */
void RemoveFromWordList(int index, char *word);
int GetStartingWordIndex(void);
int GetNextWord(int computer, char *word);
int WordsRemaining(char *word, int cheat);
int RandomBetween(int a, int b);
void InitialiseWordList(int wordLength);
int GetWordFromUser(void);
int OneLetterDifference(char *word1, char *word2);
int PlayOneTurn(int cheat, char *word, int computerTurn);
int GetWordLengthForGame();
int GetCheatChoice();

/* GLOBAL VARIABLES - the list of words of a given length, and the number of words in the list */
char wordList[MAX_WORDS][WORD_LENGTH];
int numWords;

/* ********************************************************************************* */
/* ***    YOU NEED TO COMPLETE THE DEFINITION OF THE FOLLOWING FUNCTION          *** */
/* ***    Feel free to read through the main() function first so you understand  *** */
/* ***    how the program works.                                                 *** */
/* ********************************************************************************* */

/* Returns true if there is exactly one letter difference between the two words */
int OneLetterDifference(char *word1, char *word2)
{
	// You only need to complete this function definition
	int idx = 0, diffCount = 0;
	while ((word1[idx] != '\0') && (word2[idx] != '\0')) {
		if (word1[idx] != word2[idx]) diffCount++;
		idx++;
	}
	
	if (diffCount == 1) {
		return 1;
	}

	return 0;
}




/* ********************************************************************************* */
/* ***    YOU ARE WELCOME TO READ THROUGH THE REST OF THE PROGRAM, HOWEVER YOU   *** */
/* ***    DO NOT NEED TO MODIFY ANYTHING BELOW THIS LINE                         *** */
/* ********************************************************************************* */
/* Prompts the user to enter a word and confirms that it exists amongst the remaining words */
int GetWordFromUser(void)
{
	int i;
	char word[WORD_LENGTH];

	printf("\nYour word: ");
	scanf("%s", word);

	for (i = 0; i < numWords; i++) {
		if (strcmp(wordList[i], word) == 0) {
			return i;
		}
	}

	return -1;
}

/* The main function for the proram */
int main(void)
{
	int wordLength, wordIndex;
	char word[WORD_LENGTH];
	int gameOver = 0;
	int computerTurn = 0;
	int cheat = 0;

	// Set the seed for the random number generator
	srand((unsigned int)time(NULL));

	// Get word length for game
	wordLength = GetWordLengthForGame();

	// Check if the user wants to see a list of allowed words
	cheat = GetCheatChoice();

	// Initialise list of words
	InitialiseWordList(wordLength);

	// Choose a starting word for the game
	wordIndex = GetStartingWordIndex();
	printf("Starting word: %s\n\n", wordList[wordIndex]);
	RemoveFromWordList(wordIndex, word);

	// Continue playing, alternating players, until the game is over
	while (!gameOver) {
		gameOver = PlayOneTurn(cheat, word, computerTurn);
		computerTurn = 1 - computerTurn;
	}

	return 0;
}

/* Process the turn for one player, either the computer or the human.  This function returns true
   if the game is over, otherwise it returns false */
int PlayOneTurn(int cheat, char *word, int computerTurn)
{
	int wordsRemaining, wordIndex;

	wordsRemaining = WordsRemaining(word, cheat && !computerTurn);
	if (cheat) {
		printf("Words remaining: %d\n", wordsRemaining);
	}
	if (wordsRemaining == 0) {
		printf("No more words... game over.\n");
		if (computerTurn) {
			printf("\nYOU WIN!!\n");
		} else {
			printf("\nComputer wins.\n");
		}
		return 1;
	} else {
		wordIndex = GetNextWord(computerTurn, word);
		if (computerTurn) {
			printf("\nComputer word: %s\n\n", wordList[wordIndex]);
		}
		RemoveFromWordList(wordIndex, word);
	}
	return 0;
}

/* Prompts the user to enter the word length for the game */
int GetWordLengthForGame()
{
	int input;
	printf("Enter length of words: ");
	scanf("%d", &input);
	return input;
}

/* Prompts the user if they would like to cheat */
int GetCheatChoice()
{
	char input[WORD_LENGTH];
	printf("Do you want to cheat? (yes/no): ");
	scanf("%s", input);
	if (input[0] == 'y' || input[0] == 'Y')
		return 1;
	else
		return 0;
}

/* Removes a word from the list of available words */
void RemoveFromWordList(int index, char *word)
{
	strcpy(word, wordList[index]);
	strcpy(wordList[index], wordList[numWords-1]);
	numWords--;
}

/* Selects a random index for the starting word */
int GetStartingWordIndex(void)
{
	return RandomBetween(0, numWords-1);
}

/* Processes either the computer or the humans choice.  The computer chooses a random
   word from those available, and the humans words is validated */
int GetNextWord(int computer, char *word)
{
	int indices[MAX_WORDS] = {0};
	int numIndices = 0;
	int i;

	if (computer) {
		for (i = 0; i < numWords; i++) {
			if (OneLetterDifference(wordList[i], word)) {
				indices[numIndices] = i;
				numIndices++;
			}
		}

		if (numIndices == 0)
			return -1;
		else
			return indices[RandomBetween(0, numIndices-1)];
	} else {
		do {
			i = GetWordFromUser();
		} while ((i == -1) || (OneLetterDifference(wordList[i], word) != 1));
		return i;
	}
}

/* Calculates how many valid words are remaining in the list.  If this function
   returns 0 then the game will be over */
int WordsRemaining(char *word, int cheat)
{
	int indices[MAX_WORDS] = {0};
	int numIndices = 0;

	int i;
	if (cheat) {
		printf("[ ");
	}
	for (i = 0; i < numWords; i++) {
		if (OneLetterDifference(wordList[i], word)) {
			if (cheat) {
				printf("%s ", wordList[i]);
			}
			indices[numIndices] = i;
			numIndices++;
		}
	}
	if (cheat) {
		printf("]\n");
	}

	return numIndices;
}

/* Returns a random integer between a and b inclusive */
int RandomBetween(int a, int b)
{
	return (rand() % (b-a+1)) + a;
}

/* Reads all of the words from the dictionary file, and stores those of the appropriate length into memory */
void InitialiseWordList(int wordLength)
{
	FILE *inputFile;
	char word[WORD_LENGTH];

	inputFile = fopen("wordlist.txt", "r");
	numWords = 0;

	if(inputFile == NULL) {
		printf("Could not open file.");
		exit(EXIT_FAILURE);
	}

	while (fscanf(inputFile, "%s", word) != EOF) {
		if ((int)strlen(word) == wordLength) {
			strcpy(wordList[numWords], word);
			numWords++;
		}
	}

	printf("\nThere are %d words of length %d.\n\n", numWords, wordLength);
}






