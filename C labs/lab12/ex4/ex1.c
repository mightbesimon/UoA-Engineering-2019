#include <stdio.h>
#include "LibBMP.h"

void DrawSquare(double x, double y, double size, int level)
{
	if (level > 0) {
		StartAt((int)(x - size/2), (int)(y - size/2));

		TurnRight(90);
		Forward(size);
		TurnRight(90);
		Forward(size);
		TurnRight(90);
		Forward(size);
		TurnRight(90);
		Forward(size);

		DrawSquare((int)(x - size/2), (int)(y - size/2), (int)(size / 2), level - 1);
		DrawSquare((int)(x - size/2), (int)(y + size/2), (int)(size / 2), level - 1);
		DrawSquare((int)(x + size/2), (int)(y - size/2), (int)(size / 2), level - 1);
		DrawSquare((int)(x + size/2), (int)(y + size/2), (int)(size / 2), level - 1);
	}
}

int main(void)
{
	int width, height;

	LoadBMPFile("blank.bmp", &width, &height);

	DrawSquare(300, 300, 200, 5);

	SaveBMPFile("output.bmp", width, height);

	return 0;
}




