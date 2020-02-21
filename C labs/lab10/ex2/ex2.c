#define _CRT_SECURE_NO_WARNINGS

/* ENGGEN131 (2019) - Lab 10 (8th - 11th October, 2019)
   EXERCISE TWO - Triangles
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LibBMP.h"

typedef struct {
	double x;
	double y;
} Point;

// You must implement Steps 4 and 5 of the algorithm below
int main(void)
{
	Point a, b, c, d;
	int i, numPoints, pick;
	int width, height;

	//srand((unsigned int)time(NULL));

	LoadBMPFile("blank.bmp", &width, &height);

	/* STEP 1: Initialise the positions of points A, B and C and plot these points */
	a.x = 1;
	a.y = width / 2;
	b.x = height - 2;
	b.y = 1;
	c.x = height - 2;
	c.y = width - 2;
	// Plot points A, B and C:
	DrawPixel((int)a.x, (int)a.y, 255, 0, 0);
	DrawPixel((int)b.x, (int)b.y, 255, 0, 0);
	DrawPixel((int)c.x, (int)c.y, 255, 0, 0);

	/* STEP 2: Initialise point D at some random location and plot this point */
	d.x = (double)(rand() % height);
	d.y = (double)(rand() % width);
	// Plot point D:
	DrawPixel((int)d.x, (int)d.y, 0, 255, 0);

	/* STEP 3: Read the number of points to plot */
	printf("Enter number of points: ");
	scanf("%d", &numPoints);



	/*********************************************************/
	/* STEP 4 and STEP 5: YOU MUST COMPLETE THESE TWO STEPS */
	/*********************************************************/

	/* Pick one of points A, B or C at random */

	/* Calculate the mid-point between the last point plotted and this random point */

	/* Repeat as many times as specified by the user */


	int pointIdx;
	Point pointPicked;
	Point lastPlotted;
	lastPlotted.x = d.x;
	lastPlotted.y = d.y;

	for (int i = 0; i < numPoints; i++) {

		pointIdx = rand() % 3;
		switch (pointIdx)
		{
			case 0 :
					pointPicked.x = a.x;
					pointPicked.y = a.y;
					break;
			case 1 :
					pointPicked.x = b.x;
					pointPicked.y = b.y;
					break;
			case 2 :
					pointPicked.x = c.x;
					pointPicked.y = c.y;
					break;
		}

		lastPlotted.x = (lastPlotted.x + pointPicked.x) / 2;
		lastPlotted.y = (lastPlotted.y + pointPicked.y) / 2;

		DrawPixel((int)lastPlotted.x, (int)lastPlotted.y, 0, 0, 0);

	}



	SaveBMPFile("output.bmp", width, height);

	return 0;
}

