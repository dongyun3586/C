#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int n, m, x = 1;

	printf("���� ���� �Է�: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			m *= i;
		x *= m;
	}

	printf("%d", x);

	return 0;
}