#include<stdio.h>

int main() {
	int year, result;

	printf("연도를 입력하시오: ");
	scanf("%d", &year);

	/* 윤년 규칙(그레고리력)
	  - 연도가 4로 나누어 떨어진다.
	  - 100으로 나누어 떨어지는 연도는 제외한다.
	  - 400으로 나누어 떨어지는 연도는 윤년이다. */
	
	// 1. result에 윤년이면 1(True), 평년이면 0(False)을 저장한다.
	result = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	printf("result = %d \n", result);

	return 0;
}