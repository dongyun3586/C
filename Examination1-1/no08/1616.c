#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int n, a = 1, b = 1;

	printf("���� ���� �Է�: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			a *= i;
		b *= a;
	}

	printf("%d", b);

	return 0;
}