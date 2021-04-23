#include<stdio.h>

/* 제곱 수열 결과 출력 */
int main() {
	int n, Data=1;

	printf("양의 정수 입력: ");
	scanf("%d", &n);

	for (int i = 1; i < n+1; i++) {
		for (int j = 0; j < i; j++) {
			Data = Data * i;
		}
	}
	printf("\n%d", Data);

	return 0;
}