#include<stdio.h>

int main() {
	int num = 1, sum = 0;

	while (num <= 10) {
		printf("num(%2d) + sum(%2d) = ", num, sum);
		sum += num;
		printf("%d\n", sum);
		num++;
	}

	printf("\nnum = %d, sum = %d\n", num, sum);

	return 0;
}