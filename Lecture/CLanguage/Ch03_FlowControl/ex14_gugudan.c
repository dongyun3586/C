#include<stdio.h>

int main_ex13_gugudan() {
	int dan;

	printf("������ �� ����� ���ϴ� ���� �Է��Ͻÿ� : ");
	scanf("%d", &dan);

	int i = 1;
	while (i < 10) {
		printf("%d * %d = %2d\n", dan, i, dan * i);
		i++;
	}

	return 0;
}