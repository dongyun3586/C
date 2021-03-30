// 달(1~12)을 입력하면 해당 달의 일수를 출력하는 프로그램을 작성하시오.
#include<stdio.h>

int main_ex08_daysInMonth() {
	int month;

	printf("몇 월?: ");
	scanf("%d", &month);

	switch (month) {			// switch문의 제어식은 반드시 정수값 상수이어야 한다.
	case 2:
		printf("28일\n");
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		printf("30일\n");
		break;
	default:						//  default문 : 조건과 일치하는 case가 없으면 수행
		printf("31일\n");
		break;
	}

	return 0;
}