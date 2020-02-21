/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

/* << simon shan , qsha020 , 441147157 >> */

#include "project.h"

/*
Your comment should go here – it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int TimeWorked(int minuteA, int secondA, int minuteB, int secondB)
{
	int seconds = (minuteB - minuteA) * 60 + secondB - secondA;
	seconds *= (seconds > 0) - (seconds < 0);	// change the sign if negative
	
	return seconds;
}

/*
*/
int IsPrime(int number)
{
	int isPrime = 1;						// assume is prime

	// check for any factors //
	for (int i = 2; i * i <= number; i++) {
		if (number % i == 0) {
			isPrime = 0;					// if a factor is found
			break;							// exit the loop, no need to continue
		}
	}

	return isPrime;
}

/*
Your comment should go here – it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int WarehouseAddress(int maximum)
{
	int isPrime;

	do {
		maximum--;
		/*
		isPrime = 1;							// assume is prime

		// check for any factors //
		for (int i = 2; i * i <= maximum; i++) {
			if (maximum % i == 0) {
				isPrime = 0;					// if a factor is found
				break;							// exit the loop, no need to continue
			}
		}
		*/
	} while (IsPrime(maximum) == 0);	//(isPrime == 0);

	return maximum;
}

/*
Your comment should go here – it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void Advertise(char *words)
{
	int idx = 0;
	int firstChar = words[0];

	/* rotate left by 1 */
	while (words[idx + 1] != '\0') {

		words[idx] = words[idx + 1];
		idx++;
	}

	words[idx] = firstChar;
}

/*
Your comment should go here – it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int WinningBid(int *values, int length)
{
	int  isUnique;
	int numUniques = 0;
	int minBid = 2147483647;

	for (int i = 0; i < length; i++) {
		isUnique = 1;						//assume is unique

		// check if unique //
		for (int j = 0; j < length; j++) {
			if ((values[i] == values[j]) && (i != j)) {
				isUnique = 0;				// if a duplicate is found
				break;						// exit the loop, no need to continue
			}
		}

		if (isUnique) {
			numUniques++;
			if (values[i] < minBid) minBid = values[i];
		}
	}

	/* return minimum unique bid, if none return -1 */
	if (numUniques) {
		return minBid;
	}
	return -1;

}

/*
Coords() is a helper function used in BoxDesign()
translates x y coords into array index in desgin[]
*/
int Coords(int x, int y, int width)
{
	return (width + 1) * y + x;
}

/*
Your comment should go here – it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void BoxDesign(char *design, int width, int height)
{
	int totalLength = (width + 1) * height;

	/* add space characters for the box */
	for (int i = 0; i < totalLength; i++) {
		design[i] = ' ';
	}


	/* coords of centre points */
	int   left = (int)((double)  width / 2 - 0.1);
	int  right = (int)((double)  width / 2 + 0.1);
	int    top = (int)((double) height / 2 - 0.1);
	int bottom = (int)((double) height / 2 + 0.1);

	/* add centre points */
	design[Coords(	left, 	 top, width)] = 'X';
	design[Coords( right, 	 top, width)] = 'X';
	design[Coords(	left, bottom, width)] = 'X';
	design[Coords( right, bottom, width)] = 'X';


	/* add top and bottom borders */
	for (int i = 0; i < width; i++) {
		design[Coords(i, 			0, width)] = '*';
		design[Coords(i, (height - 1), width)] = '*';
	}

	/* add left and right borders and new line characters */
	for (int i = 0; i < height; i++) {
		design[Coords(			0, i, width)] = '*';
		design[Coords((width - 1), i, width)] = '*';
		design[Coords(		width, i, width)] = '\n';
	}
}

/*
find the position of the target in the warehouse
*/
void GetPosition(int warehouse[10][10], int target, int *x, int *y)
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (warehouse[i][j] == target) {
				*x = i;
				*y = j;
				return;
			}
		}
	}
}

/*
Your comment should go here – it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
void WorkerRoute(int warehouse[10][10])
{
	int xPosWorker, yPosWorker;
	int xPosBox, 	yPosBox;

	/* find positions of worker and box */
	GetPosition(warehouse, 1, &xPosWorker, &yPosWorker);
	GetPosition(warehouse, 2, &xPosBox,    &yPosBox   );


	/* horizontal move */

	// possibility 1: move right //
	for (int i = yPosWorker + 1; i < yPosBox; i++) {
		warehouse[xPosWorker][i] = 3;
	}

	// possibility 2: move left //
	for (int i = yPosWorker - 1; i > yPosBox; i--){
		warehouse[xPosWorker][i] = 3;
	}



	/* vertical move */

	// possibility 1: move down //
	for (int i = xPosWorker; i < xPosBox; i++) {
		warehouse[i][yPosBox] = 3;
	}

	// possibility 2: move up //
	for (int i = xPosWorker; i > xPosBox; i--){
		warehouse[i][yPosBox] = 3;
	}


	warehouse[xPosWorker][yPosWorker] = 1;
	warehouse[xPosBox]   [yPosBox]	  = 2;
}

/*
check if task is completed
*/
int TaskCheck(int warehouse[10][10])
{
	int hasTargets = 0;					// assume no targets
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {

			if (warehouse[i][j] == TARGET) {
				return 0;
			}
			if (warehouse[i][j] == WORKER_ON_TARGET) hasTargets = 1;
		}
	}
	if (hasTargets) return 1;
	return 0;
}

/*
Your comment should go here – it should describe the purpose of the function and a
brief summary of the algorithm you have used to solve the task (this comment must
be written in your own words
*/
int MakeMove(int warehouse[10][10], char move)
{
	int xPosWorker = 0, yPosWorker = 0;
	int SPCTRGT;	//SPACE or TARGET

	GetPosition(warehouse, WORKER, 			 &xPosWorker, &yPosWorker);
	GetPosition(warehouse, WORKER_ON_TARGET, &xPosWorker, &yPosWorker);
	SPCTRGT = warehouse[xPosWorker][yPosWorker];

	int x = 0, y = 0;
	switch (move) {
		case 'w':
			x = -1;
			break;
		case 'a':
			y = -1;
			break;
		case 's':
			x = 1;
			break;
		case 'd':
			y = 1;
			break;
	}

	int *workerPos 		= &warehouse[xPosWorker]		[yPosWorker];
	int *inFrontWorker 	= &warehouse[xPosWorker + x]	[yPosWorker + y];
	int *inFrontBox 	= &warehouse[xPosWorker + x + x][yPosWorker + y + y];

	switch (*inFrontWorker)
	{
		case SPACE:
			*workerPos = SPCTRGT;
			*inFrontWorker = WORKER;
			break;

		case TARGET:
			*workerPos = SPCTRGT;
			*inFrontWorker = WORKER_ON_TARGET;
			break;

		case BOX:
			if (*inFrontBox == SPACE) {
				*workerPos = SPCTRGT;
				*inFrontWorker = WORKER;
				*inFrontBox = BOX;
			} else
			if (*inFrontBox == TARGET) {
				*workerPos = SPCTRGT;
				*inFrontWorker = WORKER;
				*inFrontBox = BOX_ON_TARGET;
			}
			break;

		case BOX_ON_TARGET:
			if (*inFrontBox == SPACE) {
				*workerPos = SPCTRGT;
				*inFrontWorker = WORKER_ON_TARGET;
				*inFrontBox = BOX;
			} else
			if (*inFrontBox == TARGET) {
				*workerPos = SPCTRGT;
				*inFrontWorker = WORKER_ON_TARGET;
				*inFrontBox = BOX_ON_TARGET;
			}
			break;
	}

	return TaskCheck(warehouse);
}

