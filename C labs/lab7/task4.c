#include <stdio.h>

int main(void)

{
	char c;
	int d;
	double f;

	c = 'x';
	d = 123;
	f = 123.456;

	printf("%c %d %f\n", c, d, f);
	printf("%c %5d %5.1f\n", c, d, f);
	printf("%c %10d %10.2f\n", c, d, f);

	printf("\\ / /n \n");
	printf("\\ \" \\ \" \n");


	return 0;
}