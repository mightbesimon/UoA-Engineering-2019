/* ENGGEN131 Project - C Project - 2019 */
/* The Warehouse */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define WAREHOUSE_SIZE 10
#define MAX_ARRAY_SIZE 1000

#define SPACE 0
#define WALL 1
#define TARGET 2
#define BOX 3
#define BOX_ON_TARGET 4
#define WORKER 5
#define WORKER_ON_TARGET 6

/*********************************************************************************/
// Function prototype declarations

int TimeWorked(int minuteA, int secondA, int minuteB, int secondB);
int WarehouseAddress(int maximum);
void Advertise(char *words);
int WinningBid(int *values, int length);
void BoxDesign(char *design, int width, int height);
void WorkerRoute(int warehouse[10][10]);
int MakeMove(int warehouse[10][10], char move);

/*********************************************************************************/

