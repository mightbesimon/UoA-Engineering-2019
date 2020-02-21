/*  LibBMP - a library for reading and writing bitmap data for
    uncompressed 24-bit BMP images.
    - Paul Denny
    - August 2007
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
void DrawPixel(int x, int y, int r, int g, int b);

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
