#include<stdio.h>

int main_ex08_daysInMonth() {
	int month;

	printf("월을 입력하시오: ");
	scanf("%d", &month);

	switch (month) {			// switch문의 제어식은 반드시 정수값 상수이어야 한다.
	case 1:
	case 2:
		printf("사이다\n");
		break;						// break를 지우고 실행해본다.
	case 3:
		printf("환타\n");
		break;
	case 4:
		printf("포카리스웨트\n");
		break;
	default:						//  default문 : 조건과 일치하는 case가 없으면 수행
		printf("default\n");
		break;
	}

	return 0;
}