#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int i = 0, tot = 0, n;

	printf("���� ���� �Է�: ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		for (i; i > 0; i--) {
			tot *= i;
		}
	}
	printf("\n%d", tot);

	return 0;
}