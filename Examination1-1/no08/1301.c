#include<stdio.h>

/* ���� ���� ��� ��� */
int main() {
	int n, i, ans = 0;

	printf("���� ���� �Է�: ");
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		ans = ans * i * i;
	}

	printf("%d", ans);

	return 0;
}