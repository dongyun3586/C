#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int n, sum = 1, q = 1;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			q *= j;
		sum *= 1;
		q = 1;
	}

	printf("%d", sum);

	return 0;
}