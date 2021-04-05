#include<stdio.h>

int main_ex10_sum_for() {
	int sum, n;
	sum = 0;

	printf("1부터 합계를 구할 정수를 입력하시오: ");
	scanf("%d", &n);

	// for문을 사용하여 정수의 합 구하기
	for (int i = 1; i <= n; i++)
		sum = sum + i;  // sum += i;

	printf("1 ~ %d까지의 합은 %d 입니다.\n", n, sum);

	return 0;
}