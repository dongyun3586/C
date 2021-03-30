#include<stdio.h>

int main_ex14_gugudan() {
	int dan, i=1;

	printf("몇 단? ");
	scanf("%d", &dan);

	// while문으로 구구단 출력하기
	while (i <= 9) {
		printf("%d * %d = %2d \n", dan, i, dan * i);
		i++;
	}

	return 0;
}