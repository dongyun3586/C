#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int n, sum = 1;

	printf("���� ���� �Է�: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++)
			sum *= j;
	}

	printf("%d", sum);

	return 0;
}