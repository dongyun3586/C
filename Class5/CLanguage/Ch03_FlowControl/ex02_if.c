// (연습문제2) 정수의 절대값 출력하기 (ex02_if.c)

#include<stdio.h>

int main_ex02_if() {
	int n;
	printf("정수 입력: ");
	scanf("%d", &n);

	// 음수면 양수로 변환
	if (n < 0)
		n = -n;

	printf("절대값은 %d \n", n);

	return 0;
}