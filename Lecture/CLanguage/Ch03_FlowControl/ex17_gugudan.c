#include<stdio.h>

int main() {
	int dan, n;
	for (dan = 2; dan <= 9; dan++) {
		for (n = 1; n <= 9; n++) {
			printf("%2d * %2d = %2d\n", dan, n, dan * n);
		}
		printf("\n");
	}

	return 0;
}