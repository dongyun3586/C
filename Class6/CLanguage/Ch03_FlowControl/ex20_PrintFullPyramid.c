#include<stdio.h>

int main_ex20_PrintFullPyramid() {
	int height;

	printf("피라미드의 높이는? ");
	scanf("%d", &height);

	// Full Pyramid 출력
	for (int i = 1; i <= height; i++) {
		// 공백 출력
		for (int space = 1; space <= height - i; space++)
			printf(" ");

		// 별 출력
		for (int j = 1; j <= 2 * i - 1; j++)
			printf("*");

		// 줄바꿈
		printf("\n");
	}


	return 0;
}