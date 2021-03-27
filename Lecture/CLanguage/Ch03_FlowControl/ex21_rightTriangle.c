#include<stdio.h>

int main_ex21_rightTriangle() {
	int count = 0;

	for(int a=1; a<=100; a++)
		for(int b=1; b<=100; b++)
			for (int c = 1; c <= 100; c++) {
				if (a <= b && (a * a + b * b) == c * c) {
					printf("%3d %3d %3d\n", a, b, c);
					count++;
				}
			}
	printf("count: %d\n", count);
	
	return 0;
}