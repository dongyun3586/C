#include<stdio.h>

int main_ex08_daysInMonth() {
	int month;

	printf("몇 월? ");
	scanf("%d", &month);

	switch (month) {
		case 2:
			printf("28일\n");
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			printf("30일\n");
			break;
		default:
			printf("31일\n");
			break;
	}

	return 0;
}