#include<stdio.h>

int main() {
	int dan, i, j;
	for (dan = 2; dan <= 9; dan++) {
		for (i = 1; i <= 9; i++) {
			printf("%2d * %2d = %2d\n", dan, i, dan * i);
		}
		printf("\n");
	}

	return 0;
}