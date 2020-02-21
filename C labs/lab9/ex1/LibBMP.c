#define _CRT_SECURE_NO_DEPRECATE

#include "LibBMP.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Prototype declartions for input functions.  GetByte() returns a 1-byte sequence as an int,
   GetWord() returns a 2-byte sequence as an int, GetDoubleWord() returns a 4-byte sequence as an int.
   These functions assume little-endianness of file
*/
static int GetByte(FILE *fp);
static int GetWord(FILE *fp);
static int GetDoubleWord(FILE *fp);

/* This is used for storing file data for a BMP file loaded using the LoadBMPFile function */
static Colour internalBitmap[MAXH][MAXW];
static int loadSuccess = 0;

/* Turtle state */
double turtle_x = 0;
double turtle_y = 0;
double turtle_angle = 180;
int turtle_pen = 1;
int turtle_r = 0;
int turtle_g = 0;
int turtle_b = 0;

void LoadBMPFile(char* filename, int* width, int* height)
{
	/* For reading data from the file */
	int colourDepth, compression, fileSize;
	int x, y;

	/* Open BMP file */
	FILE *fptr;
	fptr = fopen(filename, "rb");
	if (fptr == NULL) {
		printf("Could not open input file: \"%s\"\n", filename);
		exit(EXIT_FAILURE);
	}

	/* Read file size */
	(void)fseek(fptr, 2, SEEK_SET);
	fileSize = GetDoubleWord(fptr);

	/* Read width and height of image */
	(void)fseek(fptr, 18, SEEK_SET);
	*width = GetDoubleWord(fptr);
	(void)fseek(fptr, 22, SEEK_SET);
	*height = GetDoubleWord(fptr);

	/* Read colour depth */
	(void)fseek(fptr, 28, SEEK_SET);
	colourDepth = GetWord(fptr);

	/* Read compression */
	(void)fseek(fptr, 30, SEEK_SET);
	compression = GetDoubleWord(fptr);

	/* Ensure a 24-bit, and therefore uncompressed BMP file */
	if ((colourDepth != 24) || (compression != 0)) {
		printf("Not a valid 24-bit BMP file.\n");
		printf("Colour depth should be 24 - it is %d.\n", colourDepth);
		printf("Compression should be 0 - it is %d.\n", compression);
		exit(EXIT_FAILURE);
	}

	/* Read the pixel information */
	(void)fseek(fptr, 54, SEEK_SET);

	/* Ensure memory is adequate */
	if ((*height >= MAXH) || (*width >= MAXW)) {
		printf("Not enough memory for a %dx%d image.\n", MAXW, MAXH);
		printf("Increase the values of MAXW and MAXH in LibBMP.h\n");
		exit(EXIT_FAILURE);
	}

	for(y = *height-1; y >= 0; y--) {
		for(x = 0; x < *width; x++) {
			internalBitmap[y][x].blue = (byte)GetByte(fptr);
			internalBitmap[y][x].green = (byte)GetByte(fptr);
			internalBitmap[y][x].red = (byte)GetByte(fptr);
		}
		/* Realign the file pointer, scan lines are word aliged */
		(void)fseek(fptr, *width % 4, SEEK_CUR);
	}

	/* Close the input file */
	(void)fclose(fptr);

	printf("Successfully loaded bitmap information:\n");
	printf("  - Filename: \"%s\"\n", filename);
	printf("  - Width: %d\n", *width);
	printf("  - Height: %d\n", *height);
	printf("  - Bytes read: %d\n\n", fileSize);
	loadSuccess = 1;
}

/* channel 0, 1, 2 = red, green, blue */
int GetPixelValue(int row, int col, int channel)
{
	if (channel == 0)
		return internalBitmap[row][col].red;
	else if (channel == 1)
		return internalBitmap[row][col].green;
	else
		return internalBitmap[row][col].blue;
}

/* channel 0, 1, 2 = red, green, blue */
void SetPixelValue(int value, int row, int col, int channel)
{
	byte val = (byte)value;
	if (channel == 0)
		internalBitmap[row][col].red = val;
	else if (channel == 1)
		internalBitmap[row][col].green = val;
	else
		internalBitmap[row][col].blue = val;
}

void DrawPixel(int row, int col, int r, int g, int b)
{
	// MAXH and MAXW give the maximum dimensions for the bitmap
	// r, g and b are limited to 0-255
	if (r < 0) r = 0; if (g < 0) g = 0; if (b < 0) b = 0;
	if (r > 255) r = 255; if (g > 255) g = 255; if (b > 255) b = 255;

	if ((row < 0) || (row > MAXH)) {
		return;
	} else if ((col < 0) || (col > MAXW)) {
		return;
	} else {
		SetPixelValue(r, row, col, 0);
		SetPixelValue(g, row, col, 1);
		SetPixelValue(b, row, col, 2);
	}
}

void DrawSquare(int row, int col, int size, int red, int green, int blue)
{
	int r, c;

	for (r = row - size; r <= row + size; r++) {
		for (c = col - size; c <= col + size; c++) {
			if (r == row - size || r == row + size || c == col - size || c == col + size) {
				DrawPixel(r, c, red, green, blue);
			}
		}
	}
}

void FillSquare(int row, int col, int size, int red, int green, int blue)
{
	int r, c;

	for (r = row - size; r <= row + size; r++) {
		for (c = col - size; c <= col + size; c++) {
			DrawPixel(r, c, red, green, blue);
		}
	}
}

void PlotLineLow(int x0, int y0, int x1, int y1, int red, int green, int blue)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int yi = 1;
	if (dy < 0) {
	    yi = -1;
		dy = -dy;
	}
	int D = 2*dy - dx;
	int y = y0;

	for (int x = x0; x <= x1; x++) {
	    DrawPixel(x, y, red, green, blue);
		if (D > 0) {
			y = y + yi;
			D = D - 2*dx;
		}
		D = D + 2*dy;
	}
}

void PlotLineHigh(int x0, int y0, int x1, int y1, int red, int green, int blue)
{
	int dx = x1 - x0;
	int dy = y1 - y0;
	int xi = 1;
	if (dx < 0) {
	    xi = -1;
		dx = -dx;
	}
	int D = 2*dx - dy;
	int x = x0;

	for (int y = y0; y <= y1; y++) {
	    DrawPixel(x, y, red, green, blue);
		if (D > 0) {
			x = x + xi;
			D = D - 2*dy;
		}
		D = D + 2*dx;
	}
}

int absDiff(int a, int b) {
	if (a > b) {
		return a - b;
	} else {
		return b - a;
	}
}

void DrawLine(int row0, int col0, int row1, int col1, int red, int green, int blue)
{
	if (absDiff(col1, col0) < absDiff(row1, row0)) {
		if (row0 > row1) {
			PlotLineLow(row1, col1, row0, col0, red, green, blue);
		} else {
			PlotLineLow(row0, col0, row1, col1, red, green, blue);
		}
	} else {
		if (col0 > col1) {
			PlotLineHigh(row1, col1, row0, col0, red, green, blue);
		} else {
			PlotLineHigh(row0, col0, row1, col1, red, green, blue);
		}
	}
}

void DrawCircle(int row, int col, int radius, int red, int green, int blue)
{
	int x = radius;
	int y = 0;
	int radiusError = 1-x;

	while(x >= y) {
		DrawPixel(x + row, y + col, red, green, blue);
		DrawPixel(y + row, x + col, red, green, blue);
		DrawPixel(-x + row, y + col, red, green, blue);
		DrawPixel(-y + row, x + col, red, green, blue);
		DrawPixel(-x + row, -y + col, red, green, blue);
		DrawPixel(-y + row, -x + col, red, green, blue);
		DrawPixel(x + row, -y + col, red, green, blue);
		DrawPixel(y + row, -x + col, red, green, blue);
		y++;
		if (radiusError < 0) {
			radiusError += 2 * y + 1;
		} else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}

void FillCircle(int row, int col, int radius, int red, int green, int blue)
{
	int x = radius;
	int y = 0;
	int radiusError = 1-x;

	while(x >= y) {
		DrawLine(-x + row, y + col, x + row, y + col, red, green, blue);
		DrawLine(-y + row, x + col, y + row, x + col, red, green, blue);
		DrawLine(-x + row, -y + col, x + row, -y + col, red, green, blue);
		DrawLine(-y + row, -x + col, y + row, -x + col, red, green, blue);
		y++;
		if (radiusError < 0) {
			radiusError += 2 * y + 1;
		} else {
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}

// Core turtle functions
void turtle_plot_(int X, int Y, double D, int r, int g, int b)
{
	int to_red, to_green, to_blue;
	int old_red, old_green, old_blue;
	double br = D;
	if ( br > 1.0 ) {
		br = 1.0;
	}
	if ((X < 0) || (X > MAXW)) {
		return;
	} else if ((Y < 0) || (Y > MAXH)) {
		return;
	} else {
		old_red = GetPixelValue(X, Y, 0);
		old_green = GetPixelValue(X, Y, 1);
		old_blue = GetPixelValue(X, Y, 2);
		to_red = (int)(br * (double)r + old_red * (1-br));
		to_green = (int)(br * (double)g + old_green * (1-br));
		to_blue = (int)(br * (double)b + old_blue * (1-br));
		SetPixelValue(to_red, X, Y, 0);
		SetPixelValue(to_green, X, Y, 1);
		SetPixelValue(to_blue, X, Y, 2);
	}
}

#define libbmp_ipart_(X) ((int)(X))
#define libbmp_round_(X) ((int)(((double)(X))+0.5))
#define libbmp_fpart_(X) (((double)(X))-(double)libbmp_ipart_(X))
#define libbmp_rfpart_(X) (1.0-libbmp_fpart_(X))
#define swap_(a, b) {  int tmp;  tmp = a; a = b; b = tmp; }

void turtle_draw_line_antialias(int x1,  int y1, int x2,  int y2, int r, int g, int b) {

	double gradient, xend, yend, xgap, ygap, intery, interx;
	double dx = (double)x2 - (double)x1;
	double dy = (double)y2 - (double)y1;
	int x, y, xpxl1, ypxl1, xpxl2, ypxl2;

	if ( fabs(dx) > fabs(dy) ) {
		if ( x2 < x1 ) {
			swap_(x1, x2);
			swap_(y1, y2);
		}
		gradient = dy / dx;
		xend = libbmp_round_(x1);
		yend = y1 + gradient*(xend - x1);
		xgap = libbmp_rfpart_(x1 + 0.5);
		xpxl1 = (int)xend;
		ypxl1 = libbmp_ipart_(yend);
		turtle_plot_(xpxl1, ypxl1, libbmp_rfpart_(yend)*xgap, r, g, b);
		turtle_plot_(xpxl1, ypxl1+1, libbmp_fpart_(yend)*xgap, r, g, b);
		intery = yend + gradient;

		xend = libbmp_round_(x2);
		yend = y2 + gradient*(xend - x2);
		xgap = libbmp_fpart_(x2+0.5);
		xpxl2 = (int)xend;
		ypxl2 = libbmp_ipart_(yend);
		turtle_plot_(xpxl2, ypxl2, libbmp_rfpart_(yend) * xgap, r, g, b);
		turtle_plot_(xpxl2, ypxl2 + 1, libbmp_fpart_(yend) * xgap, r, g, b);

		for(x=xpxl1+1; x <= (xpxl2-1); x++) {
			turtle_plot_(x, libbmp_ipart_(intery), libbmp_rfpart_(intery), r, g, b);
			turtle_plot_(x, libbmp_ipart_(intery) + 1, libbmp_fpart_(intery), r, g, b);
			intery += gradient;
		}

	} else {
		if ( y2 < y1 ) {
			swap_(x1, x2);
			swap_(y1, y2);
		}
		gradient = dx / dy;
		yend = libbmp_round_(y1);
		xend = x1 + gradient*(yend - y1);
		ygap = libbmp_rfpart_(y1 + 0.5);
		ypxl1 = (int)yend;
		xpxl1 = libbmp_ipart_(xend);
		turtle_plot_(xpxl1, ypxl1, libbmp_rfpart_(xend)*ygap, r, g, b);
		turtle_plot_(xpxl1, ypxl1+1, libbmp_fpart_(xend)*ygap, r, g, b);
		interx = xend + gradient;

		yend = libbmp_round_(y2);
		xend = x2 + gradient*(yend - y2);
		ygap = libbmp_fpart_(y2+0.5);
		ypxl2 = (int)yend;
		xpxl2 = libbmp_ipart_(xend);
		turtle_plot_(xpxl2, ypxl2, libbmp_rfpart_(xend) * ygap, r, g, b);
		turtle_plot_(xpxl2, ypxl2 + 1, libbmp_fpart_(xend) * ygap, r, g, b);

		for(y=ypxl1+1; y <= (ypxl2-1); y++) {
			turtle_plot_(libbmp_ipart_(interx), y, libbmp_rfpart_(interx), r, g, b);
			turtle_plot_(libbmp_ipart_(interx) + 1, y, libbmp_fpart_(interx), r, g, b);
			interx += gradient;
		}
	}
}

/* API turtle functions */
#define M_PI_TURTLE 3.14159265358979323846

void StartAt(double row, double col) {
	turtle_x = row;
	turtle_y = col;
}

double to_radians(double degrees) {
    return (M_PI_TURTLE * degrees) / 180;
}

void TurnRight(double delta) {
	turtle_angle -= delta;
}

void TurnLeft(double delta) {
	turtle_angle += delta;
}

void PenUp()
{
	turtle_pen = 0;
}

void PenDown()
{
	turtle_pen = 1;
}

void PenColour(int r, int g, int b)
{
	turtle_r = r;
	turtle_g = g;
	turtle_b = b;
}


void Forward(double step) {
	double oldx = turtle_x;
	double oldy = turtle_y;
	turtle_x += step * cos(to_radians(turtle_angle));
	turtle_y += step * sin(to_radians(turtle_angle));
	if (turtle_pen) {
		turtle_draw_line_antialias((int)oldx, (int)oldy, (int)turtle_x, (int)turtle_y, turtle_r, turtle_g, turtle_b);
	}
}

void Backward(double step) {
	double oldx = turtle_x;
	double oldy = turtle_y;
	turtle_x -= step * cos(to_radians(turtle_angle));
	turtle_y -= step * sin(to_radians(turtle_angle));
	if (turtle_pen) {
		turtle_draw_line_antialias((int)oldx, (int)oldy, (int)turtle_x, (int)turtle_y, turtle_r, turtle_g, turtle_b);
	}
}

void SaveBMPFile(char* filename, int width, int height)
{
	/* BMP file format header, for uncompressed 24-bit colour */
	byte header[54] = {	0x42,0x4D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00,0xC2,0x1E,0x00,0x00,0xC2,0x1E,0x00,0x00,0x00,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00 };

	FILE *fptr;
	byte* fileData;

	int aligned, padding, totalSize;
	int i;
	int x, y;
	int writeIndex = 54;

	/* Ensure a file has been loaded prior to this call */
	if (!loadSuccess) {
		printf("BMP file must be loaded before saving.\n");
		exit(EXIT_FAILURE);
	}

	/* Calculate total size of picture, taking into account padding */
	aligned = 4 - (width * 3) % 4;
	padding = (aligned == 4) ? 0 : aligned;
	totalSize = 54 + (((width * 3) + padding) * height);

	/* Allocate room to store filedata */
	fileData = (byte*)malloc((size_t)totalSize);
	if (fileData == NULL) {
		printf("Could not allocate sufficient memory.\n");
		exit(EXIT_FAILURE);
	}

	/* Initialise first 54 bytes, set total size and width and height correctly */
	for (i = 0; i < 54; i++) {
		fileData[i] = header[i];
	}
	/* File size */
	fileData[2] = (byte)(totalSize & 0xFF);
	fileData[3] = (byte)((totalSize >> 0x08) & 0xFF);
	fileData[4] = (byte)((totalSize >> 0x10) & 0xFF);
	fileData[5] = (byte)((totalSize >> 0x18) & 0xFF);
	/* Width */
	fileData[18] = (byte)(width & 0xFF);
	fileData[19] = (byte)((width >> 0x08) & 0xFF);
	fileData[20] = (byte)((width >> 0x10) & 0xFF);
	fileData[21] = (byte)((width >> 0x18) & 0xFF);
	/* Height */
	fileData[22] = (byte)(height & 0xFF);
	fileData[23] = (byte)((height >> 0x08) & 0xFF);
	fileData[24] = (byte)((height >> 0x10) & 0xFF);
	fileData[25] = (byte)((height >> 0x18) & 0xFF);

	/* Copy bitmap data */
	for(y=height-1; y >=0; y--) {
		for(x=0; x < width; x++) {
			fileData[writeIndex++] = internalBitmap[y][x].blue;
			fileData[writeIndex++] = internalBitmap[y][x].green;
			fileData[writeIndex++] = internalBitmap[y][x].red;
		}
		writeIndex += width%4;
	}

	/* Write to file */
	fptr = fopen(filename, "wb");
	if (fptr == NULL) {
		printf("Could not open output file: \"%s\"\n", filename);
		exit(EXIT_FAILURE);
	}

	/* Write data */
	(void)fwrite(fileData, 1, (size_t)totalSize, fptr);

	/* Close files */
	(void)fclose(fptr);

	/* Release memory */
	free(fileData);

	printf("Successfully saved bitmap information:\n");
	printf("  - Filename: \"%s\"\n", filename);
	printf("  - Width: %d\n", width);
	printf("  - Height: %d\n", height);
	printf("  - Bytes written: %d\n\n", totalSize);
}

void LoadColourArray(char* filename, Colour bitmap[MAXH][MAXW], int* width, int* height)
{
	/* For reading data from the file */
	int colourDepth, compression, fileSize;
	int x, y;

	/* Open BMP file */
	FILE *fptr;
	fptr = fopen(filename, "rb");
	if (fptr == NULL) {
		printf("Could not open input file: \"%s\"\n", filename);
		exit(EXIT_FAILURE);
	}

	/* Read file size */
	(void)fseek(fptr, 2, SEEK_SET);
	fileSize = GetDoubleWord(fptr);

	/* Read width and height of image */
	(void)fseek(fptr, 18, SEEK_SET);
	*width = GetDoubleWord(fptr);
	(void)fseek(fptr, 22, SEEK_SET);
	*height = GetDoubleWord(fptr);

	/* Read colour depth */
	(void)fseek(fptr, 28, SEEK_SET);
	colourDepth = GetWord(fptr);

	/* Read compression */
	(void)fseek(fptr, 30, SEEK_SET);
	compression = GetDoubleWord(fptr);

	/* Ensure a 24-bit, and therefore uncompressed BMP file */
	if ((colourDepth != 24) || (compression != 0)) {
		printf("Not a valid 24-bit BMP file.\n");
		printf("Colour depth should be 24 - it is %d.\n", colourDepth);
		printf("Compression should be 0 - it is %d.\n", compression);
		exit(EXIT_FAILURE);
	}

	/* Read the pixel information */
	(void)fseek(fptr, 54, SEEK_SET);

	/* Ensure memory is adequate */
	if ((*height >= MAXH) || (*width >= MAXW)) {
		printf("Not enough memory for a %dx%d image.\n", MAXW, MAXH);
		printf("Increase the values of MAXW and MAXH in LibBMP.h\n");
		exit(EXIT_FAILURE);
	}

	for(y = *height-1; y >= 0; y--) {
		for(x = 0; x < *width; x++) {
			bitmap[y][x].blue = (byte)GetByte(fptr);
			bitmap[y][x].green = (byte)GetByte(fptr);
			bitmap[y][x].red = (byte)GetByte(fptr);
		}
		/* Realign the file pointer, scan lines are word aliged */
		(void)fseek(fptr, *width % 4, SEEK_CUR);
	}

	/* Close the input file */
	(void)fclose(fptr);

	printf("Successfully loaded bitmap information:\n");
	printf("  - Filename: \"%s\"\n", filename);
	printf("  - Width: %d\n", *width);
	printf("  - Height: %d\n", *height);
	printf("  - Bytes read: %d\n\n", fileSize);
}

void SaveColourArray(char* filename, Colour bitmap[MAXH][MAXW], int width, int height)
{
	/* BMP file format header, for uncompressed 24-bit colour */
	byte header[54] = {	0x42,0x4D,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x36,0x00,0x00,0x00,0x28,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x18,0x00,0x00,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00,0xC2,0x1E,0x00,0x00,0xC2,0x1E,0x00,0x00,0x00,0x00,
						0x00,0x00,0x00,0x00,0x00,0x00 };

	FILE *fptr;
	byte* fileData;

	int aligned, padding, totalSize;
	int i;
	int x, y;
	int writeIndex = 54;

	/* Calculate total size of picture, taking into account padding */
	aligned = 4 - (width * 3) % 4;
	padding = (aligned == 4) ? 0 : aligned;
	totalSize = 54 + (((width * 3) + padding) * height);

	/* Allocate room to store filedata */
	fileData = (byte*)malloc((size_t)totalSize);
	if (fileData == NULL) {
		printf("Could not allocate sufficient memory.\n");
		exit(EXIT_FAILURE);
	}

	/* Initialise first 54 bytes, set total size and width and height correctly */
	for (i = 0; i < 54; i++) {
		fileData[i] = header[i];
	}
	/* File size */
	fileData[2] = (byte)(totalSize & 0xFF);
	fileData[3] = (byte)((totalSize >> 0x08) & 0xFF);
	fileData[4] = (byte)((totalSize >> 0x10) & 0xFF);
	fileData[5] = (byte)((totalSize >> 0x18) & 0xFF);
	/* Width */
	fileData[18] = (byte)(width & 0xFF);
	fileData[19] = (byte)((width >> 0x08) & 0xFF);
	fileData[20] = (byte)((width >> 0x10) & 0xFF);
	fileData[21] = (byte)((width >> 0x18) & 0xFF);
	/* Height */
	fileData[22] = (byte)(height & 0xFF);
	fileData[23] = (byte)((height >> 0x08) & 0xFF);
	fileData[24] = (byte)((height >> 0x10) & 0xFF);
	fileData[25] = (byte)((height >> 0x18) & 0xFF);

	/* Copy bitmap data */
	for(y=height-1; y >=0; y--) {
		for(x=0; x < width; x++) {
			fileData[writeIndex++] = bitmap[y][x].blue;
			fileData[writeIndex++] = bitmap[y][x].green;
			fileData[writeIndex++] = bitmap[y][x].red;
		}
		writeIndex += width%4;
	}

	/* Write to file */
	fptr = fopen(filename, "wb");
	if (fptr == NULL) {
		printf("Could not open output file: \"%s\"\n", filename);
		exit(EXIT_FAILURE);
	}

	/* Write data */
	(void)fwrite(fileData, 1, (size_t)totalSize, fptr);

	/* Close files */
	(void)fclose(fptr);

	/* Release memory */
	free(fileData);

	printf("Successfully saved bitmap information:\n");
	printf("  - Filename: \"%s\"\n", filename);
	printf("  - Width: %d\n", width);
	printf("  - Height: %d\n", height);
	printf("  - Bytes written: %d\n\n", totalSize);
}


static int GetByte(FILE *fp)
{
	int w;
	w =  (int) (fgetc(fp) & 0xFF);
	return(w);
}

static int GetWord(FILE *fp)
{
	int w;
	w =  (int) (fgetc(fp) & 0xFF);
	w |= ((int) (fgetc(fp) & 0xFF) << 0x08);
	return(w);
}

static int GetDoubleWord(FILE *fp)
{
	int dw;
	dw =  (int) (fgetc(fp) & 0xFF);
	dw |= ((int) (fgetc(fp) & 0xFF) << 0x08);
	dw |= ((int) (fgetc(fp) & 0xFF) << 0x10);
	dw |= ((int) (fgetc(fp) & 0xFF) << 0x18);
	return(dw);
}
