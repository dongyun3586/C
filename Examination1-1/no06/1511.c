#include<stdio.h>

/* 피보나치 수열 출력 */
int main() {

	// ① 변수 선언 [2점]
	int a, i, j, n;

	// ② 입력 정보 안내 및 입력 받기 [2점]
	printf("양의 정수: ");
	scanf("%d", &a);

	i = 0, j = 1;

	printf("%d %d ", i, j);
	n = i + j;

	while (n<a) {
		printf("%d ", n);
		i = n;
		n = n + j;
		j = i;
	}

	return 0;
}