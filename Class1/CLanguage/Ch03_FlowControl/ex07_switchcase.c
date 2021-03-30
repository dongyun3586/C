#include<stdio.h>

int main_ex07_switchcase() {
	int buttonNum;

	printf("음료수 버튼 번호(1~4번)를 선택하세요: ");
	scanf("%d", &buttonNum);

	switch (buttonNum) {			// switch문의 제어식은 반드시 정수값 상수이어야 한다.
	case 1:
		printf("콜라\n");
		break;						// break문을 만나면 switch ~ case문을 빠져나온다.
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