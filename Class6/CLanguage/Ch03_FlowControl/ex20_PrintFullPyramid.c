#include<stdio.h>

int main_ex20_PrintFullPyramid() {
	int height;

	printf("�Ƕ�̵��� ���̴�? ");
	scanf("%d", &height);

	// Full Pyramid ���
	for (int i = 1; i <= height; i++) {
		// ���� ���
		for (int space = 1; space <= height - i; space++)
			printf(" ");

		// �� ���
		for (int j = 1; j <= 2 * i - 1; j++)
			printf("*");

		// �ٹٲ�
		printf("\n");
	}


	return 0;
}