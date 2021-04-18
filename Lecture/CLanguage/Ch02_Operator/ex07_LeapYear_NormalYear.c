#include<stdio.h>

int main() {
	int year;

	printf("연도를 입력하시오: ");
	scanf("%d", &year);

	/* 윤년 규칙(그레고리력)
	  - 연도가 4로 나누어 떨어진다.
	  - 100으로 나누어 떨어지는 연도는 제외한다.
	  - 400으로 나누어 떨어지는 연도는 윤년이다. */
	
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d년은 윤년입니다. \n", year);
	else
		printf("%d년은 평년입니다. \n", year);

	main_ex01_operator();
	main_ex06_operator();

	return 0;
}