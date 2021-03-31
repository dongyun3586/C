#include<stdio.h>

int main_ex14_gugudan() {
	int dan;

	printf("구구단 중 원하는 단을 입력하시오: ");
	scanf("%d", &dan);

	int i = 1;
	while (i<=9) {
		printf("%2d * %2d = %2d\n", dan, i, dan * i);
		i++;
	}


	return 0;
}