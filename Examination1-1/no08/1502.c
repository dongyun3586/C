#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int n, gob = 1, jegob = 0;

	printf("양의 정수 입력: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		jegob = i * i;
		gob *= jegob;
	}
	printf("%d\n", gob);

	return 0;
}