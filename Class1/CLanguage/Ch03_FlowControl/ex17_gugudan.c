#include<stdio.h>

int main_ex17_gugudan() {
	//int dan, n;

	for (int dan = 2; dan <= 9; dan++) {
		for (int n = 1; n <= 9; n++) {
			printf("%2d * %2d = %2d\n", dan, n, dan * n);
		}
		printf("\n");
	}

	return 0;
}