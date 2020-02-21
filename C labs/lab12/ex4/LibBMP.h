/*  LibBMP - a library for reading and writing bitmap data for
    uncompressed 24-bit BMP images.
    - Paul Denny
    - September 2019
*/

/* Colour values in the range 0-255 */
typedef unsigned char byte;

/* Bitmap data for a single pixel */
typedef struct {
	byte red;
	byte green;
	byte blue;
} Colour;

/* The maximum width and height of the image supported */
#define MAXW 1500
#define MAXH 1500

/* Function prototype declarations */
void LoadBMPFile(char *filename, int *width, int *height);
void SaveBMPFile(char *filename, int width, int height);
void DrawPixel(int row, int col, int red, int green, int blue);
//void DrawSquare(int row, int col, int size, int red, int green, int blue);
void FillSquare(int row, int col, int size, int red, int green, int blue);
void DrawLine(int row0, int col0, int row1, int col1, int red, int green, int blue);
void DrawCircle(int row, int col, int radius, int red, int green, int blue);
void FillCircle(int row, int col, int radius, int red, int green, int blue);

int GetPixelValue(int row, int col, int channel);
void SetPixelValue(int value, int row, int col, int channel);

void LoadColourArray(char *filename, Colour bitmap[MAXH][MAXW], int *width, int *height);
void SaveColourArray(char *filename, Colour bitmap[MAXH][MAXW], int width, int height);

/* Turtle functions */
void StartAt(double row, double col);
void PenUp();
void PenDown();
void PenColour(int r, int g, int b);
void TurnRight(double delta);
void TurnLeft(double delta);
void Forward(double step);
void Backward(double step);

