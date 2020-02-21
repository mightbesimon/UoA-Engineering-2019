#include <stdio.h>
#include <math.h>

/* ENGGEN131 (2019) - Lab 8 (24th - 27th September, 2019)
   EXERCISE ONE (Tasks A and B)

  YOU MUST COMPLETE THE BODY OF THE TWO FUNCTIONS BELOW
  Just enter your code below, by completing the function bodies,
  and then run the program.  Your code will be marked automatically!
*/
/****************************************************************
- TASK A -
  You work for a flooring company and need to calculate the largest
  sized room for which the carpet you have will be sufficient to
  completely cover the floor.  Define a function called LargestRoom()
  which takes, as input, the area of carpet you have (in square metres).
  The function should return the side length (assuming a square room)
  of the largest room that you can carpet.
*/
int LargestRoom(int carpetArea)
{
	// You need to implement the correct code for this function.
	// You should start by deleting the incorrect statement below!
	return sqrt(carpetArea);
}

/****************************************************************
- TASK B -
  It's the Rugby World Cup!  You work for a sports betting company who
  wishes to compute odds for the gambling public.  The company has
  access to lots of score data for games played over the previous five
  years.  Define a function called WinningScore() which takes the final
  scores of the two teams for a single game as input.  The function must
  return the winning score of the game (that is, the higher of the two
  scores).  If the game ended in a draw (i.e. the scores are tied) then
  the function should return 0.  In some cases, the data is corrupted
  and records have negative values.  If either of the input scores is
  a negative number, then the function should return -1 to indicate
  this data corruption.
*/
int WinningScore(int score1, int score2)
{
	// You need to implement the correct code for this function.
	// You should start by deleting the incorrect statement below!
	int winningScore;
	if ((score1 >= 0) && (score2 >= 0)) {
		if (score1 == score2) {
			return 0;
		} else if (score1 > score2) {
			return score1;
		} else{
			return score2;
		}
	} else {
		return -1;
	}
}


/*
====================================================================
YOU CAN IGNORE EVERYTHING BELOW HERE
====================================================================
*/



































/*
====================================================================
====================================================================
====================================================================
YOU CAN IGNORE EVERYTHING BELOW HERE
====================================================================
====================================================================
====================================================================
*/

/*
Prototype declarations
*/
void TaskA(void);
void TaskB(void);

/*
The main function calls the testing functions
*/
int main(void)
{
	printf("****************************\n");
	printf("ENGGEN131 - Semester 2, 2019\nLab 8 (24th - 27th September, 2019)\n");
	printf("Hello!  Welcome to the second lab for the C Programming Module. \n");
	printf("Are you having a good week so far?  Hopefully this lab will brighten your day!\n");
	printf("****************************\n");
	printf("\nEXERCISE ONE\nMarking Task A and Task B...\n\n");
	TaskA();
	TaskB();
	return 0;
}

void TaskA(void)
{
	int tests[] = {0, 0, 1, 1, 2, 1, 3, 1, 4, 2, 5, 2, 6, 2, 700, 26, 8, 2, 9, 3, 10, 3, 20, 4, 35, 5, 60025, 245, 75, 8, 100, 10, 101, 10, 99, 9, 60024, 244, 123456, 351};
	int testSize = 2;
	int numTests = 20;
	int testsPassed = 0;
	int unmodified = 0;
	int i, result;

	for (i = 0; i < testSize*numTests; i+=testSize) {
		result = LargestRoom(tests[i]);
		if (result == tests[i+1]) {
			testsPassed++;
		} else if (result == -123456789 + tests[i]) {
			unmodified++;
		} else {
			printf("    - error: LargestRoom(%d) should give %d and not %d\n", tests[i], tests[i+1], result);
		}
	}

	if (numTests == testsPassed) {
		printf("Task A: EXCELLENT... ALL TESTS PASS!  You rock!  What a coding wizard!\n");
	} else if (numTests == unmodified) {
		printf("It looks like you haven't yet changed the code defined for Task A.\n");
		printf("Have a look at the definition of the LargestRoom() function, and \n");
		printf("replace the code that currently appears in that definition with  \n");
		printf("a correct solution to this task.  \n");
	} else {
		printf("Task A: NOT QUITE - %d of %d tests passed", testsPassed, numTests);
	}
	printf("\n");
}

void TaskB(void)
{
	int tests[] = {10, 7, 10, 10, 10, 0, 7, 10, 10, 12, 44, 44, -19, -36, -1, 12, -12, -1, -1, 1, -1, 20, 20, 0, 62, 24, 62, 24, 39, 39, 28, 19, 28, 17, 0, 17, 0, 26, 26, 27, -27, -1, 28, 28, 0, 0, 0, 0, -2, -40, -1, 21, 8, 21, 13, 40, 40, 31, 35, 35};
	int testSize = 3;
	int numTests = 20;
	int testsPassed = 0;
	int unmodified = 0;
	int i, result;

	for (i = 0; i < testSize*numTests; i+=testSize) {
		result = WinningScore(tests[i], tests[i+1]);
		if (result == tests[i+2]) {
			testsPassed++;
		} else if (result == -123456789 + tests[i] + tests[i+1]) {
			unmodified++;
		} else {
			printf("    - error: WinningScore(%d, %d) should give %d and not %d\n", tests[i], tests[i+1], tests[i+2], result);
		}
	}

	if (numTests == testsPassed) {
		printf("Task B: EXCELLENT... ALL TESTS PASS!  You rock!  Teach me your secrets!\n");
	} else if (numTests == unmodified) {
		printf("It looks like you haven't yet changed the code defined for Task B.\n");
		printf("Have a look at the definition of the WinningScore() function, and \n");
		printf("replace the code that currently appears in that definition with  \n");
		printf("a correct solution to this task.  \n");
	} else {
		printf("Task B: NOT QUITE - %d of %d tests passed", testsPassed, numTests);
	}
	printf("\n");
}

