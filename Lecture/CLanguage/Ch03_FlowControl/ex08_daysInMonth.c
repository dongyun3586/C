#include<stdio.h>

int main_ex08_daysInMonth() {
	int month, days;

	printf("월을 입력하시오: ");
	scanf("%d", &month);

	switch (month)
	{
	case 2:
		days = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days = 30;
		break;
	default:
		days = 31;	// 1, 3, 5, 7, 8, 10, 12
		break;
	}

	printf("%d월의 일수는 %d입니다.\n", month, days);

	return 0;
}