#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int a, sum;

	printf("양의 정수 입력: ");
	scanf("%d", &a);

	for (int i = 0; i <= a; i++) {
		//b = 1;
		for (int j = 0; j <= i; j++)
			i = j * j;
		sum += i;
	}

	printf("%d", sum);

	return 0;
}