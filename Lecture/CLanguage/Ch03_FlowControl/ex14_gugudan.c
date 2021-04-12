#include<stdio.h>

int main() {
	int dan;

	printf("구구단 중 출력을 원하는 단을 입력하시오 : ");
	scanf("%d", &dan);

	int i = 1;
	while (i < 10) {
		printf("%d * %d = %2d\n", dan, i, dan * i);
		i++;
	}

	return 0;
}