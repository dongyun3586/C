#include<stdio.h>

int main_ex20_PrintFullPyramid() {
	int h;

	printf("높이: ");
	scanf("%d", &h);

	for (int i = 1; i <= h; i++) {
		// 공백 출력
		for (int s = 1; s <= h - i; s++)
			printf(" ");

		// * 출력
		for (int j = 1; j <= 2 * i - 1; j++)
			printf("*");

		printf("\n");
	}
	return 0;
}