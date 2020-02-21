// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)

{
	int a, b;

	printf("Welcome to C Programming! \n");
	printf("Enter an integer: ");
	scanf("%d", &a);
	printf("Enter another integer: ");

	scanf("%d", &b);

	printf("%d + %d = %d\n", a, b, (a + b));


	return 0;
}