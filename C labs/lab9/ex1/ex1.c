/* ENGGEN131 (2019) - Lab 9 (1st - 4th October, 2019)
   EXERCISE ONE - Da Vinci Code

   Draw something spectacular!
*/

#include "LibBMP.h"

int main(void)
{
	int width, height, i;
	int border = 5;

	LoadBMPFile("blank.bmp", &width, &height);

	// Draw the border
	for (i = border; i < width - border; i++) {
		DrawPixel(border, i, 0, 0, 0);
		DrawPixel(height - border, i, 0, 0, 0);
	}
	for (i = border; i < height - border; i++) {
		DrawPixel(i, border, 0, 0, 0);
		DrawPixel(i, width - border, 0, 0, 0);
	}

	// Some basic art...
	/*
	DrawLine(280, 280, 320, 320, 0, 0, 0);
	DrawLine(280, 320, 320, 280, 0, 0, 0);
	FillCircle(300, 260, 20, 0, 0, 255);
	DrawSquare(260, 300, 20, 255, 0, 0);
	FillSquare(340, 300, 20, 0, 255, 0);
	DrawCircle(300, 340, 20, 255, 0, 0);
	*/
	int state = 0, r = 255, g = 0, b = 0;
	for (int i = 670; i >= 0; i--) {
		FillCircle(600, 300, i, r, g, b);
		for (int gradiant = 0; gradiant < 2; gradiant++) {
			if (state == 0) {
				g++;
				if (g == 255) state = 1;
			} else if (state == 1) {
				r--;
				if (r == 0) state = 2;
			} else if (state == 2) {
				b++;
				if (b == 255) state = 3;
			} else if (state == 3) {
				g--;
				if (g == 0) state = 4;
			} else if (state == 4) {
				r++;
				if (r == 255) state = 5;
			} else if (state == 5) {
				b--;
				if (b == 0) state = 0;
			}
		}
	}

	SaveBMPFile("output.bmp", width, height);

	return 0;
}
