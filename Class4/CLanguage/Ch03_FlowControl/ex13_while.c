#include<stdio.h>

int main_ex13_while() {
	int num = 1, sum = 0;

	while (num <= 100) {
		printf("num(%2d) + sum(%4d) = ", num, sum);
		sum += num;
		printf("%d\n", sum);
		num++;
	}

	printf("\nnum = %d, sum = %d\n", num, sum);

	return 0;
}