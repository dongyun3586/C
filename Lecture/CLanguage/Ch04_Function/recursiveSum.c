#include<stdio.h>

int recursiveSum(int n);

int main() {
	int n;
	printf("양의 정수: ");
	scanf("%d", &n);

	printf("1~%d의 합계: %d\n", n, recursiveSum(n));

	return 0;
}

int recursiveSum(int n)
{
	if (n == 1)                   // n이 1이면, 그냥 1을 반환함.
	{
		return 1;
	}
	return n + recursiveSum(n - 1); // n이 1이 아니면, n을 1부터 (n-1)까지의 합과 더한 값을 반환함.
}