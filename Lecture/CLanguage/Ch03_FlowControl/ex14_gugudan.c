#include<stdio.h>

int main() {
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