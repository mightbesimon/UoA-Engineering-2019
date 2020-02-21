/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/*
Program to test the functions defined in the "project.c" source file
*/
#include "project.h"

void MyTestFunction(int task)
{
	// An example of code that you could use to test Task One.
	// You should write additional tests of your own
	if (task == 1) {
		printf("\nTESTING TASK ONE:\n");
		printf("=================\n");
		printf("   Time worked = %d (should be 60)\n", TimeWorked(1, 0, 2, 0));
		printf("   Time worked = %d (should be 779)\n", TimeWorked(55, 11, 42, 12));
		printf("   Time worked = %d (should be 0)\n", TimeWorked(33, 33, 33, 33));
	}

	// An example of code that you could use to test Task Two.
	// You should write additional tests of your own
	if (task == 2) {
		printf("\nTESTING TASK TWO:\n");
		printf("=================\n");
		printf("   Address = %d (should be 997)\n", WarehouseAddress(1000));
		printf("   Address = %d (should be 47)\n", WarehouseAddress(50));
		printf("   Address = %d (should be 104383)\n", WarehouseAddress(104393));
		printf(" * Address = %d (should be 3)\n", WarehouseAddress(5));
	}

	// An example of code that you could use to test Task Three.
	// You should write additional tests of your own
	if (task == 3) {
		printf("\nTESTING TASK THREE:\n");
		printf("=================\n");
		char message1[MAX_ARRAY_SIZE] = "Discount today only!";
		char message2[MAX_ARRAY_SIZE] = "Hurry, hurry, hurry...";
		char message3[MAX_ARRAY_SIZE] = "Good luck!";
		Advertise(message1);
		Advertise(message2);
		Advertise(message3);
		printf("   Advertise = \"%s\" (should be: \"iscount today only!D\")\n", message1);
		printf("   Advertise = \"%s\" (should be: \"urry, hurry, hurry...H\")\n", message2);
		printf("   Advertise = \"%s\" (should be: \"ood luck!G\")\n", message3);
	}

	// An example of code that you could use to test Task Four.
	// You should write additional tests of your own
	if (task == 4) {
		printf("\nTESTING TASK FOUR:\n");
		printf("=================\n");
		int values1[MAX_ARRAY_SIZE] = {3, 7, 5, 6, 3, 4, 8, 4, 5, 8, 12, 11};
		int values2[MAX_ARRAY_SIZE] = {6, 17, 6, 6, 6, 6, 12, 12, 17, 10000};
		int values3[MAX_ARRAY_SIZE] = {5, 4, 3, 2, 1};
		printf("   Winning bid = %d (should be 6)\n", WinningBid(values1, 12));
		printf("   Winning bid = %d (should be 10000)\n", WinningBid(values2, 10));
		printf("   Winning bid = %d (should be 1)\n", WinningBid(values3, 5));
	}

	// An example of code that you could use to test Task Five.
	// You should write additional tests of your own
	if (task == 5) {
		printf("\nTESTING TASK FIVE:\n");
		printf("=================\n");
		char box1[MAX_ARRAY_SIZE] = {0};
		char box2[MAX_ARRAY_SIZE] = {0};
		char box3[MAX_ARRAY_SIZE] = {0};
		BoxDesign(box1, 12, 5);
		BoxDesign(box2, 15, 15);
		BoxDesign(box3, 4, 4);
		printf("Box 1 = \n%s\n", box1);
		printf("Box 2 = \n%s\n", box2);
		printf("Box 3 = \n%s\n", box3);
		printf("Checking string lengths = %d %d %d\n", (int)(strlen(box1)), (int)(strlen(box2)), (int)(strlen(box3)));
	}

	// An example of code that you could use to test Task Six.
	// You should write additional tests of your own
	if (task == 6) {
		printf("\nTESTING TASK SIX:\n");
		printf("=================\n");
		int i, j;
		int warehouse1[WAREHOUSE_SIZE][WAREHOUSE_SIZE] = {
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 2, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		};
		int warehouse2[WAREHOUSE_SIZE][WAREHOUSE_SIZE] = {
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		};
		int warehouse3[WAREHOUSE_SIZE][WAREHOUSE_SIZE] = {
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 2, 0, 0, 1, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		};
		int warehouse4[WAREHOUSE_SIZE][WAREHOUSE_SIZE] = {
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 2, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		};
		int warehouse5[WAREHOUSE_SIZE][WAREHOUSE_SIZE] = {
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 2, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
		};

		WorkerRoute(warehouse1);
		WorkerRoute(warehouse2);
		WorkerRoute(warehouse3);
		WorkerRoute(warehouse4);
		WorkerRoute(warehouse5);

		printf("Worker route 1: \n");
		for (i = 0; i < WAREHOUSE_SIZE; i++) {
			for (j = 0; j < WAREHOUSE_SIZE; j++) {
				printf("%d", warehouse1[i][j]);
			}
			printf("\n");
		}
		printf("\nWorker route 2: \n");
		for (i = 0; i < WAREHOUSE_SIZE; i++) {
			for (j = 0; j < WAREHOUSE_SIZE; j++) {
				printf("%d", warehouse2[i][j]);
			}
			printf("\n");
		}
		printf("\nWorker route 3: \n");
		for (i = 0; i < WAREHOUSE_SIZE; i++) {
			for (j = 0; j < WAREHOUSE_SIZE; j++) {
				printf("%d", warehouse3[i][j]);
			}
			printf("\n");
		}
		printf("\nWorker route 4: \n");
		for (i = 0; i < WAREHOUSE_SIZE; i++) {
			for (j = 0; j < WAREHOUSE_SIZE; j++) {
				printf("%d", warehouse4[i][j]);
			}
			printf("\n");
		}
		printf("\nWorker route 5: \n");
		for (i = 0; i < WAREHOUSE_SIZE; i++) {
			for (j = 0; j < WAREHOUSE_SIZE; j++) {
				printf("%d", warehouse5[i][j]);
			}
			printf("\n");
		}


	}

}


//********************************************************************
//********************************************************************
// REMEMBER:
// FOR THE PROJECT, YOU ARE ONLY SUBMITTING THE MakeMove() FUNCTION
// ABOVE (AND ANY HELPER FUNCTIONS THAT YOU HAVE DEFINED).  REMEMBER
// TO PLACE THE MakeMove() FUNCTION (AND ANY HELPER FUNCTIONS) INTO
// THE project.c FILE BEFORE SUBMISSION.
//********************************************************************
//********************************************************************

/* Function prototype declarations */
void PrintWarehouse(int warehouse[10][10]);
char GetMove(void);

// Print a welcome message, and enter the main game loop.
int main(void)
{
	/* An example warehouses for testing Task 7 */
	int warehouse7[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 5, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	/* An example warehouses for testing Task 8 */
	int warehouse8[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 5, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 3, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	/* An example warehouses for testing Task 9 */
	int warehouse9[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 5, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 3, 3, 3, 3, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	/* An example warehouses for testing Task 10 */
	/*int warehouse10[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
		{1, 2, 5, 3, 0, 0, 1, 1, 1, 1},
		{1, 1, 1, 0, 3, 2, 1, 1, 1, 1},
		{1, 2, 1, 1, 3, 0, 1, 1, 1, 1},
		{1, 0, 1, 0, 2, 0, 1, 1, 1, 1},
		{1, 3, 0, 4, 3, 3, 2, 1, 1, 1},
		{1, 2, 0, 0, 2, 0, 0, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};*/

	/* Optional level for Task 10 */
	int warehouse10[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
		{1, 1, 1, 0, 3, 1, 0, 0, 1, 1},
		{1, 2, 0, 0, 2, 2, 0, 0, 0, 1},
		{1, 1, 1, 0, 1, 0, 3, 3, 3, 1},
		{1, 0, 0, 3, 0, 0, 1, 5, 2, 1},
		{1, 2, 0, 0, 0, 1, 1, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
	int task = -1;
	int i, j;

	// The main warehouse to be used in the game
	int warehouse[10][10];

	printf("ENGGEN131 2019 - C Project...\n");
	printf(" _____ _            _    _                _                          \n");
	printf("|_   _| |          | |  | |              | |                         \n");
	printf("  | | | |__   ___  | |  | | __ _ _ __ ___| |__   ___  _   _ ___  ___ \n");
	printf("  | | | \'_ \\ / _ \\ | |/\\| |/ _` | \'__/ _ \\ \'_ \\ / _ \\| | | / __|/ _ \\\n");
	printf("  | | | | | |  __/ \\  /\\  / (_| | | |  __/ | | | (_) | |_| \\__ \\  __/\n");
	printf("  \\_/ |_| |_|\\___|  \\/  \\/ \\__,_|_|  \\___|_| |_|\\___/ \\__,_|___/\\___|\n");
	printf("\nEnter the number of the task that you would like to test:\n\n");
	printf("  1 - 6  = this will execute the code in MyTestFunction()\n");
	printf("  7 - 10 = this will play the Warehouse game\n");
	while (task < 1 || task > 10) {
		printf("\nWhat task would you like to test (1, 2, 3, 4, 5, 6, 7, 8, 9 or 10)? ");
		scanf("%d", &task);
	}

	printf("\n\nOK, testing task %d!\nGood luck!\n\n", task);

	if (task < 7) {
		MyTestFunction(task);
	} else {
		printf("\nThe Warehouse game!");
		printf("\nUse the keys 'w', 'a', 's', 'd' to move the worker (X)\n");
		printf("Push the boxes (O) onto the targets (*) to complete your shift!\n");

		for (i = 0; i < 10; i++) {
			for (j = 0; j < 10; j++) {
				if (task == 7)
					warehouse[i][j] = warehouse7[i][j];
				else if (task == 8)
					warehouse[i][j] = warehouse8[i][j];
				else if (task == 9)
					warehouse[i][j] = warehouse9[i][j];
				else
					warehouse[i][j] = warehouse10[i][j];
			}
		}

		// The main game loop - continue to make moves until the game is over
		int gameOver = 0;
		PrintWarehouse(warehouse);
		while (!gameOver) {
			gameOver = MakeMove(warehouse, GetMove());
			PrintWarehouse(warehouse);
			if (gameOver) {
				printf("\nCongratulations! \nYour work here is done!\n\n");
			}
		}
	}

	return 0;
}

/* A simple function for displaying the cave. */
void PrintWarehouse(int warehouse[10][10])
{
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (warehouse[i][j] == 0) {
				printf(" ");
			} else if (warehouse[i][j] == 1) {
				printf("#");
			} else if (warehouse[i][j] == 2) {
				printf("*");
			} else if (warehouse[i][j] == 3) {
				printf("O");
			} else if (warehouse[i][j] == 4) {
				printf("O");
			} else if (warehouse[i][j] == 5) {
				printf("X");
			} else if (warehouse[i][j] == 6) {
				printf("X");
			}
		}
		printf("\n");
	}
}

/* The GetMove() function returns the entered character.  Invalid
   characters are ignored */
char GetMove(void)
{
	char move;
	printf("\nEnter move: ");
	// Ignore any characters that are invalid
	scanf("%c", &move);
	while ((move != 'w') && (move != 'a') && (move != 's') && (move != 'd')) {
		scanf("%c", &move);
	}
	return move;
}
