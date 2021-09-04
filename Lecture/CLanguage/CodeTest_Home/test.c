#include<stdio.h>
#define LENGTH 12

int main() {
	int c = 0;
	
	while ((c = getchar()) != EOF)
		putchar(c);

	return 0;
}