#include<stdio.h>

int main() {
	int n = 3;

	for (int a = 0; a <= n; a++) {
		for (int b = a; b >= 0; b--) {
			printf("%d", b);
		}

		printf("\n");
	}

	return 0;
}