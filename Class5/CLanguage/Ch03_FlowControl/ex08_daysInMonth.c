#include<stdio.h>

int main_ex08_daysInMonth() {
	int month;

	printf("©Ы ют╥б: ");
	scanf("%d", &month);

	switch (month) {
	case 2:
		printf("28\n");
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		printf("30\n");
		break;
	default:
		printf("31\n");
		break;
	}

	return 0;
}