#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int sum = 0, i, a, b = 1;

	printf("���� ���� �Է�: ");
	scanf("%d", &a);

	for (int i = 1; i <= a; i++) {
		b = 1;
		for (int j = 1; j <= i; j++)
			b *= i;
		sum += b;
	}

	printf("%d", sum);

	return 0;
}