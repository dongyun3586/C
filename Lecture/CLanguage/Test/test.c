#include<stdio.h>

int main() {
	int count = 0;

	for (int a = 1; a <= 1000; a++)
		for (int b = a; b <= 1000; b++)
			for (int c = b; c <= 1000; c++) {
				if ((a * a + b * b) == c * c) {
					printf("%3d %3d %3d\n", a, b, c);
					count++;
				}
			}
	printf("count: %d\n", count);

	return 0;
}