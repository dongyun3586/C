// (연습문제2) 정수의 절대값 출력하기 (ex02_if.c)

#include<stdio.h>

int main_ex02_if() {
	int n;

	printf("정수를 입력하시오: ");
	scanf("%d", &n);

	// 입력이 음수인 경우 양수로 변경함.
	if (n<0)
		n = -n;

	printf("절대값은 %d 입니다. \n", n);

	return 0;
}