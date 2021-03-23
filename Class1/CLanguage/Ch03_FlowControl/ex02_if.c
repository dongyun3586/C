#include<stdio.h>

int main_ex02_if() {
	int n; // 필요한 변수 선언

	// 값 입력받기
	printf("정수를 입력하시오: ");
	scanf("%d", &n);

	// 판단
	if (n<0)
		n = -n;

	// 절대값 출력
	printf("절대값은 %d 입니다 \n", n);
	return 0;
}