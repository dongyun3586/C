#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int a, b, n, j, i, sum;

	printf("���� ���� �Է�: ");
	scanf("%d", &n);
	sum = 1; a = 1; b = 1;

	while (a <= n) {
		for (i = 1; i <= a; i++) {
			b *= a;
		}
		sum *= b;
		b = 1;
		a++;
	}

	printf("\n%d", sum);

	return 0;
}