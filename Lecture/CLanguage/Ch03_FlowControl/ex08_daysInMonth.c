#include<stdio.h>

int main_ex08_daysInMonth() {
	int month, days;

	printf("���� �Է��Ͻÿ�: ");
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

	printf("%d���� �ϼ��� %d�Դϴ�.\n", month, days);

	return 0;
}